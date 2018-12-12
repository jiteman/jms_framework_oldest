#include "jmsf/cule/TestMacros.h"
#include "jmsf/cule/Test.h"
#include "jmsf/cule/Assert.h"

#include "jmsf/factory_TextObject.h"

#include "jmsf/data_structures/realization_ContainerArray.hpp"


namespace jmsf {
namespace data_structures {


TEST( shouldBeEmptyAfterCreation ) {
	realization_ContainerArray< int > intArray;
	shouldBe( intArray.isEmpty() );
}

TEST( shouldContainAsManyElementsAsAppendedBack ) {
	realization_ContainerArray< integer > intArray;

	intArray.appendBack( 10 );
	shouldBe( intArray.isNotEmpty() );
	naturalValuesShouldBeEqual( natural_size( 1 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getLast() );

	intArray.appendBack( 22 );
	naturalValuesShouldBeEqual( natural_size( 2 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 22 ), intArray.getLast() );

	intArray.appendBack( 33 );
	naturalValuesShouldBeEqual( natural_size( 3 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 33 ), intArray.getLast() );
}

TEST( shouldContainAsManyElementsAsAppendedFront ) {
	realization_ContainerArray< integer > intArray;

	intArray.appendFront( 10 );
	shouldBe( intArray.isNotEmpty() );
	naturalValuesShouldBeEqual( natural_size( 1 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getLast() );

	intArray.appendFront( 22 );
	naturalValuesShouldBeEqual( natural_size( 2 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 22 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getLast() );

	intArray.appendFront( 33 );
	naturalValuesShouldBeEqual( natural_size( 3 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 33 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getLast() );
}

TEST( shouldContainElementInCorrespondedOrder ) {
	realization_ContainerArray< integer > intArray;
	intArray.appendBack( 10 );
	intArray.appendFront( 22 );
	intArray.appendBack( 33 );
	intArray.appendFront( 44 );

	naturalValuesShouldBeEqual( natural_size( 4 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 44 ), intArray.getFirst() );
	integerValuesShouldBeEqual( integer( 33 ), intArray.getLast() );
	integerValuesShouldBeEqual( integer( 44 ), intArray.getAt( 0 ) );
	integerValuesShouldBeEqual( integer( 22 ), intArray.getAt( 1 ) );
	integerValuesShouldBeEqual( integer( 10 ), intArray.getAt( 2 ) );
	integerValuesShouldBeEqual( integer( 33 ), intArray.getAt( 3 ) );
}

TEST( shouldWithdrawElementInCorrespondedOrder ) {
	realization_ContainerArray< integer > intArray;
	intArray.appendBack( 10 );
	intArray.appendFront( 22 );
	intArray.appendBack( 33 );
	intArray.appendFront( 44 );

	integerValuesShouldBeEqual( integer( 44 ), intArray.withdrawFirst() );
	naturalValuesShouldBeEqual( natural_size( 3 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 22 ), intArray.withdrawFirst() );
	naturalValuesShouldBeEqual( natural_size( 2 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 33 ), intArray.withdrawLast() );
	naturalValuesShouldBeEqual( natural_size( 1 ), intArray.getQuantityOfObjects() );
	integerValuesShouldBeEqual( integer( 10 ), intArray.withdrawLast() );
	naturalValuesShouldBeEqual( natural_size( 0 ), intArray.getQuantityOfObjects() );
	shouldBe( intArray.isEmpty() );
}

TEST( should ) {
	notImplementedYet( CONSTANT_TEXT_STRING( "should" ) );
}

} // namespace
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
