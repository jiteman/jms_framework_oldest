#pragma once


#include "../factory_SceneDrawer.h"


namespace nehe {
namespace tutorials {
namespace realizations {


class realization_factory_SceneDrawer :
	public factory_SceneDrawer
{

public:
	// virtuals factory_MaskDm
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< SceneDrawer > > > createSceneDrawer() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_SceneDrawer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_SceneDrawer;
	realization_factory_SceneDrawer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_SceneDrawer( const realization_factory_SceneDrawer &other ) throw();
	const realization_factory_SceneDrawer &operator =( const realization_factory_SceneDrawer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizations


} // namespace tutorials
} // namespace nehe
