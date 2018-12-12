#include "FSHA_list_allocator.h"

#include "jmsf/structing/containing/List.inl"
#include "jmsf/structing/traversing/List_traverser.inl"
#include "Fixed_size_heap_allocator.h"
#include "Memory_block_descriptor.h"


namespace jmsf {
namespace memorying {
namespace allocating {


Memory_pointer FSHA_list_allocator::allocate_memory( const typing::Memory_size a_size, const typing::Memory_size an_alignment ) {
	if ( a_size.is_nill() ) {
		return Memory_pointer();
	}

	Memory_pointer result_memory_pointer;

	if ( _last_successfull_allocator.is_not_done() ) {
		// try to find enough amount of memory with last used allocator
		result_memory_pointer = _last_successfull_allocator.take_object().allocate_memory( a_size, an_alignment );		
	}

	if ( result_memory_pointer.is_empty() ) {
		// try to find enough amount of memory with other allocators

		for (
			structing::traversing::List_traverser< Fixed_size_heap_allocator > list_traverser = _fsha_list.create_traverser_at_begin();
			list_traverser.is_not_done();
			list_traverser.move_one_step_to_end() )
		{
			// skip last successfull allocator
			if ( &_last_successfull_allocator.get_object() == &list_traverser.get_object() ) continue;

			result_memory_pointer = list_traverser.take_object().allocate_memory( a_size, an_alignment );

			if ( result_memory_pointer.is_not_empty() ) {
				_last_successfull_allocator = list_traverser;
				break;
			}
		}
	}

	return result_memory_pointer;
}

void FSHA_list_allocator::deallocate_memory( const Memory_pointer &a_memory, const typing::Memory_size an_alignment ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
FSHA_list_allocator::~FSHA_list_allocator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FSHA_list_allocator::FSHA_list_allocator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FSHA_list_allocator::FSHA_list_allocator( const FSHA_list_allocator & ) noexept { // another
}

const FSHA_list_allocator &FSHA_list_allocator::operator =( const FSHA_list_allocator &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
