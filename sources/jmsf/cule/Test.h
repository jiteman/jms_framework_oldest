#pragma once


#include "TestRegistry.hxx"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/validating/File_and_line.h"

#include "jmsf/jmsf_language_support.h"

#include "cule.h"


namespace jmsf {
namespace cule {


//----------------------------------------------------------------------------------------------------------------------

// class JMSF_CULE_DLL_INTERFACE TestRegistrar {
// 
// public:
// 	static const Pointer< std::vector< Pointer< Test > > > &getRegisteredTests();
// 
// private:
// 	static Pointer< std::vector< Pointer< Test > > > _registeredTests;
// 	
// public:
// 	virtual ~TestRegistrar();
// 	TestRegistrar( const Pointer< Test > &test );
// 
// private:
// 	TestRegistrar( const TestRegistrar & ) {}
// 	const TestRegistrar &operator=( const TestRegistrar & ) { return *this; }
// 
// };


//----------------------------------------------------------------------------------------------------------------------

class JMSF_CULE_DLL_INTERFACE Test {

public:
	static TestRegistry &get_test_registry() noexept;

public:
	virtual void run() const = 0;

public:
	const typing::Ansii_string &get_name() const noexept;
	const typing::Ansii_string &get_filename() const noexept;
	typing::Memory_size get_line_number() const noexept;

public:
	virtual ~Test() noexept;
	Test( const typing::internals::platform_character_type *test_name, const validating::File_and_line &file_and_line ) noexept;

protected:
	const Test &operator =( const Test & ) { return *this; }

private:
	const typing::Ansii_string _test_name;
	const validating::File_and_line _file_and_line;
//	const typing::Ansii_string _filename;
// 	const std::_tstring _testName;
// 	const std::_tstring _fileName;
//	const typing::Memory_size _line_number;

protected:
	static TestRegistry _testRegistry;

};


} // namespace
}



