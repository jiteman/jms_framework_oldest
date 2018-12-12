#include "ms_windows_hidden_Thread.h"
#include "jmsf/osie/exceptions/exception_PriorityLevelIsOutOfRange.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {
namespace hiddens {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void ms_windows_hidden_Thread::setPriority( const natural_size priorityLevel ) throw( Exception ) {
	::SetThreadPriority( _ms_windows_hidden_ThreadHandle, getPriorityLevelValue( priorityLevel ) );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_hidden_Thread::~ms_windows_hidden_Thread() throw() {
	::CloseHandle( _ms_windows_hidden_ThreadHandle );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Pointer< osie::hiddens::hidden_Thread > ms_windows_hidden_Thread::create( HANDLE threadHandle, const DWORD threadId ) throw() {
	osie::hiddens::hidden_Thread *hiddenThread = new ms_windows_hidden_Thread( threadHandle, threadId );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( hiddenThread, MACROS_FILE_AND_LINE ) );
	return Pointer< osie::hiddens::hidden_Thread >::createUnique( hiddenThread );
}

ms_windows_hidden_Thread::ms_windows_hidden_Thread( HANDLE threadHandle, const DWORD threadId ) throw()
	:
		_ms_windows_hidden_ThreadId( threadId )
{
	_ms_windows_hidden_ThreadHandle = threadHandle;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointer< osie::hiddens::hidden_Thread > ms_windows_hidden_Thread::createClone() const throw() {
	osie::hiddens::hidden_Thread *hiddenThread = new ms_windows_hidden_Thread( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( hiddenThread, MACROS_FILE_AND_LINE ) );
	return Pointer< osie::hiddens::hidden_Thread >::createUnique( hiddenThread );
}

ms_windows_hidden_Thread::ms_windows_hidden_Thread( const ms_windows_hidden_Thread & ) throw() // other
	:
		_ms_windows_hidden_ThreadId( 0 )
{}

const ms_windows_hidden_Thread &ms_windows_hidden_Thread::operator =( const ms_windows_hidden_Thread &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
int ms_windows_hidden_Thread::getPriorityLevelValue( const natural_size priorityLevel ) throw( Exception ) {
	if ( priorityLevel > 6 ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "ms_windows_ThreadLauncher::getPriorityLevelValue() - priority level = " ) );
		textStream->putNatural( priorityLevel );
		throw exceptions::exception_PriorityLevelIsOutOfRange( textStream );
	}

	switch ( priorityLevel ) {
		case 6:
			return THREAD_PRIORITY_TIME_CRITICAL;

		case 5:
			return THREAD_PRIORITY_HIGHEST;

		case 4:
			return THREAD_PRIORITY_ABOVE_NORMAL;

		case 3:
			return THREAD_PRIORITY_NORMAL;

		case 2:
			return THREAD_PRIORITY_BELOW_NORMAL;

		case 1:
			return THREAD_PRIORITY_LOWEST;

		case 0:
			return THREAD_PRIORITY_IDLE;

		default:
			return THREAD_PRIORITY_NORMAL;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace hiddens
} // namespace ms_windows
} // namespace osie
} // namespace jmsf
