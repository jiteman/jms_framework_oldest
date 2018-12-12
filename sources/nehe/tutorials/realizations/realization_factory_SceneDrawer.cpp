#include "realization_factory_SceneDrawer.h"


#include "../factory_SceneDrawer.h"

#include "realization_Scene01Drawer.h"

#include "jmsf/factory_Container.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"




namespace nehe {
namespace tutorials {
namespace realizations {

::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< SceneDrawer > > > realization_factory_SceneDrawer::createSceneDrawer() const throw() {
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< SceneDrawer > > > scenes = ::jmsf::factory_Container< ::jmsf::Proxy< SceneDrawer > >::instance()->createArray();

	{
		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene01Drawer );
		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
		scenes->appendBack( newSceneDrawer.takeAsShared() );
	}

// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene02Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}
// 
// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene03Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}
// 
// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene04Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}
// 
// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene05Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}
// 
// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene06Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}
// 
// 	{
// 		::jmsf::Proxy< SceneDrawer > newSceneDrawer = ::jmsf::Proxy< SceneDrawer >::createUnique( new realization_Scene07Drawer );
// 		::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( newSceneDrawer.get(), MACROS_FILE_AND_LINE ) );
// 		scenes->appendBack( newSceneDrawer.takeAsShared() );
// 	}

	return scenes;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_SceneDrawer::~realization_factory_SceneDrawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_SceneDrawer::realization_factory_SceneDrawer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_SceneDrawer::realization_factory_SceneDrawer( const realization_factory_SceneDrawer & ) throw() // other
{}

const realization_factory_SceneDrawer &realization_factory_SceneDrawer::operator =( const realization_factory_SceneDrawer &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations

} // namespace tutorials
} // namespace nehe
