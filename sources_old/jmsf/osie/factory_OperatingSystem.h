#pragma once

#include "jmsf/patterning/Singleton.inl"

#include "Mutex.hxx"
#include "MultithreadingControl.hxx"
#include "FileSystemControl.hxx"
#include "UtilityControl.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"

#include "jmsf/jmsf.h"

//#include "../warning_suppressor.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE factory_OperatingSystem :
	public ::jmsf::patterning::Singleton< factory_OperatingSystem >
{

public:
	virtual const pointing::ConstantProxy< MultithreadingControl > &getMultithreadingControl() throw() = 0;
	virtual const pointing::ConstantProxy< FileSystemControl > &getFileSystemControl() throw() = 0;
	virtual const pointing::ConstantProxy< UtilityControl > &getUtilityControl() throw() = 0;
	virtual Mutex *takeOperatingSystemMutex() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_OperatingSystem() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< factory_OperatingSystem >;
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
