#include "factory_StatisticsProcesses.h"
#include "realizations/realization_factory_StatisticsProcesses.h"

namespace nppntt {
namespace mdm {
namespace statistics {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_StatisticsProcesses::~factory_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_StatisticsProcesses *factory_StatisticsProcesses::createInstance() throw() {
	return new realizations::realization_factory_StatisticsProcesses;
}

factory_StatisticsProcesses::factory_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_StatisticsProcesses::factory_StatisticsProcesses( const factory_StatisticsProcesses & ) throw() // other
{}

const factory_StatisticsProcesses &factory_StatisticsProcesses::operator =( const factory_StatisticsProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
