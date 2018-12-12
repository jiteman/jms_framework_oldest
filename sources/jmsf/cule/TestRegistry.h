#pragma once


////#include "jmsf/Pointers.hpp"

#include "cule.h"

#include "jmsf/pointing/Pointer.hxx"

#include "Test.hxx"
////#include "jmsf/Exception.hxx"


#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
namespace cule {


class JMSF_CULE_DLL_INTERFACE TestRegistry {

public:
	void registerTest( const pointing::Pointer< Test > &test ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const std::vector< pointing::Pointer< Test > > &getRegisteredTests() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~TestRegistry() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	TestRegistry() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	TestRegistry( const TestRegistry &other ) throw();
	const TestRegistry &operator =( const TestRegistry &other ); // exceptions: Exception

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::vector< pointing::Pointer< Test > > _registeredTests;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace cule
} // namespace jmsf
