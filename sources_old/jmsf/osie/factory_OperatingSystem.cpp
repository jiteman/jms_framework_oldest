#include "factory_OperatingSystem.h"


#include "ms_windows/ms_windows_factory_OperatingSystem.h"
#include "ms_windows/ms_windows_MultithreadingControl.h"
#include "ms_windows/ms_windows_FileSystemControl.h"
#include "ms_windows/ms_windows_UtilityControl.h"


namespace jmsf {
namespace osie {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_OperatingSystem::~factory_OperatingSystem() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_OperatingSystem *factory_OperatingSystem::createInstance() throw() {
	ms_windows::ms_windows_MultithreadingControl *multithreadingControlPointer = new ms_windows::ms_windows_MultithreadingControl;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( multithreadingControlPointer, MACROS_FILE_AND_LINE ) );
	const pointing::AutomaticPointer< MultithreadingControl > multithreadingControl = pointing::AutomaticPointer< MultithreadingControl >( multithreadingControlPointer );

	ms_windows::ms_windows_FileSystemControl *fileSystemControlPointer = new ms_windows::ms_windows_FileSystemControl;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( fileSystemControlPointer, MACROS_FILE_AND_LINE ) );
	const pointing::AutomaticPointer< FileSystemControl > fileSystemControl = pointing::AutomaticPointer< FileSystemControl >( fileSystemControlPointer );

	ms_windows::ms_windows_UtilityControl *utilityControlPointer = new ms_windows::ms_windows_UtilityControl;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( utilityControlPointer, MACROS_FILE_AND_LINE ) );
	const pointing::AutomaticPointer< UtilityControl > utilityControl = pointing::AutomaticPointer< UtilityControl >( utilityControlPointer );
	
	ms_windows::ms_windows_factory_OperatingSystem *factoryOperatingSystem = new ms_windows::ms_windows_factory_OperatingSystem( multithreadingControl, fileSystemControl, utilityControl );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryOperatingSystem, MACROS_FILE_AND_LINE ) );
	return factoryOperatingSystem;
}

factory_OperatingSystem::factory_OperatingSystem() throw() 
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_OperatingSystem::factory_OperatingSystem( const factory_OperatingSystem & ) throw() // other
{}

const factory_OperatingSystem &factory_OperatingSystem::operator =( const factory_OperatingSystem &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
