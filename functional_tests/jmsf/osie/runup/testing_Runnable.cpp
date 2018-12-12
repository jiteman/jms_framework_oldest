#include "testing_Runnable.h"

#include "jmsf/Pointer.hpp"


namespace jmsf {
namespace osie {
namespace runup {


void testing_Runnable::run() throw( validating::Exception ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
testing_Runnable::~testing_Runnable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::Pointer< testing_Runnable > testing_Runnable::create() throw() {
	return ::jmsf::Pointer< testing_Runnable >::createUnique( new testing_Runnable );
}

testing_Runnable::testing_Runnable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Pointer< testing_Runnable > testing_Runnable::createClone() const throw() {
	return ::jmsf::Pointer< testing_Runnable >::createUnique( new testing_Runnable( *this ) );
}

testing_Runnable::testing_Runnable( const testing_Runnable & ) throw() // other
{}

const testing_Runnable &testing_Runnable::operator =( const testing_Runnable &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
