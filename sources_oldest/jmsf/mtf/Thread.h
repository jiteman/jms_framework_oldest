#pragma once

#include "jmsf/osie/osie_Thread.h"
#include "jmsf/Object.h"

#include "Runnable.hxx"
#include "exceptions/RunnableExceptionInformation.hxx"
#include "jmsf/osie/Event.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"
#include "realizations/realization_factory_Multithreading.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace mtf {

class JMSF_DLL_INTERFACE Thread :
	public virtual osie::osie_Thread,
	public virtual ::jmsf::Object
{

public:
	virtual void registerRunnable( Pointer< Runnable > runnable ) throw( Exception ) = 0;

	virtual void launch() throw( Exception ) = 0;
	virtual void resume() throw() = 0;
	virtual void suspend() throw() = 0;
	virtual void resumeNestedThreads() throw() = 0;
	virtual void suspendNestedThreads() throw() = 0;

protected: friend realizations::realization_factory_Multithreading;
	virtual void automaticResumeNestedThreads() throw() = 0;
	virtual void automaticSuspendNestedThreads() throw() = 0;
	virtual void terminateNestedThreads() throw() = 0;

public:
	virtual void terminate() throw() = 0;

	virtual Proxy< osie::Event > &takeSuspendEvent() throw() = 0;
	virtual Proxy< osie::Event > &takeTerminateEvent() throw() = 0;
 	virtual Proxy< osie::Event > &takeIsSuspendedEvent() throw() = 0;
 	virtual Proxy< osie::Event > &takeIsTerminatedEvent() throw() = 0;

	virtual const ConstantProxy< osie::Event > &getLastOccuredEvent() const throw() = 0;

	virtual void waitTillIsSuspended() const throw() = 0;
	virtual void waitTillNestedThreadsAreSuspended() const throw() = 0;
	virtual void waitTillTerminatingIsCompleted() const throw() = 0;

	virtual void appendWaitableEvent( Proxy< osie::Event > waitableEvent ) throw() = 0;
	virtual void appendNestedThread( Proxy< Thread > nestedThread ) throw() = 0;
	
	virtual void clearExceptionInformation() throw() = 0;
	virtual const Boolean wasExceptionOccured() const throw() = 0;
	virtual const ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > &getExceptionInformationContainer() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals osie_Thread
	void runThread() throw() = 0;
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Thread *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< Thread > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
