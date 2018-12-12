#include "ms_windows_EventArray.h"
#include "realizations/EventHandleCache.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/exceptions/exception_EventIsNullptr.h"
#include "jmsf/osie/exceptions/exception_EventArrayIsNullptr.h"
#include "jmsf/osie/exceptions/exception_EventIsAlreadyAdded.h"
#include "jmsf/exceptions/exception_UnexpectedStlException.h"
#include "jmsf/Container.hpp"
#include "jmsf/TextStream.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/assists/Functors.hpp"
#include "jmsf/assists/DoForEvery.hpp"
#include "jmsf/assists/Find.hpp"
#include "jmsf/Casts.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"
#include "../../warning_suppressor.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

void ms_windows_EventArray::appendEvent( const Proxy< Event > &theEvent ) throw( Exception ) {
	if ( theEvent.get() == nullptr ) {
		throw exceptions::exception_EventIsNullptr( CONSTANT_TEXT_STRING( "EventArray::addEvent - new event is null" ) );
	}

	const Proxy< Iterator< Proxy< Event > > > foundEvent = assists::find( _eventContainer, theEvent );
	_eventHandleCache->invalidate();
	_eventContainer->appendBack( theEvent );
}

void ms_windows_EventArray::appendEventArray( const Proxy< EventArray > &eventArray ) throw( Exception ) {
	if ( eventArray.get() == nullptr ) {
		throw exceptions::exception_EventArrayIsNullptr( CONSTANT_TEXT_STRING( "EventArray::addEventArray - event array is null" ) );
	}

	const ConstantPointer< ms_windows_EventArray > ms_windows_eventArray = constantDowncast< ms_windows_EventArray >( eventArray, CONSTANT_TEXT_STRING( "EventArray => ms_windows_EventArray" ) );

	for (
		Proxy< ConstantIterator< Proxy< Event > > > iterator = _eventContainer->createConstantForwardIterator();
		iterator->isNotDone();
		iterator->advance() )
	{
		appendEvent( iterator->getContainie() );
	}
}

void ms_windows_EventArray::setAllEvents() throw() {
	assists::doForEvery( _eventContainer, _setEventFunctor );
}

void ms_windows_EventArray::resetAllEvents() throw() {
	assists::doForEvery( _eventContainer, _resetEventFunctor );
}

void ms_windows_EventArray::waitForAnyEvent() const throw( Exception ) {
	try {
		_eventHandleCache->waitForAnyEvent();
	} catch ( const std::out_of_range &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAny() - out of range exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	} catch ( const std::exception &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAny() - unexpected std exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	}
}

const ConstantProxy< Event > ms_windows_EventArray::waitForAnyEventThenGetIt() const throw( Exception ) {
	ConstantProxy< Event > event;

	try {
		event = _eventContainer->getContainie( _eventHandleCache->waitForAnyEvent() ).getNonlinkedConstant();
	} catch ( const std::out_of_range &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyAndGet() - out of range exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	} catch ( const std::exception &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyGet() - unexpected std exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	}

	return event;
}

Proxy< Event > ms_windows_EventArray::waitForAnyEventThenGetItOneself() throw( Exception ) {
	Proxy< Event > event;

	try {
		event = _eventContainer->takeContainie( _eventHandleCache->waitForAnyEvent() ).getNonlinked();
	} catch ( const std::out_of_range &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyGetOneself() - out of range exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	} catch ( const std::exception &catched ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "EventArray::waitForAnyAndGetOneself() - unexpected std exception: " ) )->put( TEXT_STRING( catched.what() ) );
		throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );		
	}

	return event;
}

void ms_windows_EventArray::waitForAllEvents() const throw( Exception ) {
	return _eventHandleCache->waitForAllEvents();
}

Boolean ms_windows_EventArray::isEmpty() const throw() {
	return _eventContainer->isEmpty();
}

natural_size ms_windows_EventArray::getQuantityOfEvents() const throw() {
	return _eventContainer->getQuantityOfElements();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ConstantProxy< Container< Proxy< Event > > > ms_windows_EventArray::getEventContainer() const throw() {
	return _eventContainer.getNonlinkedConstant();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_EventArray::~ms_windows_EventArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_EventArray::ms_windows_EventArray(
	Proxy< Container< Proxy< Event > > > eventContainer,
	Proxy< assists::Functor< Proxy< Event > > > setEventFunctor,
	Proxy< assists::Functor< Proxy< Event > > > resetEventFunctor ) throw()
	:
		_eventContainer( eventContainer ),
		_setEventFunctor( setEventFunctor ),
		_resetEventFunctor( resetEventFunctor ),
		_eventHandleCache( realizations::EventHandleCache::create( ConstantPointer< ms_windows_EventArray >::createNonlinkedFor( this ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< EventArray > ms_windows_EventArray::createClone() const throw() {
	ms_windows_EventArray *eventArray = new ms_windows_EventArray( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( eventArray, MACROS_FILE_AND_LINE ) );
	return Proxy< EventArray >::createUnique( eventArray );
}

ms_windows_EventArray::ms_windows_EventArray( const ms_windows_EventArray &other ) throw() // other
	:
		_eventContainer( other._eventContainer->createClone() ),
		_setEventFunctor( other._setEventFunctor->createClone() ),
		_resetEventFunctor( other._resetEventFunctor->createClone() ),
		_eventHandleCache( other._eventHandleCache->createClone() )
{}

const ms_windows_EventArray &ms_windows_EventArray::operator =( const ms_windows_EventArray &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "ms_windows_EventArray::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
