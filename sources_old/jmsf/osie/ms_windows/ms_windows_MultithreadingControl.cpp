#include "ms_windows_MultithreadingControl.h"
#include "ms_windows_Event.h"
#include "ms_windows_EventArray.h"
#include "ms_windows_Mutex.h"
#include "hiddens/ms_windows_hidden_Thread.h"
#include "jmsf/osie/exceptions/exception_PriorityLevelIsOutOfRange.h"
#include "jmsf/osie/exceptions/exception_UnableToCreateThread.h"
#include "jmsf/osie/osie_Thread.h"

#include "jmsf/containing/factory_Container.inl"
#include "jmsf/texting/factory_TextObject.h"

#include "jmsf/texting/TextStream.h"
#include "jmsf/texting/TextString.h"

#include "jmsf/assisting/flyweight_factory_Functor.inl"
#include "jmsf/assisting/Functor.inl"

#include "jmsf/pointing/Proxy.inl"

#include "jmsf/validating/Should.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

pointing::Proxy< Event > ms_windows_MultithreadingControl::createEvent() const throw() {
	ms_windows_Event *event = new ms_windows_Event;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( event, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< Event >::createUnique( event );
}

pointing::Proxy< EventArray > ms_windows_MultithreadingControl::createEventArray() const throw() {
	ms_windows_EventArray *eventArray =
		new ms_windows_EventArray(
			containing::factory_Container< pointing::Proxy< Event > >::instance()->createArray(),
				assisting::flyweight_factory_Functor< pointing::Proxy< Event > >::instance()->createFunctor( &Event::set ),
				assisting::flyweight_factory_Functor< pointing::Proxy< Event > >::instance()->createFunctor( &Event::reset ) );

//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( eventArray, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< EventArray >::createUnique( eventArray );
}

pointing::Proxy< Mutex > ms_windows_MultithreadingControl::createMutex() const throw() {
	CRITICAL_SECTION *criticalSection = new CRITICAL_SECTION;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( criticalSection, MACROS_FILE_AND_LINE ) );
	ms_windows_Mutex *mutex = new ms_windows_Mutex( pointing::Pointer< CRITICAL_SECTION >::createUnique( criticalSection ) );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( mutex, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< Mutex >::createUnique( mutex );
}

// internal
static DWORD WINAPI threadLauncher( void *objectToRun ) throw() {
	if ( objectToRun == nullptr ) return static_cast< DWORD >( -1 );

	osie_Thread *aThread = reinterpret_cast< osie_Thread * >( objectToRun );
	aThread->runThread();
	return 0;
}
//~internal

void ms_windows_MultithreadingControl::launchThread( pointing::Pointer< osie_Thread > aThread, const typing::Natural priorityLevel ) const throw( validating::Exception ) {
	DWORD threadId; // ulongint
//	HANDLE threadHandle = ::CreateThread( nullptr, 0, launcher, reinterpret_cast< void * >( thread.get() ), CREATE_SUSPENDED, &threadId );
	HANDLE threadHandle = ::CreateThread( nullptr, 0, threadLauncher, reinterpret_cast< void * >( aThread.get() ), 0, &threadId );

	if ( threadHandle == nullptr ) {
		pointing::Proxy< texting::TextStream > textStream = texting::factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "ms_windows_ThreadControl::launchThread() - Unable to create thread. GetLastError() = " ) )->putNatural( typing::Natural::create( ::GetLastError() ) );
		throw osie::exceptions::exception_UnableToCreateThread( textStream, FILE_AND_LINE );
	}

	aThread->setHiddenThread( hiddens::ms_windows_hidden_Thread::create( threadHandle, threadId ) );
	aThread->setPriority( priorityLevel );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_MultithreadingControl::~ms_windows_MultithreadingControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_MultithreadingControl::ms_windows_MultithreadingControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< MultithreadingControl > ms_windows_MultithreadingControl::createClone() const throw() {
	ms_windows_MultithreadingControl *multithreadingControl = new ms_windows_MultithreadingControl( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( multithreadingControl, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< MultithreadingControl >::createUnique( multithreadingControl );
}

ms_windows_MultithreadingControl::ms_windows_MultithreadingControl( const ms_windows_MultithreadingControl & ) throw() // other
{}

const ms_windows_MultithreadingControl &ms_windows_MultithreadingControl::operator =( const ms_windows_MultithreadingControl &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	validating::Should::neverViolateCopyingProhibition( "ms_windows_MultithreadingControl::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
// int ms_windows_MultithreadingControl::getPriorityLevelValue( const natural_size priorityLevel ) throw( validating::Exception ) {
// 	if ( priorityLevel > 6 ) {
// 		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
// 		textStream->put( CONSTANT_TEXT_STRING( "ms_windows_ThreadControl::getPriorityLevelValue() - priority level = " ) );
// 		textStream->putNatural( priorityLevel );
// 		throw exceptions::exception_PriorityLevelIsOutOfRange( textStream );
// 	}
// 
// 	switch ( priorityLevel ) {
// 		case 6:
// 			return THREAD_PRIORITY_TIME_CRITICAL;
// 
// 		case 5:
// 			return THREAD_PRIORITY_HIGHEST;
// 
// 		case 4:
// 			return THREAD_PRIORITY_ABOVE_NORMAL;
// 
// 		case 3:
// 			return THREAD_PRIORITY_NORMAL;
// 
// 		case 2:
// 			return THREAD_PRIORITY_BELOW_NORMAL;
// 
// 		case 1:
// 			return THREAD_PRIORITY_LOWEST;
// 
// 		case 0:
// 			return THREAD_PRIORITY_IDLE;
// 
// 		default:
// 			return 0;
// 	}
// }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
