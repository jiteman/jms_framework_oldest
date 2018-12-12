#include "realization_Thread.h"
#include "../Runnable.h"
#include "../exceptions/RunnableExceptionInformation.h"
#include "../exceptions/exception_RunnableIsAlreadyRegisteredForThisThread.h"
#include "../exceptions/exception_RunnableException.h"
#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/osie/osie_Thread.h"
#include "jmsf/assists/Functors.hpp"
#include "jmsf/assists/DoForEvery.hpp"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"


namespace jmsf {
namespace mtf {
namespace realizations {


void realization_Thread::registerRunnable( Pointer< Runnable > runnable ) throw( Exception ) {
	if ( _runnable.isNotEmpty() ) {
		throw exceptions::exception_RunnableIsAlreadyRegisteredForThisThread( CONSTANT_TEXT_STRING( "realization_Thread::registerRunnable()" ) );
	}

	_runnable = runnable;
}

void realization_Thread::launch() throw( Exception ) {
	Should::neverBeNull( _runnable.get() );
	Pointer< osie::osie_Thread > thisThread = Pointer< osie::osie_Thread >::createNonlinkedFor( this );
	osie::factory_OperatingSystem::instance()->getMultithreadingControl()->launchThread( thisThread, _priorityLevel );
	doForEvery( _nestedThreadContainer, _automaticLaunchNestedThreadsFunctor );
}

void realization_Thread::resume() throw() {
	_isSuspendedEvent->reset();
	_suspendEvent->reset();
	_resumeEvent->set();
	doForEvery( _nestedThreadContainer, _automaticResumeNestedThreadsFunctor );
}

void realization_Thread::suspend() throw() {
	doForEvery( _nestedThreadContainer, _automaticSuspendNestedThreadsFunctor );
	_resumeEvent->reset();
	_suspendEvent->set();
}

void realization_Thread::resumeNestedThreads() throw() {
	doForEvery( _nestedThreadContainer, _resumeNestedThreadsFunctor );
}

void realization_Thread::suspendNestedThreads() throw() {
	doForEvery( _nestedThreadContainer, _suspendNestedThreadsFunctor );
}

void realization_Thread::automaticResumeNestedThreads() throw() {
	if ( _isAutostopEnable ) return;

	resume();
}

void realization_Thread::automaticSuspendNestedThreads() throw() {
	if ( _isAutostopEnable ) return;

	suspend();
}

void realization_Thread::terminateNestedThreads() throw() {
	doForEvery( _nestedThreadContainer, _terminateThreadFunctor );
}

void realization_Thread::terminate() throw() {
	doForEvery( _nestedThreadContainer, _terminateNestedThreadsFunctor );
	_terminateEvent->set();
}

Proxy< osie::Event > &realization_Thread::takeSuspendEvent() throw() {
	return _suspendEvent;
}

Proxy< osie::Event > &realization_Thread::takeTerminateEvent() throw() {
	return _terminateEvent;
}

Proxy< osie::Event > &realization_Thread::takeIsSuspendedEvent() throw() {
	return _isSuspendedEvent;
}

Proxy< osie::Event > &realization_Thread::takeIsTerminatedEvent() throw() {
	return _isTerminatedEvent;
}

const ConstantProxy< osie::Event > &realization_Thread::getLastOccuredEvent() const throw() {
	return _lastOccuredEvent;
}

void realization_Thread::waitTillIsSuspended() const throw() {
	if ( _isAutostopEnable.not() ) {
		waitTillNestedThreadsAreSuspended();
	}

	_isSuspendedEvent->wait();
}

void realization_Thread::waitTillNestedThreadsAreSuspended() const throw() {
	_areNestedThreadsSuspendedEventContainer->waitForAllEvents();
}

void realization_Thread::waitTillTerminatingIsCompleted() const throw() {
	_areNestedThreadsTerminatedEventContainer->waitForAllEvents();
	_isTerminatedEvent->wait();
}

void realization_Thread::appendWaitableEvent( Proxy< osie::Event > waitableEvent ) throw() {
	_waitableEventContainer->appendEvent( waitableEvent );
}

void realization_Thread::appendNestedThread( Proxy< Thread > nestedThread ) throw() {
	_areNestedThreadsSuspendedEventContainer->appendEvent( nestedThread->takeIsSuspendedEvent().getNonlinked() );
	_areNestedThreadsTerminatedEventContainer->appendEvent( nestedThread->takeIsTerminatedEvent().getNonlinked() );
	_nestedThreadContainer->appendBack( nestedThread );
}
	
void realization_Thread::clearExceptionInformation() throw() {
	_exceptionInformationContainer->clear();
}

const Boolean realization_Thread::wasExceptionOccured() const throw() {
	return _exceptionInformationContainer->isNotEmpty();
}

const ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > &realization_Thread::getExceptionInformationContainer() const throw() {
	return _exceptionInformationContainerConstantReferenceToReturn;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_Thread::runThread() throw() {
	Proxy< osie::EventArray > waitableEvents = osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray();
	waitableEvents->appendEvent( _terminateEvent.getNonlinked() );
	waitableEvents->appendEvent( _suspendEvent.getNonlinked() );
	waitableEvents->appendEventArray( _waitableEventContainer.getNonlinked() );

	for ( ;; ) {
		Boolean wasErrorOccured = False;

		try {
			_lastOccuredEvent = waitableEvents->waitForAnyEventThenGetIt();

			if ( _lastOccuredEvent == _terminateEvent ) {
				suspend();
				waitTillNestedThreadsAreSuspended();
				terminate();
				waitTillTerminatingIsCompleted();
				return;
			}

			if ( _lastOccuredEvent == _suspendEvent ) {
				suspend();
				waitTillNestedThreadsAreSuspended();
				continue;
			}

			if ( _runnable.isEmpty() ) {
				Pointer< exceptions::RunnableExceptionInformation > runnableExceptionInformation = exceptions::RunnableExceptionInformation::create( CONSTANT_TEXT_STRING( "realization_Thread::runThread() - runnable is empty" ) );
				_exceptionInformationContainer->appendBack( runnableExceptionInformation.takeConstant() );
				return;
			} 

			try {
				_runnable->run();
			} catch ( const exceptions::exception_RunnableException &catchedRunnableException ) {				
				Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
				textStream->put( CONSTANT_TEXT_STRING( "EventTriggeringRunnable::runThread() - continuing: " ) )->put( catchedRunnableException.getReason() );
				Pointer< exceptions::RunnableExceptionInformation > runnableExceptionInformation = exceptions::RunnableExceptionInformation::create( textStream );
				_exceptionInformationContainer->appendBack( runnableExceptionInformation.takeConstant() );
			} catch ( const Exception &catchedException ) {
				Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
				textStream->put( CONSTANT_TEXT_STRING( "EventTriggeringRunnable::runThread() - continuing: " ) )->put( catchedException.getReason() );
				Pointer< exceptions::RunnableExceptionInformation > runnableExceptionInformation = exceptions::RunnableExceptionInformation::create( textStream );
				_exceptionInformationContainer->appendBack( runnableExceptionInformation.takeConstant() );
			}
		} catch ( const Exception &catchedException ) {
			Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
			textStream->put( CONSTANT_TEXT_STRING( "EventTriggeringRunnable::runThread() - continuing: " ) )->put( catchedException.getReason() );
			Pointer< exceptions::RunnableExceptionInformation > runnableExceptionInformation = exceptions::RunnableExceptionInformation::create( textStream );
			_exceptionInformationContainer->appendBack( runnableExceptionInformation.takeConstant() );
			wasErrorOccured = true;
		}

		if ( _isAutostopEnable || wasErrorOccured ) {
			suspend();
			waitTillNestedThreadsAreSuspended();
		}	

		if ( wasErrorOccured ) {
// 			suspend();
// 			waitTillNestedThreadsAreSuspended();
			terminate();
			waitTillTerminatingIsCompleted();
			return;
		}
	}
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Thread::~realization_Thread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Thread::realization_Thread(
		const natural_size priorityLevel,
		Proxy< osie::Event > resumeEvent,
		Proxy< osie::Event > isSuspendedEvent,
		Proxy< osie::Event > terminateEvent,
		Proxy< osie::Event > suspendEvent,
		Proxy< osie::Event > isTerminatedEvent,
		Proxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > exceptionInformationContainer,
		Proxy< osie::EventArray > waitableEventContainer,
		Proxy< osie::EventArray > areNestedThreadsSuspendedEventContainer,
		Proxy< osie::EventArray > areNestedThreadsTerminatedEventContainer,
		Proxy< Container< Proxy< Thread > > > nestedThreadContainer,
		Boolean isAutostopEnable,
		Proxy< assists::Functor< Proxy< Thread > > > automaticLaunchNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > resumeThreadFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > suspendThreadFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > terminateThreadFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > resumeNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > suspendNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > automaticResumeNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > automaticSuspendNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > terminateNestedThreadsFunctor ) throw()
	:
		_resumeEvent( resumeEvent ),
		_isSuspendedEvent( isSuspendedEvent ),
		_terminateEvent( terminateEvent ),
		_suspendEvent( suspendEvent ),
		_isTerminatedEvent( isTerminatedEvent ),
		_exceptionInformationContainer( exceptionInformationContainer ),
		_waitableEventContainer( waitableEventContainer ),
		_areNestedThreadsSuspendedEventContainer( areNestedThreadsSuspendedEventContainer ),
		_areNestedThreadsTerminatedEventContainer( areNestedThreadsTerminatedEventContainer ),
		_nestedThreadContainer( nestedThreadContainer ),
		_isAutostopEnable( isAutostopEnable ),
		_automaticLaunchNestedThreadsFunctor( automaticLaunchNestedThreadsFunctor ),
		_resumeThreadFunctor( resumeThreadFunctor ),
		_suspendThreadFunctor( suspendThreadFunctor ),
		_terminateThreadFunctor( terminateThreadFunctor ),
		_resumeNestedThreadsFunctor( resumeNestedThreadsFunctor ),
		_suspendNestedThreadsFunctor( suspendNestedThreadsFunctor ),
		_terminateNestedThreadsFunctor( terminateNestedThreadsFunctor ),
		_automaticResumeNestedThreadsFunctor( automaticResumeNestedThreadsFunctor ),
		_automaticSuspendNestedThreadsFunctor( automaticSuspendNestedThreadsFunctor )
{
	_priorityLevel = priorityLevel;
	_exceptionInformationContainerConstantReferenceToReturn = _exceptionInformationContainer.getNonlinkedConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< Thread > realization_Thread::createClone() const throw() {
	realization_Thread *thread = new realization_Thread( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( thread, MACROS_FILE_AND_LINE ) );
	return Proxy< Thread >::createUnique( thread );
}

realization_Thread::realization_Thread( const realization_Thread & ) throw() // other
{}

const realization_Thread &realization_Thread::operator =( const realization_Thread &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_Thread::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
