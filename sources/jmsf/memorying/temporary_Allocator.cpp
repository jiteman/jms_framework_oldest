#include "temporary_Allocator.h"

#include "Memory_pointer.h"

#include "jmsf/typing/Naturals.inl"

#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
namespace memorying {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer temporary_Allocator::allocate_memory( const typing::Memory_size a_size, const typing::Memory_size  ) { // alignment
	return
		a_size.is_nill() ?
				Memory_pointer()
			:
				Memory_pointer::create_from_address( typing::create_address_from_pointer( ::malloc( a_size.get_value() ) ) );
}

void temporary_Allocator::deallocate_memory( const Memory_pointer &a_memory, const typing::Memory_size  ) { // alignment
	if ( a_memory.is_empty() ) return;

	Memory_pointer &non_const_memory_pointer = const_cast< Memory_pointer & >( a_memory );
	::free( non_const_memory_pointer.take() );
}



// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
temporary_Allocator::~temporary_Allocator()
{}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace memorying
} // namespace jmsf
