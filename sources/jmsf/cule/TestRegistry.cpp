#include "TestRegistry.h"
#include "Test.h"


#include "jmsf/pointing/Pointer.inl"

#include "jmsf/validating/Should.h"


namespace jmsf {
namespace cule {


void TestRegistry::registerTest( const pointing::Pointer< Test > &test ) throw() {
	_registeredTests.push_back( test );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const std::vector< pointing::Pointer< Test > > &TestRegistry::getRegisteredTests() const throw() {
	return _registeredTests;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
TestRegistry::~TestRegistry() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TestRegistry::TestRegistry() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TestRegistry::TestRegistry( const TestRegistry & ) throw() // other
{}

const TestRegistry &TestRegistry::operator =( const TestRegistry &other ) { // throw( Exception )
	if ( this == &other ) return *this;

	// copy
	validating::Should::never_violate_copy_prohibition( "TestRegistry::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace cule
} // namespace jmsf
