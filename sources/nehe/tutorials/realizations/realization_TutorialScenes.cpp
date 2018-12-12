#include "realization_TutorialScenes.h"

#include "../factory_SceneDrawer.h"
#include "../SceneDrawer.h"

#include "jmsf/Container.hpp"
#include "jmsf/Iterators.hpp"
#include "jmsf/Proxies.hpp"


namespace nehe {
namespace tutorials {
namespace realizations {

::jmsf::Proxy< SceneDrawer > realization_TutorialScenes::getCurrentSceneDrawer() throw() {
	return _currentSceneDrawer.takeAsShared();
}

void realization_TutorialScenes::switchToPreviousSceneDrawer() throw() {

}

void realization_TutorialScenes::switchToNextSceneDrawer() throw() {
	if ( _sceneDrawerIterator->isNotDone() ) {
		_sceneDrawerIterator->advance();
	}

	if ( _sceneDrawerIterator->isDone() ) {
		_sceneDrawerIterator = _sceneDrawers->createForwardIterator();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_TutorialScenes::~realization_TutorialScenes() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TutorialScenes::realization_TutorialScenes() throw() {
	_sceneDrawers = factory_SceneDrawer::instance()->createSceneDrawer();
	_sceneDrawerIterator = _sceneDrawers->createForwardIterator();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TutorialScenes::realization_TutorialScenes( const realization_TutorialScenes & ) throw() // other
{}

const realization_TutorialScenes &realization_TutorialScenes::operator =( const realization_TutorialScenes &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations

} // namespace tutorials
} // namespace nehe
