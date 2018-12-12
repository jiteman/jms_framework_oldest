#include "factory_MaskDm.h"

#include "realizations/realization_factory_MaskDm.h"


namespace nppntt {
namespace mdm {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_MaskDm::~factory_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_MaskDm *factory_MaskDm::createInstance() throw() {
	return new realizations::realization_factory_MaskDm;
}

factory_MaskDm::factory_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_MaskDm::factory_MaskDm( const factory_MaskDm & ) throw() // other
{}

const factory_MaskDm &factory_MaskDm::operator =( const factory_MaskDm &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
