#include "Fixed_size_heap_allocator.h"

#include "Top_pool_allocator.inl"

#include "Memory_block_descriptor.h"

#include "comparing/Mbd_size_fit_comparator.h"
#include "comparing/Mbd_size_comparator.h"
#include "comparing/Mbd_returned_address_comparator.h"
#include "comparing/Mbd_address_comparator.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Aso.inl"

#include "jmsf/structing/traversing/List_traverser.inl"
#include "jmsf/structing/containing/List.inl"

#include "jmsf/assisting/Find.inl"

#include "../Constructor.inl"
#include "../Destructor.inl"


namespace jmsf {
namespace memorying {
namespace allocating {


// virtuals Allocator
Memory_pointer Fixed_size_heap_allocator::allocate_memory( const typing::Memory_size a_size, const typing::Memory_size an_alignment ) {
	Memory_pointer allocated_memory;

	if ( ( allocated_memory = tryToAllocateMemory( a_size, an_alignment ) ).is_empty() ) {	
		// log
		// throw Exception no free memory in allocator
	}

	return allocated_memory;
}

void Fixed_size_heap_allocator::deallocate_memory( const Memory_pointer &a_memory, const typing::Memory_size an_alignment ) {
	
}
//~virtuals Allocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Fixed_size_heap_allocator::~Fixed_size_heap_allocator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Fixed_size_heap_allocator::Fixed_size_heap_allocator( const Memory_pointer &memory_heap, const typing::Memory_size heap_size )
	:
		_heap_status_descriptor( memory_heap.get_address(), heap_size )
{
	// Next to do: check for heap size
// 	if ( heap_size < some value depending on memory block descriptor size ) {
// 		// heap is too small (provide minimum size number)
// 		return;
// 	}

	_list_nodes_allocator =
		Top_pool_allocator< structing::noding::Doubly_linked_node< Memory_block_descriptor > >(
			Womp< Heap_status_descriptor >::create_from_pointer( &_heap_status_descriptor ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Fixed_size_heap_allocator::Fixed_size_heap_allocator( const Fixed_size_heap_allocator & ) noexept { // another
}

const Fixed_size_heap_allocator &Fixed_size_heap_allocator::operator =( const Fixed_size_heap_allocator &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer Fixed_size_heap_allocator::tryToAllocateMemory( const typing::Memory_size size_to_allocate, const typing::Memory_size an_alignment ) noexept {
	Memory_pointer allocated_memory;

	// find first fit in empty blocks
	structing::traversing::List_traverser< Memory_block_descriptor > first_fit_memory_block =
		assisting::find_first_not(
			Memory_block_descriptor( typing::Memory_size_nill, an_alignment, size_to_allocate ),
			_empty_memory_list_sorted_by_size.create_traverser_at_begin(),
			comparing::Mbd_size_fit_comparator(),
			typing::Comparasion_result::create_greater() ); 

	if ( first_fit_memory_block.is_not_done() ) { // if found
		// split (or do not split) this block and move this block to used list and other block insert in empty list
		Memory_block_descriptor memory_block_to_allocate = first_fit_memory_block.withdraw_object();

		structing::traversing::List_traverser< Memory_block_descriptor > found =
			assisting::find_first(
				memory_block_to_allocate,
				_empty_memory_list_sorted_by_address.create_traverser_at_begin(),
				comparing::Mbd_address_comparator() );

		found.erase_object();
		const typing::Memory_size alignment_up_value = typing::get_alignment_up_value( memory_block_to_allocate.get_memory_block_address(), an_alignment );
		const typing::Memory_size total_size_to_allocate = size_to_allocate + alignment_up_value;

		Memory_block_descriptor new_empty_memory_block(
			memory_block_to_allocate.get_memory_block_address() + total_size_to_allocate,
			typing::Memory_size_nill,
			memory_block_to_allocate.get_size() - total_size_to_allocate );

		Memory_block_descriptor new_used_memory_block(
			memory_block_to_allocate.get_memory_block_address(),
			memory_block_to_allocate.get_memory_block_address() + alignment_up_value,
			total_size_to_allocate );

		_used_memory_list.append_sorted(
			Womp< Allocator >::create_from_pointer( &_list_nodes_allocator ),
			comparing::Mbd_returned_address_comparator(),
			new_used_memory_block );

		consolidate_and_add( new_empty_memory_block );
	} else {
		Memory_block_descriptor new_used_memory_block;

		const typing::Memory_size alignment_up_value = typing::get_alignment_up_value( _heap_status_descriptor.get_middle_block_start(), an_alignment );
		const typing::Memory_size total_size_to_allocate = size_to_allocate + alignment_up_value;

		if ( _heap_status_descriptor.get_middle_block_size() >= total_size_to_allocate ) {
			new_used_memory_block.set_memory_block_address( _heap_status_descriptor.get_middle_block_start() );
			new_used_memory_block.set_size( total_size_to_allocate );
			new_used_memory_block.set_returned_address( _heap_status_descriptor.get_middle_block_start() + alignment_up_value );

			_heap_status_descriptor.set_middle_block_start( _heap_status_descriptor.get_middle_block_start() + total_size_to_allocate );

			_used_memory_list.append_sorted(
				Womp< Allocator >::create_from_pointer( &_list_nodes_allocator ),
				comparing::Mbd_returned_address_comparator(),
				new_used_memory_block );
		}
	}

	return allocated_memory;
}

void Fixed_size_heap_allocator::consolidate_and_add( const Memory_block_descriptor &new_empty_memory_block ) noexept {
	structing::traversing::List_traverser< Memory_block_descriptor > block_above =
		assisting::find_first(
			new_empty_memory_block,
			_empty_memory_list_sorted_by_address.create_traverser_at_begin(),
			comparing::Mbd_address_comparator(),
			typing::Comparasion_result::create_lower() );

	structing::traversing::List_traverser< Memory_block_descriptor > block_below =
		block_above.is_done() ?
				structing::traversing::List_traverser< Memory_block_descriptor >()
			:
				block_above.create_previous();


	typing::Boolean isNeededConsolidationWithBlockBelow;

	if ( block_below.is_not_done() ) {
		if ( block_below.get_object().get_memory_block_address() + block_below.get_object().get_size() == new_empty_memory_block.get_memory_block_address() ) {
			isNeededConsolidationWithBlockBelow = typing::True;
		}
	}

	typing::Boolean isNeededConsolidationWithBlockAbove;

	if ( block_above.is_not_done() ) {
		if ( new_empty_memory_block.get_memory_block_address() + new_empty_memory_block.get_size() == block_above.get_object().get_memory_block_address() ) {
			isNeededConsolidationWithBlockAbove = typing::True;
		}
	}

	Memory_block_descriptor consolidating_memory_block = new_empty_memory_block;

	if ( isNeededConsolidationWithBlockBelow ) {
		consolidating_memory_block.set_memory_block_address( block_below.get_object().get_memory_block_address() );
		consolidating_memory_block.set_size( block_below.get_object().get_size() + consolidating_memory_block.get_size() );
	}

	if ( isNeededConsolidationWithBlockAbove ) {
		consolidating_memory_block.set_size( consolidating_memory_block.get_size() + block_above.get_object().get_size() );
	}

	if ( isNeededConsolidationWithBlockBelow || isNeededConsolidationWithBlockAbove ) {
		if ( isNeededConsolidationWithBlockBelow ) {
			structing::traversing::List_traverser< Memory_block_descriptor > found =
				assisting::find_first(
					block_below.get_object(),
					_empty_memory_list_sorted_by_size.create_traverser_at_begin(),
					comparing::Mbd_size_comparator() );

			found = assisting::find_first( block_below.get_object(), found, comparing::Mbd_address_comparator() );

			if ( found.is_done() ) {
				// should never reach here;
			}

			found.erase_object();
			block_below.erase_object();
		}
		
		if ( isNeededConsolidationWithBlockAbove ) {
			structing::traversing::List_traverser< Memory_block_descriptor > found =
				assisting::find_first(
					block_above.get_object(),
					_empty_memory_list_sorted_by_size.create_traverser_at_begin(),
					comparing::Mbd_size_comparator() );

			found = assisting::find_first( block_below.get_object(), found, comparing::Mbd_address_comparator() );

			if ( found.is_done() ) {
				// should never reach here
			}

			found.erase_object();
			block_above.erase_object();
		}
	}

	_empty_memory_list_sorted_by_size.append_sorted(
		Womp< Allocator >::create_from_pointer( &_list_nodes_allocator ),
		comparing::Mbd_size_comparator(),
		consolidating_memory_block );

	_empty_memory_list_sorted_by_address.append_sorted(
		Womp< Allocator >::create_from_pointer( &_list_nodes_allocator ),
		comparing::Mbd_address_comparator(),
		consolidating_memory_block );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typing::Boolean Fixed_size_heap_allocator::isFit(
	const typing::Memory_size address_of_the_block,
	const typing::Memory_size size_of_the_block,
	const typing::Memory_size size_to_allocate,
	const typing::Memory_size an_alignment ) noexept
{
	const typing::Memory_size new_start_address = typing::align_up( address_of_the_block, an_alignment );
	const typing::Memory_size total_size_to_allocate = size_to_allocate + ( new_start_address - address_of_the_block );

	return size_of_the_block >= total_size_to_allocate;
}


} // namespace allocating
} // namespace memorying
} // namespace jmsf
