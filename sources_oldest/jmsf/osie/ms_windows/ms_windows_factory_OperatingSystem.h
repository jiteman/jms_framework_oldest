#pragma once

#include "../factory_OperatingSystem.h"

#include "jmsf/Proxies.hpp"


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
	const ConstantProxy< MultithreadingControl > &getMultithreadingControl() throw();
	const ConstantProxy< FileSystemControl > &getFileSystemControl() throw();
	const ConstantProxy< UtilityControl > &getUtilityControl() throw();
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
		const Automatic< MultithreadingControl > &multithreadingControl,
		const Automatic< FileSystemControl > &fileSystemControl,
		const Automatic< UtilityControl > &utilityControl ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	ms_windows_factory_OperatingSystem( const ms_windows_factory_OperatingSystem &other ) throw( Exception );
	const ms_windows_factory_OperatingSystem &operator =( const ms_windows_factory_OperatingSystem &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const Automatic< MultithreadingControl > _multithreadingControl;
	const Automatic< FileSystemControl > _fileSystemControl;
	const Automatic< UtilityControl > _utilityControl;

	ConstantProxy< MultithreadingControl > _multithreadingControl_crtr;
	ConstantProxy< FileSystemControl > _fileSystemControl_crtr;
	ConstantProxy< UtilityControl > _utilityControl_crtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Proxy< Mutex > _operatingSystemMutex;

};


} // namespace
}
}
