#include "factory_ExternalSoftware.h"

#include "realizations/realization_factory_ExternalSoftware.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_ExternalSoftware::~factory_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_ExternalSoftware *factory_ExternalSoftware::createInstance() throw() {
	return new realizations::realization_factory_ExternalSoftware;
}

factory_ExternalSoftware::factory_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_ExternalSoftware::factory_ExternalSoftware( const factory_ExternalSoftware & ) throw() // other
{}

const factory_ExternalSoftware &factory_ExternalSoftware::operator =( const factory_ExternalSoftware &other ) throw() {
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
