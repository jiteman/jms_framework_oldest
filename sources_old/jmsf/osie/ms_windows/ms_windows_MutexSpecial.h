#pragma once


#include "../Mutex.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/pointing/AutomaticPointer.hpp"
#include "jmsf/typing/Boolean.h"

#include "ms_windows_include.h"
#include "ms_windows_MultithreadingControl.hxx"
#include "../static_factory_OperatingSystemSpecial.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_MutexSpecial :
	public Mutex,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals Mutex
	void lock() throw();
	void unlock() throw();
	typing::Boolean tryToLock() throw();
	typing::Boolean isLocked() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_MutexSpecial() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	friend ms_windows_MultithreadingControl;
	friend static_factory_OperatingSystemSpecial;
	ms_windows_MutexSpecial( const pointing::AutomaticPointer< CRITICAL_SECTION > &criticalSection ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Mutex > createClone() const throw();

private:
	ms_windows_MutexSpecial( const ms_windows_MutexSpecial &other ) throw( validating::Exception );
	const ms_windows_MutexSpecial &operator =( const ms_windows_MutexSpecial &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::AutomaticPointer< CRITICAL_SECTION > _criticalSection;
	typing::Boolean _isLocked;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
