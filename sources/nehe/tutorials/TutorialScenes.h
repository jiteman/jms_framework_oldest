#pragma once

#include "jmsf/Singleton.hpp"

#include "SceneDrawer.hxx"
#include "jmsf/Proxies.hxx"


namespace nehe {
namespace tutorials {


class TutorialScenes :
	public ::jmsf::Singleton< TutorialScenes >
{

public:
	virtual ::jmsf::Proxy< SceneDrawer > getCurrentSceneDrawer() throw() = 0;
	virtual void switchToPreviousSceneDrawer() throw() = 0;
	virtual void switchToNextSceneDrawer() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~TutorialScenes() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< TutorialScenes >;
	static TutorialScenes *createInstance() throw();

protected:
	TutorialScenes() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	TutorialScenes( const TutorialScenes &other ) throw();
	const TutorialScenes &operator =( const TutorialScenes &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace tutorials
} // namespace nehe
