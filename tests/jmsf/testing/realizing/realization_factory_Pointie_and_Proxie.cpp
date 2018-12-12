#include "realization_factory_Pointie_and_Proxie.h"
#include "realization_testing_Pointie.h"
#include "realization_testing_Proxie.h"

#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/Pointer.inl"
////#include "jmsf/debugging/ObjectCreationLogging.h"

#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace testing {
namespace realizations {


::jmsf::pointing::Pointer< testing_Pointie > realization_factory_Pointie_and_Proxie::createPointie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	return
		pointing::Pointer< testing_Pointie >::create_unique(
			memorying::Constructor< testing_Pointie, realization_testing_Pointie >::construct( the_temporary_allocator, sensingPointer ) );
// 	testing_Pointie *testingPointie = new realization_testing_Pointie( sensingPointer );
//// 	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( testingPointie, MACROS_FILE_AND_LINE ) );
// 	return ::jmsf::Pointer< testing_Pointie >::createUnique( testingPointie );
}

::jmsf::pointing::Proxy< testing_Proxie > realization_factory_Pointie_and_Proxie::createProxie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	return
		pointing::Proxy< testing_Proxie >::create_unique(
			memorying::Constructor< testing_Proxie, realization_testing_Proxie >::construct( the_temporary_allocator, sensingPointer ) );
// 	testing_Proxie *testingProxie = new realization_testing_Proxie( sensingPointer );
//// 	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( testingProxie, MACROS_FILE_AND_LINE ) );
// 	return ::jmsf::Proxy< testing_Proxie >::createUnique( testingProxie );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_Pointie_and_Proxie::~realization_factory_Pointie_and_Proxie() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Pointie_and_Proxie::realization_factory_Pointie_and_Proxie() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Pointie_and_Proxie::realization_factory_Pointie_and_Proxie( const realization_factory_Pointie_and_Proxie & ) throw() // other
{}

const realization_factory_Pointie_and_Proxie &realization_factory_Pointie_and_Proxie::operator =( const realization_factory_Pointie_and_Proxie &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
