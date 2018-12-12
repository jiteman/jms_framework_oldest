#include "ms_windows_Mutex.h"


#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/Pointer.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace osie {
namespace ms_windows {

void ms_windows_Mutex::lock() throw() {
	::EnterCriticalSection( _criticalSection.get() );
	_isLocked = typing::True;
}

void ms_windows_Mutex::unlock() throw() {
	_isLocked = typing::False;
	::LeaveCriticalSection( _criticalSection.get() );
}

typing::Boolean ms_windows_Mutex::tryToLock() throw() {
	return typing::Boolean::create( ::TryEnterCriticalSection( _criticalSection.get() ) != FALSE );
}

typing::Boolean ms_windows_Mutex::isLocked() const throw() {
	return _isLocked;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_Mutex::~ms_windows_Mutex() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_Mutex::ms_windows_Mutex( const pointing::Pointer< CRITICAL_SECTION > &criticalSection ) throw()
	:
		_criticalSection( criticalSection )
// 			Pointer< CRITICAL_SECTION >::createUnique(
// 				debugging::static_ObjectCreationLogger< CRITICAL_SECTION >::registerCreation(
// 					new CRITICAL_SECTION, sizeof( CRITICAL_SECTION ), MACROS_FILE_AND_LINE ) ) )
{
	::InitializeCriticalSection( _criticalSection.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< Mutex > ms_windows_Mutex::createClone() const throw() {
	ms_windows_Mutex *mutex = new ms_windows_Mutex( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( mutex, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< Mutex >::createUnique( mutex );
}

ms_windows_Mutex::ms_windows_Mutex( const ms_windows_Mutex & ) throw( validating::Exception ) { // other
	validating::Should::neverViolateCopyingProhibition( "ms_windows_Mutex::ms_windows_Mutex()", FILE_AND_LINE );
}

const ms_windows_Mutex &ms_windows_Mutex::operator =( const ms_windows_Mutex &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	// copy
	validating::Should::neverViolateCopyingProhibition( "ms_windows_Mutex::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
