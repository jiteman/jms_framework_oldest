#pragma once

#include "../Thread.h"
#include "jmsf/osie/mixins/mixin_osie_Thread.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../exceptions/RunnableExceptionInformation.hxx"
#include "jmsf/osie/EventArray.hxx"
#include "jmsf/assists/Functors.hxx"
#include "realization_factory_Multithreading.hxx"


namespace jmsf {
namespace mtf {
namespace realizations {


class realization_Thread :	
	public Thread,
	public osie::mixins::mixin_osie_Thread,
	public mixins::mixin_Object
{

public:
	// virtuals Thread
	void registerRunnable( Pointer< Runnable > runnable ) throw( Exception );

	void launch() throw( Exception );
	void resume() throw();
	void suspend() throw();
	void resumeNestedThreads() throw();
	void suspendNestedThreads() throw();

protected:
	void automaticResumeNestedThreads() throw();
	void automaticSuspendNestedThreads() throw();
	void terminateNestedThreads() throw();

public:
	void terminate() throw();

	Proxy< osie::Event > &takeSuspendEvent() throw();
	Proxy< osie::Event > &takeTerminateEvent() throw();
 	Proxy< osie::Event > &takeIsSuspendedEvent() throw();
 	Proxy< osie::Event > &takeIsTerminatedEvent() throw();

	const ConstantProxy< osie::Event > &getLastOccuredEvent() const throw();

	void waitTillIsSuspended() const throw();
	void waitTillNestedThreadsAreSuspended() const throw();
	void waitTillTerminatingIsCompleted() const throw();	

	void appendWaitableEvent( Proxy< osie::Event > waitableEvent ) throw();
	void appendNestedThread( Proxy< Thread > nestedThread ) throw();
	
	void clearExceptionInformation() throw();
	const Boolean wasExceptionOccured() const throw();
	const ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > &getExceptionInformationContainer() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Thread
	void runThread() throw();
	//~virtuals Thread

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Multithreading;
	realization_Thread(
		natural_size priorityLevel,
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
		Proxy< assists::Functor< Proxy< Thread > > > terminateNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > automaticResumeNestedThreadsFunctor,
		Proxy< assists::Functor< Proxy< Thread > > > automaticSuspendNestedThreadsFunctor ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Thread > createClone() const throw();

private:
	realization_Thread( const realization_Thread &other ) throw();
	const realization_Thread &operator =( const realization_Thread &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< Runnable > _runnable;

	Proxy< osie::Event > _resumeEvent;
	Proxy< osie::Event > _isSuspendedEvent;
	Proxy< osie::Event > _terminateEvent;
	Proxy< osie::Event > _suspendEvent;
	Proxy< osie::Event > _isTerminatedEvent;

	const Boolean _isAutostopEnable;
	ConstantProxy< osie::Event > _lastOccuredEvent;
	Proxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > _exceptionInformationContainer;
	ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > _exceptionInformationContainerConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	natural_size _priorityLevel;
	Proxy< osie::EventArray > _waitableEventContainer;
	natural_size _minimalWaitableEventQuantity;

	Proxy< Container< Proxy< Thread > > > _nestedThreadContainer;

	Proxy< osie::EventArray > _areNestedThreadsSuspendedEventContainer;
	Proxy< osie::EventArray > _areNestedThreadsTerminatedEventContainer;

	Proxy< assists::Functor< Proxy< Thread > > > _automaticLaunchNestedThreadsFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _resumeThreadFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _suspendThreadFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _terminateThreadFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _resumeNestedThreadsFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _suspendNestedThreadsFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _automaticResumeNestedThreadsFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _automaticSuspendNestedThreadsFunctor;
	Proxy< assists::Functor< Proxy< Thread > > > _terminateNestedThreadsFunctor;

};


} // namespace
}
}
