#include "Thread.h"
#include "Runnable.h"
#include "exceptions/RunnableExceptionInformation.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/mixins/null_mixin_osie_Thread.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace mtf {


class null_Thread :	
	public Thread,
	public osie::mixins::null_mixin_osie_Thread,
	public mixins::mixin_null_Object,
	public Singleton< null_Thread >
{

public:
	// virtuals Thread
	void registerRunnable( Pointer< Runnable >  ) throw( Exception ) {} // runnable
	void launch() throw( Exception ) {}
	void resume() throw() {}
	void suspend() throw() {}
	void resumeNestedThreads() throw() {}
	void suspendNestedThreads() throw() {}

protected:
	void automaticResumeNestedThreads() throw() {}
	void automaticSuspendNestedThreads() throw() {}
	void terminateNestedThreads() throw() {}

public:
	void terminate() throw() {}

	Proxy< osie::Event > &takeSuspendEvent() throw() {
		return _eventReferenceToReturn;
	}

	Proxy< osie::Event > &takeTerminateEvent() throw() {
		return _eventReferenceToReturn;
	}

 	Proxy< osie::Event > &takeIsSuspendedEvent() throw() {
		return _eventReferenceToReturn;
	}

 	Proxy< osie::Event > &takeIsTerminatedEvent() throw() {
		return _eventReferenceToReturn;
	}

	const ConstantProxy< osie::Event > &getLastOccuredEvent() const throw() {
		return _eventConstantReferenceToReturn;
	}

	void waitTillIsSuspended() const throw() {}
	void waitTillNestedThreadsAreSuspended() const throw() {}
	void waitTillTerminatingIsCompleted() const throw() {}

	void appendWaitableEvent( Proxy< osie::Event >  ) throw() {} // waitableEvent
	void appendNestedThread( Proxy< Thread >  ) throw() {} // nestedThread
	
	void clearExceptionInformation() throw() {}

	const Boolean wasExceptionOccured() const throw() {
		return False;
	}

	const ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > &getExceptionInformationContainer() const throw() {
		return _runnableExceptionInformationContainerReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Thread
	void runThread() throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Thread() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Thread >;
	static null_Thread *createInstance() throw() {
		null_Thread *nullThread = new null_Thread;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullThread, MACROS_FILE_AND_LINE ) );
		return nullThread;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Thread() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Thread > createClone() const throw() {
		return Proxy< Thread >::createUnique( this );
	}

private:
	null_Thread( const null_Thread & ) throw() {} // other
	
	const null_Thread &operator =( const null_Thread &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Thread::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< osie::Event > _eventReferenceToReturn;
	ConstantProxy< osie::Event > _eventConstantReferenceToReturn;
	ConstantProxy< Container< ConstantPointer< exceptions::RunnableExceptionInformation > > > _runnableExceptionInformationContainerReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Thread *Thread::getNull() throw() {
	return null_Thread::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
