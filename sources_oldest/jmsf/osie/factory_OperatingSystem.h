#pragma once

#include "../Singleton.hpp"

#include "Mutex.hxx"
#include "MultithreadingControl.hxx"
#include "FileSystemControl.hxx"
#include "UtilityControl.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

#include "../warning_suppressor.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE factory_OperatingSystem :
	public Singleton< factory_OperatingSystem >
{

public:
	virtual const ConstantProxy< MultithreadingControl > &getMultithreadingControl() throw() = 0;
	virtual const ConstantProxy< FileSystemControl > &getFileSystemControl() throw() = 0;
	virtual const ConstantProxy< UtilityControl > &getUtilityControl() throw() = 0;
	virtual Mutex *takeOperatingSystemMutex() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_OperatingSystem() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< factory_OperatingSystem >;
	static factory_OperatingSystem *createInstance() throw();

protected:
	factory_OperatingSystem() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_OperatingSystem( const factory_OperatingSystem &other ) throw();
	const factory_OperatingSystem &operator =( const factory_OperatingSystem &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
