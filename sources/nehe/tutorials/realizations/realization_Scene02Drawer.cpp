#include "realization_SceneDrawer.h"


#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"


namespace nehe {
namespace tutorials {


namespace realizations {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_SceneDrawer::~realization_SceneDrawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_SceneDrawer::realization_SceneDrawer() throw( jmsf::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< SceneDrawer > realization_SceneDrawer::createClone() const throw() {
	return ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_SceneDrawer( *this ) );
}

realization_SceneDrawer::realization_SceneDrawer( const realization_SceneDrawer & ) throw() // other
{}

const realization_SceneDrawer &realization_SceneDrawer::operator =( const realization_SceneDrawer &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations


} // namespace tutorials
} // namespace nehe
