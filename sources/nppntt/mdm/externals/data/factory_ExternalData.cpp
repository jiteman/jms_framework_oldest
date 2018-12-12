#include "factory_ExternalData.h"

#include "realizations/realization_factory_ExternalData.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_ExternalData::~factory_ExternalData() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_ExternalData *factory_ExternalData::createInstance() throw() {
	return new realizations::realization_factory_ExternalData;
}

factory_ExternalData::factory_ExternalData() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_ExternalData::factory_ExternalData( const factory_ExternalData & ) throw() // other
{}

const factory_ExternalData &factory_ExternalData::operator =( const factory_ExternalData &other ) throw() {
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
