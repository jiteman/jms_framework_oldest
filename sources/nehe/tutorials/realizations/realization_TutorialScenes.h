#pragma once


#include "../TutorialScenes.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/Container.hxx"
#include "jmsf/Iterators.hxx"


namespace nehe {
namespace tutorials {
namespace realizations {


class realization_TutorialScenes :
	public TutorialScenes
{

public:
	// virtuals TutorialScenes
	::jmsf::Proxy< SceneDrawer > getCurrentSceneDrawer() throw();
	void switchToPreviousSceneDrawer() throw();
	void switchToNextSceneDrawer() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_TutorialScenes() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend TutorialScenes;
	realization_TutorialScenes() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_TutorialScenes( const realization_TutorialScenes &other ) throw();
	const realization_TutorialScenes &operator =( const realization_TutorialScenes &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< SceneDrawer > _currentSceneDrawer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< SceneDrawer > > > _sceneDrawers;
	::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< SceneDrawer > > > _sceneDrawerIterator;

};


} // namespace realizations


} // namespace tutorials
} // namespace nehe
