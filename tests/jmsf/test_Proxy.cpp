#include "jmsf/cule/TestMacros.h"
#include "jmsf/cule/Test.h"
#include "jmsf/cule/Assert.h"

#include "jmsf/factory_TextObject.h"

#include "jmsf/Proxy.hpp"


#include "testing/factory_Pointie_and_Proxie.h"
#include "testing/testing_Proxie.h"

#include "sensing/factory_Sensing.h"
#include "sensing/sensing_Pointie.h"


namespace jmsf {


TEST( shouldCorrectlyConstuctWeakReference ) {
	::jmsf::Pointer< sensing::sensing_Pointie > sensingPointie = sensing::factory_Sensing::instance()->createPointie();

	{
		::jmsf::Proxy< testing::testing_Proxie > testingProxie = testing::factory_Pointie_and_Proxie::instance()->createProxie( sensingPointie.getNonlinked() );
		pointerShouldNotBeNull( testingProxie.get() );

		naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
		naturalValuesShouldBeEqual( natural_size( 0 ), sensingPointie->getDestrutionCounter() );

		::jmsf::Proxy< testing::testing_Proxie > weakTestingPointie = testingProxie.getNonlinked();

		naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
		naturalValuesShouldBeEqual( natural_size( 0 ), sensingPointie->getDestrutionCounter() );
	}

	naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getDestrutionCounter() );
	naturalValuesShouldBeEqual( sensingPointie->getConstructionCounter(), sensingPointie->getDestrutionCounter() );
}

TEST(sShouldBeNillAfterCreation ) {
	notImplementedYet( CONSTANT_TEXT_STRING( "Nulling during creation" ) ); // creation without parameter
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
