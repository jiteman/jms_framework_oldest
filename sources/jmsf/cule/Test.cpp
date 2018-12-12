#include "Test.h"
#include "TestRegistry.h"
////#include "jmsf/factory_TextObject.h"


namespace jmsf {
namespace cule {


//----------------------------------------------------------------------------------------------------------------------

// Pointer< std::vector< Pointer< Test > > > TestRegistrar::_registeredTests = Pointer< std::vector< Pointer< Test > > >::createUnique();
// 
// TestRegistrar::~TestRegistrar() {
// }
// 
// TestRegistrar::TestRegistrar( const Pointer< Test > &test ) {
// 	if ( _registeredTests.isEmpty() ) {
// 		_registeredTests = Pointer< std::vector< Pointer< Test > > >::createUnique( _new std::vector< Pointer< Test > > );
// 	}
// 
// 	_registeredTests->push_back( test );
// }
// 
// 
// const Pointer< std::vector< Pointer< Test > > > &TestRegistrar::getRegisteredTests() {
// 	return _registeredTests;
// }

//----------------------------------------------------------------------------------------------------------------------
// static
TestRegistry &Test::get_test_registry() throw() {
	return _testRegistry;
}

Test::~Test() {
}

Test::Test( const typing::internals::platform_character_type *const test_name, const validating::File_and_line &file_and_line )
	:
		_test_name( AS_string_literal( test_name ) ),
		_file_and_line( file_and_line )
// 		_filename( AS_string_literal( filename ) ),
// 		_line_number( typing::Memory_size::create( line_number ) )
{}

const typing::Ansii_string &Test::get_name() const {
	return _test_name;
}

const typing::Ansii_string &Test::get_filename() const {
	return _file_and_line.get_filename();
////	return _filename;
}

typing::Memory_size Test::get_line_number() const {
	return _file_and_line.get_line_number();
//	return _line_number;
}

// static
TestRegistry Test::_testRegistry;


} // namespace
}
