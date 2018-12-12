#include "realization_factory_Multithreading.h"
#include "realization_Thread.h"
#include "../exceptions/RunnableExceptionInformation.h"
#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/assists/flyweight_factory_Functor.hpp"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace mtf {
namespace realizations {

Proxy< Thread > realization_factory_Multithreading::createThread( const natural_size priorityLevel, const Boolean isAutostopEnable ) const throw() {
	realization_Thread *thread =
		new realization_Thread(
			priorityLevel,
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			factory_Container< ConstantPointer< exceptions::RunnableExceptionInformation > >::instance()->createArray(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray(),
			factory_Container< Proxy< Thread > >::instance()->createArray(),
			isAutostopEnable,
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::launch ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::resume ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::suspend ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::terminate ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::resumeNestedThreads ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::suspendNestedThreads ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::terminateNestedThreads ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::automaticResumeNestedThreads ),
			assists::flyweight_factory_Functor< Proxy< Thread > >::instance()->createFunctor( &Thread::automaticSuspendNestedThreads ) );

	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( thread, MACROS_FILE_AND_LINE ) );
	return Proxy< Thread >::createUnique( thread );
}

Proxy< Thread > realization_factory_Multithreading::createContinuousThread() const throw() {
	return createThread( 5, False );
}

Proxy< Thread > realization_factory_Multithreading::createContinuousThread( const natural_size priorityLevel ) const throw() {
	return createThread( priorityLevel, False );
}

Proxy< Thread > realization_factory_Multithreading::createAutostopableThread() const throw() {
	return createThread( 5, True );
}

Proxy< Thread > realization_factory_Multithreading::createAutostopableThread( const natural_size priorityLevel ) const throw() {
	return createThread( priorityLevel, True );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_Multithreading::~realization_factory_Multithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Multithreading::realization_factory_Multithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_Multithreading::realization_factory_Multithreading( const realization_factory_Multithreading & ) throw() // other
{}

const realization_factory_Multithreading &realization_factory_Multithreading::operator =( const realization_factory_Multithreading &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_factory_Multithreading::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
