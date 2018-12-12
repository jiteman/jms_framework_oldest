#include "EventHandleCache.h"


#include "../ms_windows_Event.h"
#include "jmsf/osie/exceptions/exception_WaitingForEvenetIsFailed.h"
#include "jmsf/osie/exceptions/exception_EventListIsEmpty.h"
#include "jmsf/osie/Event.h"
#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/texting/TextStream.h"
#include "jmsf/containing/Container.inl"
#include "jmsf/containing/Iterator.inl"
#include "jmsf/containing/ConstantIterator.inl"
#include "jmsf/pointing/Pointer.inl"
#include "jmsf/runtiming/Casts.inl"


namespace jmsf {
namespace osie {
namespace ms_windows {
namespace realizing {


typing::Boolean EventHandleCache::isCached() const throw() {
	return _isCached;
}

void EventHandleCache::invalidate() throw() {
	_isCached = typing::False;
}

void EventHandleCache::waitForAllEvents() const throw( validating::Exception ) {
	update();
	::WaitForMultipleObjects( static_cast< DWORD >( _eventHandleContainer.size() ), &_eventHandleContainer[ 0 ], true, INFINITE );
}

typing::Natural EventHandleCache::waitForAnyEvent() const throw( validating::Exception ) {
	update();
	const typing::Natural eventIndex = typing::Natural::create( ::WaitForMultipleObjects( static_cast< DWORD >( _eventHandleContainer.size() ), &_eventHandleContainer[ 0 ], false, INFINITE ) - WAIT_OBJECT_0 );
	
	if ( eventIndex == typing::Natural::create( WAIT_FAILED ) ) {
		typing::Natural lastError;
		lastError = typing::Natural::create( ::GetLastError() );
		pointing::Proxy< texting::TextStream > textStream = texting::factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyEvent() - waiting is failed. GetLastError is " ) )->putNatural( lastError );
		throw exceptions::exception_WaitingForEvenetIsFailed( textStream, FILE_AND_LINE );
	}

	return eventIndex;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
EventHandleCache::~EventHandleCache() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
pointing::Pointer< EventHandleCache > EventHandleCache::create( const pointing::ConstantPointer< ms_windows_EventArray > &eventCollection ) throw() {
	EventHandleCache *eventHandleCache = new EventHandleCache( eventCollection );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( eventHandleCache, MACROS_FILE_AND_LINE ) );
	return pointing::Pointer< EventHandleCache >::createUnique( eventHandleCache );
}

EventHandleCache::EventHandleCache( const pointing::ConstantPointer< ms_windows_EventArray > &eventCollection ) throw()
	:
		_eventCollection( eventCollection )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Pointer< EventHandleCache > EventHandleCache::createClone() const throw() {
	EventHandleCache *eventHandleCache = new EventHandleCache( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( eventHandleCache, MACROS_FILE_AND_LINE ) );
	return pointing::Pointer< EventHandleCache >::createUnique( eventHandleCache );
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
void EventHandleCache::update() const throw( validating::Exception ) {
	if ( _isCached ) return;

	const pointing::ConstantProxy< containing::Container< pointing::Proxy< Event > > > eventContainer = _eventCollection->getEventContainer();
	
	if ( _eventHandleContainer.empty() ) {
		throw exceptions::exception_EventListIsEmpty( CONSTANT_TEXT_STRING( "EventArray::update() - event container is empty" ), FILE_AND_LINE );
	}

	_eventHandleContainer.clear();

	for (
		pointing::Proxy< containing::ConstantIterator< pointing::Proxy< Event > > > eventIterator = eventContainer->createConstantForwardIterator();
		eventIterator->isNotDone();
		eventIterator->advance() )
	{
		const pointing::ConstantPointer< ms_windows_Event > windowsEvent = constantDowncast< ms_windows_Event >( eventIterator->getContainie(), CONSTANT_TEXT_STRING( "Event -> ms_windows_Event" ) );
		_eventHandleContainer.push_back( windowsEvent->getHandle() );
	}

	_isCached = True;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
