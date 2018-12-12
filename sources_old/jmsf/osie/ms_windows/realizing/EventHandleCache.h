#pragma once


#include "jmsf/pointing/ConstantPointer.hpp"

#include "jmsf/typing/Boolean.h"

#include "../ms_windows_EventArray.h"

#include "jmsf/stdal/stdal_stl.h"
#include "../ms_windows_include.h"

#include "jmsf/validating/Exception.hxx"
#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/typing/Natural.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {
namespace realizing {


class EventHandleCache {

public:
	typing::Boolean isCached() const throw();
	void invalidate() throw();
	void waitForAllEvents() const throw( validating::Exception );
	typing::Natural waitForAnyEvent() const throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< EventHandleCache >;
	~EventHandleCache() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static pointing::Pointer< EventHandleCache > create( const pointing::ConstantPointer< ms_windows_EventArray > &eventCollection ) throw();

private:
	EventHandleCache( const pointing::ConstantPointer< ms_windows_EventArray > &eventCollection ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::Pointer< EventHandleCache > createClone() const throw();

private:
	EventHandleCache( const EventHandleCache &other ) throw();
	const EventHandleCache &operator =( const EventHandleCache &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void update() const throw( validating::Exception );

private:
	mutable typing::Boolean _isCached;
	const pointing::ConstantPointer< ms_windows_EventArray > _eventCollection;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mutable std::vector< const HANDLE > _eventHandleContainer;
};


} // namespace
}
}
}
