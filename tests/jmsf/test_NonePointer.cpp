#include "jmsf/cule/TestMacros.h"
#include "jmsf/cule/Test.h"
#include "jmsf/cule/Assert.h"

#include "jmsf/typing/Ansii_string.h"


namespace jmsf {


namespace {
	class test_nameTest : public ::jmsf::cule::Test {
		public:
			test_nameTest() : Test( "test_nameTest", FILE_AND_LINE ) {
				_testRegistry.registerTest( ::jmsf::pointing::Pointer< Test >::create_nonlinked_for( this ) );
			}
	
		protected:
			void run() const;

	} test_nameTestInstance;
}


void test_nameTest::run() const {
	notImplementedYet( AS_string_literal( "Nulling during creation" ) ); // creation without parameter
}


TEST( shouldBeNillAfterCreation ) {
	notImplementedYet( AS_string_literal( "Nulling during creation" ) ); // creation without parameter
}

TEST( shouldBeAsCreated ) {
	notImplementedYet( CONSTANT_TEXT_STRING( "Identity" ) ); // creation with parameter
}

TEST( shouldBeCopiedCorrectly ) {
	notImplementedYet( CONSTANT_TEXT_STRING( "Copying" ) ); // copying
	notImplementedYet( CONSTANT_TEXT_STRING( "Copy constructing" ) ); // copy construction
}

TEST( shouldOperateCorrectly ) {
	notImplementedYet( CONSTANT_TEXT_STRING( "Operating" ) ); // series of tests
}


} // namespace


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
