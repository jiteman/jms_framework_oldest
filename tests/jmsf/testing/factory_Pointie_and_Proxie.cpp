#include "factory_Pointie_and_Proxie.h"
#include "realizing/realization_factory_Pointie_and_Proxie.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace testing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_Pointie_and_Proxie::~factory_Pointie_and_Proxie() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_Pointie_and_Proxie *factory_Pointie_and_Proxie::createInstance() throw() {
	factory_Pointie_and_Proxie *factoryTesting = new realizations::realization_factory_Pointie_and_Proxie;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryTesting, MACROS_FILE_AND_LINE ) );
	return factoryTesting;
}

factory_Pointie_and_Proxie::factory_Pointie_and_Proxie() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_Pointie_and_Proxie::factory_Pointie_and_Proxie( const factory_Pointie_and_Proxie & ) throw() // other
{}

const factory_Pointie_and_Proxie &factory_Pointie_and_Proxie::operator =( const factory_Pointie_and_Proxie &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
