#include "factory_MaskDmObjects.h"

#include "realizations/realization_factory_MaskDmObjects.h"


namespace nppntt {
namespace mdm {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_MaskDmObjects::~factory_MaskDmObjects() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_MaskDmObjects *factory_MaskDmObjects::createInstance() throw() {
	return new realizations::realization_factory_MaskDmObjects;
}

factory_MaskDmObjects::factory_MaskDmObjects() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_MaskDmObjects::factory_MaskDmObjects( const factory_MaskDmObjects & ) throw() // other
{}

const factory_MaskDmObjects &factory_MaskDmObjects::operator =( const factory_MaskDmObjects &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
