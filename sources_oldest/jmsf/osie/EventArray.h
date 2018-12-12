#pragma once

#include "jmsf/Object.h"

#include "Event.hxx"
#include "jmsf/Pointers.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE EventArray :
	public virtual Object
{

public:
	virtual void appendEvent( const Proxy< Event > &theEvent ) throw( Exception ) = 0;
	virtual void appendEventArray( const Proxy< EventArray > &eventArray ) throw( Exception ) = 0; 
	virtual void setAllEvents() throw() = 0;
	virtual void resetAllEvents() throw() = 0;
	virtual void waitForAnyEvent() const throw( Exception ) = 0;
	virtual const ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( Exception ) = 0;
	virtual Proxy< Event > waitForAnyEventThenGetItOneself() throw( Exception ) = 0;
	virtual void waitForAllEvents() const throw( Exception ) = 0;
	virtual Boolean isEmpty() const throw() = 0;
	virtual natural_size getQuantityOfEvents() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static EventArray *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual Proxy< EventArray > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
