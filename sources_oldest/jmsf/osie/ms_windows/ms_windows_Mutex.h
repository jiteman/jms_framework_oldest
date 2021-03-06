#pragma once

#include "../Mutex.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"

#include "ms_windows_include.h"
#include "ms_windows_MultithreadingControl.hxx"
#include "../static_factory_OperatingSystemSpecial.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_Mutex :
	public Mutex,
	public mixins::mixin_Object
{

public:
	// virtuals Mutex
	void lock() throw();
	void unlock() throw();
	Boolean tryToLock() throw();
	Boolean isLocked() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_Mutex() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	friend ms_windows_MultithreadingControl;
	friend static_factory_OperatingSystemSpecial;
	ms_windows_Mutex( const Pointer< CRITICAL_SECTION > &criticalSection ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Mutex > createClone() const throw();

private:
	ms_windows_Mutex( const ms_windows_Mutex &other ) throw( Exception );
	const ms_windows_Mutex &operator =( const ms_windows_Mutex &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< CRITICAL_SECTION > _criticalSection;
	Boolean _isLocked;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
