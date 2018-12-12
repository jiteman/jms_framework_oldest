#include "factory_FileFilters.h"

#include "realizations/realization_factory_FileFilters.h"


namespace nppntt {
namespace mdm {
namespace file_filters {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_FileFilters::~factory_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_FileFilters *factory_FileFilters::createInstance() throw() {
	return new realizations::realization_factory_FileFilters;
}

factory_FileFilters::factory_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_FileFilters::factory_FileFilters( const factory_FileFilters & ) throw() // other
{}

const factory_FileFilters &factory_FileFilters::operator =( const factory_FileFilters &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
