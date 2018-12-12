#pragma once

#include "jmsf/patterning/Object.h"

#include "Event.hxx"
//#include "jmsf/Pointers.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"
#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/typing/Natural.h"
#include "jmsf/typing/Boolean.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE EventArray :
	public virtual patterning::Object
{

public:
	virtual void appendEvent( const pointing::Proxy< Event > &theEvent ) throw( validating::Exception ) = 0;
	virtual void appendEventArray( const pointing::Proxy< EventArray > &eventArray ) throw( validating::Exception ) = 0; 
	virtual void setAllEvents() throw() = 0;
	virtual void resetAllEvents() throw() = 0;
	virtual void waitForAnyEvent() const throw( validating::Exception ) = 0;
	virtual const pointing::ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( validating::Exception ) = 0;
	virtual pointing::Proxy< Event > waitForAnyEventThenGetItOneself() throw( validating::Exception ) = 0;
	virtual void waitForAllEvents() const throw( validating::Exception ) = 0;
	virtual typing::Boolean isEmpty() const throw() = 0;
	virtual typing::Natural getQuantityOfEvents() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static EventArray *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual pointing::Proxy< EventArray > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
