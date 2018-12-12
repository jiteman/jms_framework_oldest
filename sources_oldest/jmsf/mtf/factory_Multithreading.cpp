#include "factory_Multithreading.h"
#include "realizations/realization_factory_Multithreading.h"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"
#include "../warning_suppressor.h"

namespace jmsf {
namespace mtf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_Multithreading::~factory_Multithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_Multithreading *factory_Multithreading::createInstance() throw() {
	factory_Multithreading *factoryMultithreading = new realizations::realization_factory_Multithreading;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryMultithreading, MACROS_FILE_AND_LINE ) );
	return factoryMultithreading;
}

factory_Multithreading::factory_Multithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_Multithreading::factory_Multithreading( const factory_Multithreading & ) throw() // other
{}

const factory_Multithreading &factory_Multithreading::operator =( const factory_Multithreading &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "factory_Multithreading::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
