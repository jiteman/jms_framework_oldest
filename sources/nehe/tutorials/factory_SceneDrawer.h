#pragma once


#include "jmsf/Singleton.hpp"

#include "SceneDrawer.hxx"

#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"


namespace nehe {
namespace tutorials {


class factory_SceneDrawer :
	public ::jmsf::Singleton< factory_SceneDrawer >
{

public:
	virtual ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< SceneDrawer > > > createSceneDrawer() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_SceneDrawer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_SceneDrawer >;
	static factory_SceneDrawer *createInstance() throw();

protected:
	factory_SceneDrawer() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_SceneDrawer( const factory_SceneDrawer &other ) throw();
	const factory_SceneDrawer &operator =( const factory_SceneDrawer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace tutorials
} // namespace nehe
