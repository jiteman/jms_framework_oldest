#pragma once


#include "Pool_block_descriptor.hpp"

#include "jmsf/typing/Boolean.h"
#include "jmsf/typing/Aso.inl"
#include "jmsf/typing/Bitwise.inl"


namespace jmsf {
namespace memorying {
namespace allocating {


// static
template< class A_type >
const typing::Memory_size Pool_block_descriptor< A_type >::_block_size = typing::Memory_size::create( _object_memory_block_quantity_constant );

// template< class A_type >
// typing::Memory_size Pool_block_descriptor< A_type >::get_usage_indicator() const noexept {
// 	return _usage_indicator;
// }

template< class A_type >
typing::Memory_size Pool_block_descriptor< A_type >::get_first_free_index() const noexept {
	typing::Bitwise< typing::Memory_size > bitwise_usage_indicator = get_bitwise_usage_indicator();
	return bitwise_usage_indicator.get_first_reset_bit_index();	
}

template< class A_type >
typing::Boolean Pool_block_descriptor< A_type >::is_not_used() const noexept {
	return _usage_indicator.is_nill();
}

template< class A_type >
typing::Boolean Pool_block_descriptor< A_type >::is_not_full() const noexept {
	return _usage_indicator.is_not_max();
}

template< class A_type >
typing::Boolean Pool_block_descriptor< A_type >::is_used( const typing::Memory_size object_memory_block_index ) const {
	if ( object_memory_block_index >= _block_size ) {
		// wrong index
		return;
	}

	typing::Bitwise< typing::Memory_size > bitwise_usage_indicator = get_bitwise_usage_indicator();
	return bitwise_usage_indicator.is_set( object_memory_block_index );
}

template< class A_type >
typing::Boolean Pool_block_descriptor< A_type >::is_free( const typing::Memory_size object_memory_block_index ) const {
	if ( object_memory_block_index >= _block_size ) {
		// wrong index
		return typing::False;
	}

	typing::Bitwise< typing::Memory_size > bitwise_usage_indicator = get_bitwise_usage_indicator();
	return bitwise_usage_indicator.is_reset( object_memory_block_index );	
}

template< class A_type >
const A_type *Pool_block_descriptor< A_type >::get_object_memory_block_by( const typing::Shortest_natural object_memory_block_index ) const noexept {
	if ( typing::Memory_size::create( object_memory_block_index.get_value() ) >= get_max_quantity_of_desctriptors() ) {
		// wrong index
		return nullptr;
	}

	return &_object_memory_blocks[ object_memory_block_index.get_value() ];
}

template< class A_type >
typing::Memory_size Pool_block_descriptor< A_type >::get_object_memory_block_index( const A_type *const object_memory_block ) const noexept {
	const typing::Memory_size address_to_find = typing::create_address_from_pointer( object_memory_block );

	if ( typing::is_not_aligned< A_type >( address_to_find ) ) {
		// address requested is not aligned
		return typing::Memory_size_badmax;
	}

	const typing::Memory_size first_object_memory_block_address = typing::create_address_from_pointer( _object_memory_blocks );
	const typing::Memory_size last_object_memory_block_address = typing::create_address_from_pointer( &_object_memory_blocks[ _object_memory_block_quantity_constant - 1 ] );

	if ( address_to_find < first_object_memory_block_address || address_to_find > last_object_memory_block_address ) {
		// address is not from this pool block
		return typing::Memory_size_badmax;
	}

	const typing::Memory_size relative_address = address_to_find - first_object_memory_block_address;
	return relative_address / typing::size_of< A_type >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type >
// void Pool_block_descriptor< A_type >::set_usage_indicator( const typing::Memory_size using_indicator ) noexept {
// 	_usage_indicator = using_indicator;
// }

template< class A_type >
void Pool_block_descriptor< A_type >::set_as_used( const typing::Memory_size object_memory_block_index ) {
	if ( object_memory_block_index >= _block_size ) {
		// wrong index
		return;
	}

	typing::Bitwise< typing::Memory_size > bitwise_usage_indicator = get_bitwise_usage_indicator();
	bitwise_usage_indicator.set( object_memory_block_index );
}

template< class A_type >
void Pool_block_descriptor< A_type >::set_as_free( const typing::Memory_size object_memory_block_index ) {
	if ( object_memory_block_index >= _block_size ) {
		// wrong index
		return;
	}

	typing::Bitwise< typing::Memory_size > bitwise_usage_indicator = get_bitwise_usage_indicator();
	bitwise_usage_indicator.reset( object_memory_block_index );
}

template< class A_type >
A_type *Pool_block_descriptor< A_type >::take_object_memory_block_by( const typing::Memory_size object_memory_block_index ) noexept {
	if ( object_memory_block_index >= get_max_quantity_of_desctriptors() ) {
		// wrong index
		return nullptr;
	}

	return &_object_memory_blocks[ object_memory_block_index.get_value() ];
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
typing::Memory_size Pool_block_descriptor< A_type >::get_max_quantity_of_desctriptors() noexept {
	return _block_size;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Pool_block_descriptor< A_type >::~Pool_block_descriptor() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Pool_block_descriptor< A_type >::Pool_block_descriptor() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Pool_block_descriptor< A_type >::Pool_block_descriptor( const Pool_block_descriptor< A_type > & ) noexept { // another
}

template< class A_type >
const Pool_block_descriptor< A_type > &Pool_block_descriptor< A_type >::operator =( const Pool_block_descriptor< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class A_type >
typing::Bitwise< typing::Memory_size > Pool_block_descriptor< A_type >::get_bitwise_usage_indicator() const noexept {
	return typing::Bitwise< typing::Memory_size >::create( _usage_indicator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
