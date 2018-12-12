#include "realization_factory_Sensing.h"
#include "realization_sensing_Pointie.h"
////#include "jmsf/Pointers.hpp"
////#include "jmsf/debugging/ObjectCreationLogging.h"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Constructor.inl"

namespace jmsf {
namespace sensing {
namespace realizing {


pointing::Pointer< sensing_Pointie > realization_factory_Sensing::createPointie( const memorying::Womp< memorying::Allocator > &pointie_allocator ) const throw() {
	return pointing::Pointer< sensing_Pointie >::create_unique( memorying::Constructor< sensing_Pointie, realization_sensing_Pointie >::construct( pointie_allocator ) );
//	sensing_Pointie *sensingPointie = new realization_sensing_Pointie;
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( sensingPointie, MACROS_FILE_AND_LINE ) );
//	return Pointer< sensing_Pointie >::createUnique( sensingPointie );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_Sensing::~realization_factory_Sensing() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Sensing::realization_factory_Sensing() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Sensing::realization_factory_Sensing( const realization_factory_Sensing & ) throw() // other
{}

const realization_factory_Sensing &realization_factory_Sensing::operator =( const realization_factory_Sensing &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
