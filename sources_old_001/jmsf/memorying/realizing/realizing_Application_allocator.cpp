#include "realizing_Application_allocator.h"


#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Constructor.hin"


namespace jmsf {
namespace memorying {
namespace realizing {


Memory_pointer realizing_Application_allocator::allocate_memory( const typeing::Memory_natural a_size, const typeing::Memory_natural an_alignment ) {
	return _system_allocator->allocate_memory( a_size, an_alignment );
}

void realizing_Application_allocator::deallocate_memory( const Memory_pointer &a_memory, const typeing::Memory_natural an_alignment ) {
	_system_allocator->deallocate_memory( a_memory, an_alignment );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_Application_allocator::~realizing_Application_allocator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_Application_allocator::realizing_Application_allocator( const Womp< Allocator > &system_allocator ) noexcept
	:
		_system_allocator( system_allocator )
{}

// static
Omp< Allocator > realizing_Application_allocator::create( const Womp< Allocator > &system_allocator ) noexcept {
	return Constructor< Allocator, realizing_Application_allocator >::construct( system_allocator, system_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_Application_allocator::realizing_Application_allocator( const realizing_Application_allocator &/*another*/ ) noexcept {
}

const realizing_Application_allocator &realizing_Application_allocator::operator =( const realizing_Application_allocator &another ) noexcept {
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
