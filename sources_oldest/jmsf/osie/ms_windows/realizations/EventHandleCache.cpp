#include "EventHandleCache.h"
#include "../ms_windows_Event.h"
#include "jmsf/osie/exceptions/exception_WaitingForEvenetIsFailed.h"
#include "jmsf/osie/exceptions/exception_EventListIsEmpty.h"
#include "jmsf/osie/Event.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/Container.hpp"
#include "jmsf/Iterators.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Casts.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {
namespace realizations {


Boolean EventHandleCache::isCached() const throw() {
	return _isCached;
}

void EventHandleCache::invalidate() throw() {
	_isCached = False;
}

void EventHandleCache::waitForAllEvents() const throw( Exception ) {
	update();
	::WaitForMultipleObjects( static_cast< DWORD >( _eventHandleContainer.size() ), &_eventHandleContainer[ 0 ], true, INFINITE );
}

natural_size EventHandleCache::waitForAnyEvent() const throw( Exception ) {
	update();
	const natural_size eventIndex = ::WaitForMultipleObjects( static_cast< DWORD >( _eventHandleContainer.size() ), &_eventHandleContainer[ 0 ], false, INFINITE ) - WAIT_OBJECT_0;
	
	if ( eventIndex == WAIT_FAILED ) {
		DWORD lastError = 0;
		lastError = ::GetLastError();
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyEvent() - waiting is failed. GetLastError is " ) )->putNatural( lastError );
		throw exceptions::exception_WaitingForEvenetIsFailed( textStream );
	}

	return eventIndex;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
EventHandleCache::~EventHandleCache() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Pointer< EventHandleCache > EventHandleCache::create( const ConstantPointer< ms_windows_EventArray > &eventCollection ) throw() {
	EventHandleCache *eventHandleCache = new EventHandleCache( eventCollection );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( eventHandleCache, MACROS_FILE_AND_LINE ) );
	return Pointer< EventHandleCache >::createUnique( eventHandleCache );
}

EventHandleCache::EventHandleCache( const ConstantPointer< ms_windows_EventArray > &eventCollection ) throw()
	:
		_eventCollection( eventCollection )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointer< EventHandleCache > EventHandleCache::createClone() const throw() {
	EventHandleCache *eventHandleCache = new EventHandleCache( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( eventHandleCache, MACROS_FILE_AND_LINE ) );
	return Pointer< EventHandleCache >::createUnique( eventHandleCache );
}

EventHandleCache::EventHandleCache( const EventHandleCache &other ) throw()
	:
		_eventCollection( other._eventCollection )
{}

const EventHandleCache &EventHandleCache::operator =( const EventHandleCache &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
void EventHandleCache::update() const throw( Exception ) {
	if ( _isCached ) return;

	const ConstantProxy< Container< Proxy< Event > > > eventContainer = _eventCollection->getEventContainer();
	
	if ( _eventHandleContainer.empty() ) {
		throw exceptions::exception_EventListIsEmpty( CONSTANT_TEXT_STRING( "EventArray::update() - event container is empty" ) );
	}

	_eventHandleContainer.clear();

	for (
		Proxy< ConstantIterator< Proxy< Event > > > eventIterator = eventContainer->createConstantForwardIterator();
		eventIterator->isNotDone();
		eventIterator->advance() )
	{
		const ConstantPointer< ms_windows_Event > windowsEvent = constantDowncast< ms_windows_Event >( eventIterator->getContainie(), CONSTANT_TEXT_STRING( "Event -> ms_windows_Event" ) );
		_eventHandleContainer.push_back( windowsEvent->getHandle() );
	}

	_isCached = True;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
