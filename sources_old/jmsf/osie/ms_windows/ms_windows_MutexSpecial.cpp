#include "ms_windows_MutexSpecial.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

void ms_windows_MutexSpecial::lock() throw() {
	::EnterCriticalSection( _criticalSection.get() );
	_isLocked = True;
}

void ms_windows_MutexSpecial::unlock() throw() {
	_isLocked = False;
	::LeaveCriticalSection( _criticalSection.get() );
}

Boolean ms_windows_MutexSpecial::tryToLock() throw() {
	return ::TryEnterCriticalSection( _criticalSection.get() ) != FALSE;
}

Boolean ms_windows_MutexSpecial::isLocked() const throw() {
	return _isLocked;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_MutexSpecial::~ms_windows_MutexSpecial() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_MutexSpecial::ms_windows_MutexSpecial( const AutomaticPointer< CRITICAL_SECTION > &criticalSection ) throw()
	:
		_criticalSection( criticalSection )
// 			Pointer< CRITICAL_SECTION >::createUnique(
// 				debugging::static_ObjectCreationLogger< CRITICAL_SECTION >::registerCreation(
// 					new CRITICAL_SECTION, sizeof( CRITICAL_SECTION ), MACROS_FILE_AND_LINE ) ) )
{
	::InitializeCriticalSection( _criticalSection.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< Mutex > ms_windows_MutexSpecial::createClone() const throw() {
	ms_windows_MutexSpecial *mutex = new ms_windows_MutexSpecial( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( mutex, MACROS_FILE_AND_LINE ) );
	return Proxy< Mutex >::createUnique( mutex );
}

ms_windows_MutexSpecial::ms_windows_MutexSpecial( const ms_windows_MutexSpecial & ) throw( validating::Exception ) { // other
	Should::neverViolateCopyingProhibition( "ms_windows_MutexSpecial::ms_windows_MutexSpecial()" );
}

const ms_windows_MutexSpecial &ms_windows_MutexSpecial::operator =( const ms_windows_MutexSpecial &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "ms_windows_MutexSpecial::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
