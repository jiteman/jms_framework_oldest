#include "factory_ProcessingProcesses.h"

#include "realizations/realization_factory_ProcessingProcesses.h"


namespace nppntt {
namespace mdm {
namespace processing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_ProcessingProcesses::~factory_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_ProcessingProcesses *factory_ProcessingProcesses::createInstance() throw() {
	return new realizations::realization_factory_ProcessingProcesses;
}

factory_ProcessingProcesses::factory_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_ProcessingProcesses::factory_ProcessingProcesses( const factory_ProcessingProcesses & ) throw() // other
{}

const factory_ProcessingProcesses &factory_ProcessingProcesses::operator =( const factory_ProcessingProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
