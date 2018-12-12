#include "factory_SceneDrawer.h"


#include "realizing/realization_factory_SceneDrawer.h"


namespace nehe {
namespace tutorials {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_SceneDrawer::~factory_SceneDrawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_SceneDrawer *factory_SceneDrawer::createInstance() throw() {
	return new realizations::realization_factory_SceneDrawer;
}

factory_SceneDrawer::factory_SceneDrawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_SceneDrawer::factory_SceneDrawer( const factory_SceneDrawer & ) throw() // other
{}

const factory_SceneDrawer &factory_SceneDrawer::operator =( const factory_SceneDrawer &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace tutorials
} // namespace nehe
