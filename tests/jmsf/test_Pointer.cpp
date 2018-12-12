#include "jmsf/cule/TestMacros.h"
#include "jmsf/cule/Test.h"
#include "jmsf/cule/Assert.h"

////#include "jmsf/factory_TextObject.h"

#include "testing/factory_Pointie_and_Proxie.h"
#include "testing/testing_Pointie.h"

#include "sensing/factory_Sensing.h"
#include "sensing/sensing_Pointie.h"

#include "jmsf/pointing/Pointer.inl"


namespace jmsf {


TEST( shouldCorrectlyDeleteReference ) {
	::jmsf::pointing::Pointer< sensing::sensing_Pointie > sensingPointie = sensing::factory_Sensing::instance()->createPointie();

	{
		::jmsf::pointing::Pointer< testing::testing_Pointie > testingPointie = testing::factory_Pointie_and_Proxie::instance()->createPointie( sensingPointie.getNonlinked() );
		pointerShouldNotBeNull( testingPointie.get() );

		naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
		naturalValuesShouldBeEqual( natural_size( 0 ), sensingPointie->getDestrutionCounter() );
	}

	naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
	naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getDestrutionCounter() );
	naturalValuesShouldBeEqual( sensingPointie->getConstructionCounter(), sensingPointie->getDestrutionCounter() );
}

TEST( shouldCorrectlyConstuctWeakReference ) {
	::jmsf::Pointer< sensing::sensing_Pointie > sensingPointie = sensing::factory_Sensing::instance()->createPointie();

	{
		::jmsf::Pointer< testing::testing_Pointie > testingPointie = testing::factory_Pointie_and_Proxie::instance()->createPointie( sensingPointie.getNonlinked() );
		pointerShouldNotBeNull( testingPointie.get() );

		naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
		naturalValuesShouldBeEqual( natural_size( 0 ), sensingPointie->getDestrutionCounter() );

		::jmsf::Pointer< testing::testing_Pointie > weakTestingPointie = testingPointie.getNonlinked();

		naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getConstructionCounter() );
		naturalValuesShouldBeEqual( natural_size( 0 ), sensingPointie->getDestrutionCounter() );
	}

	naturalValuesShouldBeEqual( natural_size( 1 ), sensingPointie->getDestrutionCounter() );
	naturalValuesShouldBeEqual( sensingPointie->getConstructionCounter(), sensingPointie->getDestrutionCounter() );
}

TEST( shouldBeNillAfterCreation ) {
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
