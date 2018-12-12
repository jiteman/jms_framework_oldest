#pragma once

#include "jmsf/Boolean.h"

#include "jmsf/stdal/stdal_stl.h"

#include "../ms_windows_include.h"

#include "../ms_windows_EventArray.h"
#include "jmsf/Exception.hxx"
#include "jmsf/Pointers.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {
namespace realizations {


class EventHandleCache {

public:
	Boolean isCached() const throw();
	void invalidate() throw();
	void waitForAllEvents() const throw( Exception );
	natural_size waitForAnyEvent() const throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend DeleterForPointer< EventHandleCache >;
	~EventHandleCache() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Pointer< EventHandleCache > create( const ConstantPointer< ms_windows_EventArray > &eventCollection ) throw();

private:
	EventHandleCache( const ConstantPointer< ms_windows_EventArray > &eventCollection ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointer< EventHandleCache > createClone() const throw();

private:
	EventHandleCache( const EventHandleCache &other ) throw();
	const EventHandleCache &operator =( const EventHandleCache &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void update() const throw( Exception );

private:
	mutable Boolean _isCached;
	const ConstantPointer< ms_windows_EventArray > _eventCollection;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mutable std::vector< const HANDLE > _eventHandleContainer;
};


} // namespace
}
}
}
