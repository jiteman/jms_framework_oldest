#pragma once


#include "../SceneDrawer.h"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_factory_SceneDrawer.hxx"


namespace nehe {
namespace tutorials {


namespace realizations {

class realization_SceneDrawer :
	public SceneDrawer,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals SceneDrawer
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_SceneDrawer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_SceneDrawer;
	realization_SceneDrawer() throw( jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< SceneDrawer > createClone() const throw();

private:
	realization_SceneDrawer( const realization_SceneDrawer &other ) throw();
	const realization_SceneDrawer &operator =( const realization_SceneDrawer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations



} // namespace tutorials
} // namespace nehe
