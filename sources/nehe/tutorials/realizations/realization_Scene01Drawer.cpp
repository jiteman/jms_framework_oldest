#include "realization_Scene01Drawer.h"


#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"

#include "osl/glew/gl/glew.h"


namespace nehe {
namespace tutorials {


namespace realizations {

bool realization_Scene01Drawer::isInitialized() const throw() {
	return _isInitialized;
}


bool realization_Scene01Drawer::prepare() const throw() {
	::glShadeModel( GL_SMOOTH ); // Enable Smooth Shading
	::glClearColor( 0.0f, 0.0f, 0.0f, 0.5f ); // Black Background
	::glClearDepth( 1.0f ); // Depth Buffer Setup
	::glEnable( GL_DEPTH_TEST ); // Enables Depth Testing
	::glDepthFunc( GL_LEQUAL ); // The Type Of Depth Testing To Do
	::glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); // Really Nice Perspective Calculations
	return true; // Initialization Went OK	
}


bool realization_Scene01Drawer::draw() const throw() {
	::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Clear Screen And Depth Buffer
	::glLoadIdentity(); // Reset The Current Modelview Matrix
	return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Scene01Drawer::~realization_Scene01Drawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Scene01Drawer::realization_Scene01Drawer() throw( jmsf::Exception ) {
	_isInitialized = true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< SceneDrawer > realization_Scene01Drawer::createClone() const throw() {
	return ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene01Drawer( *this ) );
}

realization_Scene01Drawer::realization_Scene01Drawer( const realization_Scene01Drawer & ) throw() // other
{}

const realization_Scene01Drawer &realization_Scene01Drawer::operator =( const realization_Scene01Drawer &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations


} // namespace tutorials
} // namespace nehe
