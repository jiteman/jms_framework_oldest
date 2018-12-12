#pragma once


#include "Top_pool_allocator.hpp"

#include "Heap_status_descriptor.h"
//#include "Memory_block_descriptor.h"
#include "Pool_block_descriptor.inl"

#include "jmsf/memorying/Memory_pointer.h"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Aso.inl"
#include "jmsf/typing/Bitwise.inl"


namespace jmsf {
namespace memorying {
namespace allocating {


template< class A_type >
Memory_pointer Top_pool_allocator< A_type >::allocate_memory( const typing::Memory_size a_size, const typing::Memory_size an_alignment ) {
	if ( a_size != typing::size_of< A_type >() || an_alignment != typing::alignment_of< A_type >() ) {
		// requested memory has not appropriate size and/or alignment (wrong type)
		return Memory_pointer();
	}

	return get_empty_memory_block();
}

template< class A_type >
void Top_pool_allocator< A_type >::deallocate_memory( const Memory_pointer &a_memory, const typing::Memory_size an_alignment ) {
	if ( a_memory.is_empty() ) return;

	if ( an_alignment != typing::alignment_of< Memory_block_descriptor >() ) {
		// wtf? is this template actual for Memory block descriptor only?
		return;
	}

	const typing::Memory_size pool_block_address = typing::align_down( a_memory.get_address(), typing::size_of< Pool_block_descriptor< A_type > >() );

	if ( get_pool_block_address( _quantity_of_pool_blocks_allocated - typing::Memory_size_one ) > pool_block_address ) {
		// throw wrong address to deallocate (out of range) (from another block - ?)
		return;
	}

	Womp< Pool_block_descriptor< A_type > > pool_block_descriptor = Womp< Pool_block_descriptor< A_type > >::create_from_address( pool_block_address );

	const typing::Memory_size memory_block_descriptor_index =
		pool_block_descriptor->get_object_memory_block_index(
			typing::get_pointer_from_memory_size< A_type >( a_memory.get_address() ) );

	if ( pool_block_descriptor->is_free( memory_block_descriptor_index ) ) {
		// throw repeating deallocation (already freed)
		return;
	}

	pool_block_descriptor->set_as_free( memory_block_descriptor_index );

	if ( pool_block_descriptor->is_not_used() ) {
		release_unused_pool_block_descriptors( pool_block_descriptor, pool_block_address );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Top_pool_allocator< A_type >::~Top_pool_allocator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Top_pool_allocator< A_type >::Top_pool_allocator() noexept
{}

template< class A_type >
Top_pool_allocator< A_type >::Top_pool_allocator( const memorying::Womp< Heap_status_descriptor > &heap_status_descriptor ) noexept
	:
		_heap_status_descriptor( heap_status_descriptor )
{
	_aligned_heap_end_address = typing::align_down( ++_heap_status_descriptor->get_memory_heap_end(), typing::alignment_of< Pool_block_descriptor< A_type > >() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Top_pool_allocator< A_type >::Top_pool_allocator( const Top_pool_allocator< A_type > &another ) noexept
	:
		_heap_status_descriptor( another._heap_status_descriptor ),
		_aligned_heap_end_address( another._aligned_heap_end_address ),
		_quantity_of_pool_blocks_allocated( another._quantity_of_pool_blocks_allocated )
{}

template< class A_type >
const Top_pool_allocator< A_type > &Top_pool_allocator< A_type >::operator =( const Top_pool_allocator< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_heap_status_descriptor = another._heap_status_descriptor;
	_aligned_heap_end_address = another._aligned_heap_end_address;
	_quantity_of_pool_blocks_allocated = another._quantity_of_pool_blocks_allocated;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class A_type >
typing::Memory_size Top_pool_allocator< A_type >::get_first_pool_block_address() noexept {
	return _aligned_heap_end_address - typing::size_of< Pool_block_descriptor< A_type > >();
}

template< class A_type >
typing::Memory_size Top_pool_allocator< A_type >::get_pool_block_address( const typing::Memory_size pool_block_index ) noexept {
	return get_first_pool_block_address() - typing::size_of< Pool_block_descriptor< A_type > >() * ( pool_block_index + typing::Memory_size_one );
}

template< class A_type >
Memory_pointer Top_pool_allocator< A_type >::get_empty_memory_block() noexept {
	Womp< Pool_block_descriptor< A_type >  > pool_block_descriptor = take_pool_block_with_empty_memory_block();

	if ( pool_block_descriptor.is_empty() ) return Memory_pointer();

	return Memory_pointer::create_from_pointer( get_empty_object_memory_block( pool_block_descriptor ) );
}

template< class A_type >
Womp< Pool_block_descriptor< A_type > > Top_pool_allocator< A_type >::take_pool_block_with_empty_memory_block() noexept {
	Womp< Pool_block_descriptor< A_type > > pool_block_descriptor = Womp< Pool_block_descriptor< A_type > >::create_from_address( get_first_pool_block_address() );

	for ( typing::Memory_size counter = _quantity_of_pool_blocks_allocated; counter.is_not_nill(); --counter ) {
		if ( pool_block_descriptor->is_not_full() ) {
			return pool_block_descriptor;
		}

		pool_block_descriptor =
			Womp< Pool_block_descriptor< A_type > >::create_from_address(
				pool_block_descriptor.get_address() - typing::size_of< Pool_block_descriptor< A_type > >() );
	}

	return create_new_pool_block();
}

template< class A_type >
Womp< Pool_block_descriptor< A_type > > Top_pool_allocator< A_type >::create_new_pool_block() noexept {
	Womp< Pool_block_descriptor< A_type > > result_pool_block;

	if ( _heap_status_descriptor->get_middle_block_size() < typing::size_of< Pool_block_descriptor< A_type > >() * typing::Memory_size::create( 2 ) ) {
		// if empty middle area is smaller than two sizes of pool block descriptor ('cause we need to allocate not only pool block, but an object too)
		return result_pool_block;
	}

	_heap_status_descriptor->set_middle_block_end(
		_quantity_of_pool_blocks_allocated.is_nill() ?
				_aligned_heap_end_address - typing::size_of< Pool_block_descriptor< A_type > >() // take first
			:
				_heap_status_descriptor->get_middle_block_end() - typing::size_of< Pool_block_descriptor< A_type > >() ); // take next

	result_pool_block = Womp< Pool_block_descriptor< A_type > >::create_from_address( get_pool_block_address( _quantity_of_pool_blocks_allocated ) );
	++_quantity_of_pool_blocks_allocated;	
	return result_pool_block;
}

template< class A_type >
void Top_pool_allocator< A_type >::release_unused_pool_block_descriptors( const Womp< Pool_block_descriptor< A_type > > &pool_block_descriptor, const typing::Memory_size pool_block_address ) noexept {
	const typing::Memory_size last_pool_block_address = get_pool_block_address( _quantity_of_pool_blocks_allocated - typing::Memory_size_one );
	
	Womp< Pool_block_descriptor< A_type > > descriptor_reverse_iterator =
		last_pool_block_address == pool_block_descriptor.get_address()  ?
			pool_block_descriptor :
			Womp< Pool_block_descriptor< A_type > >::create_from_address( last_pool_block_address );

	const typing::Memory_size previous_quantity = _quantity_of_pool_blocks_allocated;

	while ( _quantity_of_pool_blocks_allocated.is_not_nill() && descriptor_reverse_iterator->is_not_used() ) {
		--_quantity_of_pool_blocks_allocated;

		descriptor_reverse_iterator =
			Womp< Pool_block_descriptor< A_type > >::create_from_address(
				descriptor_reverse_iterator.get_address() - typing::size_of< Pool_block_descriptor< A_type > >() );
	}

	if ( previous_quantity != _quantity_of_pool_blocks_allocated ) {
		_heap_status_descriptor->set_middle_block_end( _aligned_heap_end_address - typing::size_of< Pool_block_descriptor< A_type > >() * _quantity_of_pool_blocks_allocated );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
A_type *Top_pool_allocator< A_type >::get_empty_object_memory_block( Womp< Pool_block_descriptor< A_type > > &pool_block_descriptor ) noexept {
	const typing::Memory_size first_empty_memory_block_index = pool_block_descriptor->get_first_free_index();
	pool_block_descriptor->set_as_used( first_empty_memory_block_index );
	return pool_block_descriptor->take_object_memory_block_by( first_empty_memory_block_index );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
