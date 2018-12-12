#pragma once

#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/Pointer.hxx"

#include "Event.hxx"
#include "EventArray.hxx"
#include "Mutex.hxx"
#include "osie_Thread.hxx"


#include "jmsf/typing/Natural.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE MultithreadingControl :
	public virtual patterning::Object
{

public:
 	virtual pointing::Proxy< Event > createEvent() const throw() = 0;
 	virtual pointing::Proxy< EventArray > createEventArray() const throw() = 0;
 	virtual pointing::Proxy< Mutex > createMutex() const throw() = 0;
	virtual void launchThread( pointing::Pointer< osie_Thread > aThread, typing::Natural priorityLevel ) const throw( validating::Exception ) = 0;

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
	virtual pointing::Proxy< MultithreadingControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace osie
} // namespace jmsf
