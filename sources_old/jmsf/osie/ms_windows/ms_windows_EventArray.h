#pragma once


#include "../EventArray.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/pointing/Proxy.hpp"
#include "jmsf/pointing/Pointer.hpp"

#include "realizing/EventHandleCache.hxx"
#include "jmsf/assisting/Functor.hxx"
#include "jmsf/containing/Container.hxx"

#include "ms_windows_MultithreadingControl.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_EventArray :
	public EventArray,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals EventArray
	void appendEvent( const pointing::Proxy< Event > &theEvent ) throw( validating::Exception );
	void appendEventArray( const pointing::Proxy< EventArray > &eventArray ) throw( validating::Exception );
	void setAllEvents() throw();
	void resetAllEvents() throw();
	void waitForAnyEvent() const throw( validating::Exception );
	const pointing::ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( validating::Exception );
	pointing::Proxy< Event > waitForAnyEventThenGetItOneself() throw( validating::Exception );
	void waitForAllEvents() const throw( validating::Exception );
	typing::Boolean isEmpty() const throw();
	typing::Natural getQuantityOfEvents() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const pointing::ConstantProxy< containing::Container< pointing::Proxy< Event > > > getEventContainer() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	friend memorying::Destructor< ms_windows_EventArray >;
	~ms_windows_EventArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_MultithreadingControl;
	ms_windows_EventArray(
		pointing::Proxy< containing::Container< pointing::Proxy< Event > > > eventContainer,
		pointing::Proxy< assisting::Functor< pointing::Proxy< Event > > > setEventFunctor,
		pointing::Proxy< assisting::Functor< pointing::Proxy< Event > > > resetEventFunctor ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< EventArray > createClone() const throw();

private:
	ms_windows_EventArray( const ms_windows_EventArray &other ) throw();
	const ms_windows_EventArray &operator =( const ms_windows_EventArray &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Proxy< containing::Container< pointing::Proxy< Event > > > _eventContainer;
	pointing::Pointer< realizing::EventHandleCache > _eventHandleCache;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Proxy< assisting::Functor< pointing::Proxy< Event > > > _setEventFunctor;
	pointing::Proxy< assisting::Functor< pointing::Proxy< Event > > > _resetEventFunctor;

};


} // namespace
}
}
