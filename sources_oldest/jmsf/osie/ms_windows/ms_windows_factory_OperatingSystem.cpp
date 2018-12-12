#include "ms_windows_factory_OperatingSystem.h"
#include "ms_windows_MultithreadingControl.h"
#include "ms_windows_FileSystemControl.h"
#include "ms_windows_UtilityControl.h"
#include "jmsf/assists/flyweight_factory_Functor.hpp"
#include "jmsf/assists/Functors.hpp"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

const ConstantProxy< MultithreadingControl > &ms_windows_factory_OperatingSystem::getMultithreadingControl() throw() {
	return _multithreadingControl_crtr;
}

const ConstantProxy< FileSystemControl > &ms_windows_factory_OperatingSystem::getFileSystemControl() throw() {
	return _fileSystemControl_crtr;
}

const ConstantProxy< UtilityControl > &ms_windows_factory_OperatingSystem::getUtilityControl() throw() {
	return _utilityControl_crtr;
}

Mutex *ms_windows_factory_OperatingSystem::takeOperatingSystemMutex() throw() {
	return _operatingSystemMutex.get();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_factory_OperatingSystem::~ms_windows_factory_OperatingSystem() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_factory_OperatingSystem::ms_windows_factory_OperatingSystem(
	const Automatic< MultithreadingControl > &multithreadingControl,
	const Automatic< FileSystemControl > &fileSystemControl,
	const Automatic< UtilityControl > &utilityControl ) throw()
	:
//		_factoryOperatingSystemMutex( createMutex() )
		_multithreadingControl( multithreadingControl ),
		_fileSystemControl( fileSystemControl ),
		_utilityControl( utilityControl )
// 		_multithreadingControl(
// 			ConstantProxy< MultithreadingControl >::createUnique(
// 				debugging::static_ObjectCreationLogger< ms_windows_MultithreadingControl >::registerCreation(
// 					new ms_windows_MultithreadingControl, sizeof( ms_windows_MultithreadingControl ), MACROS_FILE_AND_LINE ) ) ),
// 
// 		_fileSystemControl(
// 			ConstantProxy< FileSystemControl >::createUnique(
// 				debugging::static_ObjectCreationLogger< ms_windows_FileSystemControl >::registerCreation(
// 					new ms_windows_FileSystemControl, sizeof( ms_windows_FileSystemControl ), MACROS_FILE_AND_LINE ) ) ),
// 
// 		_utilityControl(
// 			ConstantProxy< UtilityControl >::createUnique(
// 				debugging::static_ObjectCreationLogger< ms_windows_UtilityControl >::registerCreation(
// 					new ms_windows_UtilityControl, sizeof( ms_windows_UtilityControl ), MACROS_FILE_AND_LINE ) ) )
{
	_multithreadingControl_crtr = ConstantProxy< MultithreadingControl >::createNonlinkedFor( _multithreadingControl.get() );
	_fileSystemControl_crtr = ConstantProxy< FileSystemControl >::createNonlinkedFor( _fileSystemControl.get() );
	_utilityControl_crtr = ConstantProxy< UtilityControl >::createNonlinkedFor( _utilityControl.get() );
	_operatingSystemMutex = _multithreadingControl->createMutex();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_factory_OperatingSystem::ms_windows_factory_OperatingSystem( const ms_windows_factory_OperatingSystem & ) throw( Exception ) { // other
	Should::neverViolateCopyingProhibition( "ms_windows_factory_OperatingSystem::ms_windows_factory_OperatingSystem( copy )" );
}

const ms_windows_factory_OperatingSystem &ms_windows_factory_OperatingSystem::operator =( const ms_windows_factory_OperatingSystem &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_factory_OperatingSystem::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
