#include "factory_ed_Statistics.h"

#include "realizations/realization_factory_ed_Statistics.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_ed_Statistics::~factory_ed_Statistics() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_ed_Statistics *factory_ed_Statistics::createInstance() throw() {
	return new realizations::realization_factory_ed_Statistics;
}

factory_ed_Statistics::factory_ed_Statistics() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_ed_Statistics::factory_ed_Statistics( const factory_ed_Statistics & ) throw() // other
{}

const factory_ed_Statistics &factory_ed_Statistics::operator =( const factory_ed_Statistics &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
}
