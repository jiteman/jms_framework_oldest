#include "ms_windows_Event.h"


#include "jmsf/typing/Boolean.h"

#include "jmsf/pointing/Proxy.inl"
//#include "jmsf/pointing/Proxy.hpp"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {
namespace ms_windows {


void ms_windows_Event::set() throw() {
	::SetEvent( _handle );
}

typing::Boolean ms_windows_Event::isSet() const throw() {
	return typing::Boolean::create( ::WaitForSingleObject( _handle, 0 ) == WAIT_OBJECT_0 );
}

typing::Boolean ms_windows_Event::isNotSet() const throw() {
	return isSet().not();
}

void ms_windows_Event::reset() throw() {
	::ResetEvent( _handle );
}

void ms_windows_Event::wait() const throw() {
	::WaitForSingleObject( _handle, INFINITE );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
HANDLE ms_windows_Event::getHandle() const throw() {
	return _handle;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_Event::~ms_windows_Event() throw() {
	::CloseHandle( _handle );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_Event::ms_windows_Event() throw() {
	_handle = ::CreateEvent( nullptr, true, false, nullptr );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< Event > ms_windows_Event::createClone() const throw() {
	ms_windows_Event *event = new ms_windows_Event( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( event, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< Event >::createUnique( event );
}

ms_windows_Event::ms_windows_Event( const ms_windows_Event & ) throw() // other
{}

const ms_windows_Event &ms_windows_Event::operator =( const ms_windows_Event &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
