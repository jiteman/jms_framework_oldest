#pragma once

#include "../EventArray.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"

#include "realizations/EventHandleCache.hxx"
#include "jmsf/assists/Functors.hxx"
#include "jmsf/Container.hxx"

#include "ms_windows_MultithreadingControl.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_EventArray :
	public EventArray,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals EventArray
	void appendEvent( const Proxy< Event > &theEvent ) throw( Exception );
	void appendEventArray( const Proxy< EventArray > &eventArray ) throw( Exception );
	void setAllEvents() throw();
	void resetAllEvents() throw();
	void waitForAnyEvent() const throw( Exception );
	const ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( Exception );
	Proxy< Event > waitForAnyEventThenGetItOneself() throw( Exception );
	void waitForAllEvents() const throw( Exception );
	Boolean isEmpty() const throw();
	natural_size getQuantityOfEvents() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const ConstantProxy< Container< Proxy< Event > > > getEventContainer() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	friend DeleterForPointer< ms_windows_EventArray >;
	~ms_windows_EventArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_MultithreadingControl;
	ms_windows_EventArray(
		Proxy< Container< Proxy< Event > > > eventContainer,
		Proxy< assists::Functor< Proxy< Event > > > setEventFunctor,
		Proxy< assists::Functor< Proxy< Event > > > resetEventFunctor ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< EventArray > createClone() const throw();

private:
	ms_windows_EventArray( const ms_windows_EventArray &other ) throw();
	const ms_windows_EventArray &operator =( const ms_windows_EventArray &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< Container< Proxy< Event > > > _eventContainer;
	Pointer< realizations::EventHandleCache > _eventHandleCache;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Proxy< assists::Functor< Proxy< Event > > > _setEventFunctor;
	Proxy< assists::Functor< Proxy< Event > > > _resetEventFunctor;

};


} // namespace
}
}
