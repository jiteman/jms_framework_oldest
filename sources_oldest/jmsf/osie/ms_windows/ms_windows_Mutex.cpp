#include "ms_windows_Mutex.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

void ms_windows_Mutex::lock() throw() {
	::EnterCriticalSection( _criticalSection.get() );
	_isLocked = True;
}

void ms_windows_Mutex::unlock() throw() {
	_isLocked = False;
	::LeaveCriticalSection( _criticalSection.get() );
}

Boolean ms_windows_Mutex::tryToLock() throw() {
	return ::TryEnterCriticalSection( _criticalSection.get() ) != FALSE;
}

Boolean ms_windows_Mutex::isLocked() const throw() {
	return _isLocked;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_Mutex::~ms_windows_Mutex() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_Mutex::ms_windows_Mutex( const Pointer< CRITICAL_SECTION > &criticalSection ) throw()
	:
		_criticalSection( criticalSection )
// 			Pointer< CRITICAL_SECTION >::createUnique(
// 				debugging::static_ObjectCreationLogger< CRITICAL_SECTION >::registerCreation(
// 					new CRITICAL_SECTION, sizeof( CRITICAL_SECTION ), MACROS_FILE_AND_LINE ) ) )
{
	::InitializeCriticalSection( _criticalSection.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< Mutex > ms_windows_Mutex::createClone() const throw() {
	ms_windows_Mutex *mutex = new ms_windows_Mutex( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( mutex, MACROS_FILE_AND_LINE ) );
	return Proxy< Mutex >::createUnique( mutex );
}

ms_windows_Mutex::ms_windows_Mutex( const ms_windows_Mutex & ) throw( Exception ) { // other
	Should::neverViolateCopyingProhibition( "ms_windows_Mutex::ms_windows_Mutex()" );
}

const ms_windows_Mutex &ms_windows_Mutex::operator =( const ms_windows_Mutex &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "ms_windows_Mutex::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
