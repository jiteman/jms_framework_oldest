#include "factory_Sensing.h"
#include "realizing/realization_factory_Sensing.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace sensing {
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_Sensing::~factory_Sensing() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_Sensing *factory_Sensing::create_singleton_instance() noexept {
//factory_Sensing *factory_Sensing::createInstance() throw() {
	factory_Sensing *factorySensing = new realizing::realization_factory_Sensing;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factorySensing, MACROS_FILE_AND_LINE ) );
	return factorySensing;
}

factory_Sensing::factory_Sensing() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_Sensing::factory_Sensing( const factory_Sensing & ) throw() // other
{}

const factory_Sensing &factory_Sensing::operator =( const factory_Sensing &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
