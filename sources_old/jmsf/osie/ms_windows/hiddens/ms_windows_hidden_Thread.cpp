#include "ms_windows_hidden_Thread.h"


#include "jmsf/osie/exceptions/exception_PriorityLevelIsOutOfRange.h"
#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/texting/TextStream.h"
#include "jmsf/texting/TextString.h"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/Pointer.inl"


namespace jmsf {
namespace osie {
namespace ms_windows {
namespace hiddens {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void ms_windows_hidden_Thread::setPriority( const typing::Natural priorityLevel ) throw( validating::Exception ) {
	::SetThreadPriority( _ms_windows_hidden_ThreadHandle, getPriorityLevelValue( priorityLevel ) );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_hidden_Thread::~ms_windows_hidden_Thread() throw() {
	::CloseHandle( _ms_windows_hidden_ThreadHandle );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
pointing::Pointer< osie::hiddens::hidden_Thread > ms_windows_hidden_Thread::create( HANDLE threadHandle, const DWORD threadId ) throw() {
	osie::hiddens::hidden_Thread *hiddenThread = new ms_windows_hidden_Thread( threadHandle, threadId );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( hiddenThread, MACROS_FILE_AND_LINE ) );
	return pointing::Pointer< osie::hiddens::hidden_Thread >::createUnique( hiddenThread );
}

ms_windows_hidden_Thread::ms_windows_hidden_Thread( HANDLE threadHandle, const DWORD threadId ) throw()
	:
		_ms_windows_hidden_ThreadId( threadId )
{
	_ms_windows_hidden_ThreadHandle = threadHandle;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Pointer< osie::hiddens::hidden_Thread > ms_windows_hidden_Thread::createClone() const throw() {
	osie::hiddens::hidden_Thread *hiddenThread = new ms_windows_hidden_Thread( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( hiddenThread, MACROS_FILE_AND_LINE ) );
	return pointing::Pointer< osie::hiddens::hidden_Thread >::createUnique( hiddenThread );
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
int ms_windows_hidden_Thread::getPriorityLevelValue( const typing::Natural priorityLevel ) throw( validating::Exception ) {
	if ( priorityLevel > typing::Natural::create( 6 ) ) {
		pointing::Proxy< texting::TextStream > textStream = texting::factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "ms_windows_ThreadLauncher::getPriorityLevelValue() - priority level = " ) );
		textStream->putNatural( priorityLevel );
		throw exceptions::exception_PriorityLevelIsOutOfRange( textStream, FILE_AND_LINE );
	}

	if ( priorityLevel == typing::Natural::create( 6 ) ) {
		return THREAD_PRIORITY_TIME_CRITICAL;
	} else if ( priorityLevel == typing::Natural::create( 5 ) ) {
		return THREAD_PRIORITY_HIGHEST;
	} else if ( priorityLevel == typing::Natural::create( 4 ) ) {
		return THREAD_PRIORITY_ABOVE_NORMAL;
	} else if ( priorityLevel == typing::Natural::create( 3 ) ) {
		return THREAD_PRIORITY_NORMAL;
	} else if ( priorityLevel == typing::Natural::create( 2 ) ) {
		return THREAD_PRIORITY_BELOW_NORMAL;
	} else if ( priorityLevel == typing::Natural::create( 1 ) ) {
		return THREAD_PRIORITY_LOWEST;
	} else { // if ( priorityLevel == typing::Natural::create( 0 ) {
		return THREAD_PRIORITY_IDLE;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace hiddens
} // namespace ms_windows
} // namespace osie
} // namespace jmsf
