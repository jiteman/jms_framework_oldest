#pragma once

#include "../factory_OperatingSystem.h"

#include "jmsf/pointing/ConstantProxy.hpp"
#include "jmsf/pointing/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_factory_OperatingSystem :
	public factory_OperatingSystem
{

public:
	// virtuals factory_OperatingSystem
// 	Proxy< Event > createEvent() const throw();
// 	Proxy< EventArray > createEventArray() const throw();
// 	Proxy< Mutex > createMutex() const throw();
	const pointing::ConstantProxy< MultithreadingControl > &getMultithreadingControl() throw();
	const pointing::ConstantProxy< FileSystemControl > &getFileSystemControl() throw();
	const pointing::ConstantProxy< UtilityControl > &getUtilityControl() throw();
	Mutex *takeOperatingSystemMutex() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_factory_OperatingSystem() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_OperatingSystem;
	ms_windows_factory_OperatingSystem(
		const pointing::AutomaticPointer< MultithreadingControl > &multithreadingControl,
		const pointing::AutomaticPointer< FileSystemControl > &fileSystemControl,
		const pointing::AutomaticPointer< UtilityControl > &utilityControl ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	ms_windows_factory_OperatingSystem( const ms_windows_factory_OperatingSystem &other ) throw( validating::Exception );
	const ms_windows_factory_OperatingSystem &operator =( const ms_windows_factory_OperatingSystem &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const pointing::AutomaticPointer< MultithreadingControl > _multithreadingControl;
	const pointing::AutomaticPointer< FileSystemControl > _fileSystemControl;
	const pointing::AutomaticPointer< UtilityControl > _utilityControl;

	pointing::ConstantProxy< MultithreadingControl > _multithreadingControl_crtr;
	pointing::ConstantProxy< FileSystemControl > _fileSystemControl_crtr;
	pointing::ConstantProxy< UtilityControl > _utilityControl_crtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Proxy< Mutex > _operatingSystemMutex;

};


} // namespace
}
}
