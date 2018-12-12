#pragma once 


#include "TestRegistry.h"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/validating/File_and_line.h"


//======================================================================================================================

#define TEST( test_name )\
	namespace {\
		class test_name ## Test : public ::jmsf::cule::Test {\
			public:\
				test_name ## Test()\
					: Test( #test_name"Test", FILE_AND_LINE )\
				{\
					_testRegistry.registerTest( Pointer< Test >::createNonlinkedFor( this ) );\
				}\
\
			protected:\
				void run() const;\
\
		} test_name ## TestInstance;\
\
	}\
\
	void test_name ## Test::run() const


#define TEST_EXCEPTION( test_name, exception_name )\
	namespace {\
		class test_name ## Test : public ::jmsf::cule::Test {\
			public:\
				test_name ## Test()\
					: Test( #test_name"Test", FILE_AND_LINE )\
				{\
					_testRegistry.registerTest( Pointer< Test >::createNonlinkedFor( this ) );\
				}\
\
			protected:\
				void run() const;\
\
				void testToRun() const ;\
\
		} test_name ## TestInstance;\
\
	}\
\
	void test_name ## Test::run() const {\
		try {\
			testToRun();\
			free::ThrowCuleException( _t( "expected exception: " ) + std::_tstring( _t( #exception_name ) ) + _t( "but there was no exception" ), get_line_number() );\
		} catch ( const exception_name &theException ) {\
		} catch ( ... ) {\
			free::ThrowCuleException( _t( "expected exception: " ) +std::_tstring( _t( #exception_name ) ) + _t( "but there was UNKNOWN exception" ), get_line_number() );\
		}\
	}\
\
	void test_name ## Test::testToRun() const
