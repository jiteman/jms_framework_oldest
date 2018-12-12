#include "realizing_System_allocator.h"


#include "jmsf/memorying/Omp.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/al_std/stl_hin/cstdlib_al_std.hin"

#include <iostream>


namespace jmsf {
namespace memorying {
namespace realizing {


Memory_pointer realizing_System_allocator::allocate_memory( typeing::Memory_natural a_size, const typeing::Memory_natural /*an_alignment*/ ) {
	return
		a_size.is_nill() ?
				Memory_pointer()
			:
				Memory_pointer::create_from_address( typeing::create_address_from_pointer( ::std::malloc( a_size.get_native_value() ) ) );
}

void realizing_System_allocator::deallocate_memory( const Memory_pointer &a_memory, const typeing::Memory_natural /*an_alignment*/ ) {
	if ( a_memory.is_empty() ) return;

	Memory_pointer &non_const_memory_pointer = const_cast< Memory_pointer & >( a_memory );
	::std::free( non_const_memory_pointer.take() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 realizing_System_allocator::~realizing_System_allocator() noexcept {
	::std::cout << ::std::endl;
	::std::cout << "realizing_System_allocator::~realizing_System_allocator()" << ::std::endl;
	::std::cout << ::std::endl;
 }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 realizing_System_allocator::realizing_System_allocator() noexcept {
	::std::cout << ::std::endl;
	::std::cout << "realizing_System_allocator::realizing_System_allocator()" << ::std::endl;
	::std::cout << ::std::endl;
}

// static
Omp< Allocator > realizing_System_allocator::create() noexcept {
	return
		Omp< Allocator >::create(
			Memory_pointer::create_from_pointer< Allocator >( new realizing_System_allocator() ),
			Womp< Allocator >(),
			typeing::Memory_natural_badmax );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 realizing_System_allocator::realizing_System_allocator( const  realizing_System_allocator &/*another*/ ) noexcept {
}

const  realizing_System_allocator & realizing_System_allocator::operator =( const  realizing_System_allocator &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace memorying
} // namespace jmsf
