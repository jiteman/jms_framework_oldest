#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"
#include "Event.hxx"
#include "EventArray.hxx"
#include "Mutex.hxx"
#include "osie_Thread.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE MultithreadingControl :
	public virtual Object
{

public:
 	virtual Proxy< Event > createEvent() const throw() = 0;
 	virtual Proxy< EventArray > createEventArray() const throw() = 0;
 	virtual Proxy< Mutex > createMutex() const throw() = 0;
	virtual void launchThread( Pointer< osie_Thread > thread, natural_size priorityLevel ) const throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static MultithreadingControl *getNull() throw();
	static MultithreadingControl *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< MultithreadingControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
