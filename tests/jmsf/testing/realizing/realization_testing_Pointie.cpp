#include "realization_testing_Pointie.h"
#include "../../sensing/sensing_Pointie.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"

// #include "jmsf/memorying/Constructor.inl"
// #include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace testing {
namespace realizations {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_testing_Pointie::~realization_testing_Pointie() throw() {
	_sensingPointer->registerDestruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Pointie::realization_testing_Pointie(
	const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) throw()
	:
		_sensingPointer( sensingPointer )
{
	_sensingPointer->registerConstruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ::jmsf::pointing::Pointer< testing_Pointie > realization_testing_Pointie::createClone() const throw() {
// 	memorying::temporary_Allocator temporary_allocator;
// 	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
// 
// 	return
// 		pointing::Pointer< testing_Pointie >::create_unique(
// 			memorying::Constructor< testing_Pointie, realization_testing_Pointie >::construct( the_temporary_allocator ) );
// 
// ////	testing_Pointie *testingPointie = new realization_testing_Pointie( *this );
// ////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( testingPointie, MACROS_FILE_AND_LINE ) );
// ////	return ::jmsf::Pointer< testing_Pointie >::createUnique( testingPointie );
// }

realization_testing_Pointie::realization_testing_Pointie( const realization_testing_Pointie & ) throw() // other
{}

const realization_testing_Pointie &realization_testing_Pointie::operator =( const realization_testing_Pointie &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
