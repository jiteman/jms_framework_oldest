#include "../static_factory_OperatingSystemSpecial.h"
#include "ms_windows_Mutex.h"
#include "ms_windows_MutexSpecial.h"
#include "ms_windows_Stopwatch.h"
#include "jmsf/AutomaticPointer.hpp"
//#include "jmsf/debugging/MemoryUsingLogging.h"

namespace jmsf {
namespace osie {

// static
AutomaticPointer< Stopwatch > static_factory_OperatingSystemSpecial::createAutomaticStopwatch() throw() {
	return AutomaticPointer< Stopwatch >( new ms_windows::ms_windows_Stopwatch );
}

// static
AutomaticPointer< Mutex > static_factory_OperatingSystemSpecial::createAutomaticMutex() throw() {
	CRITICAL_SECTION *criticalSection = new CRITICAL_SECTION;
	Mutex *mutex = new ms_windows::ms_windows_MutexSpecial( AutomaticPointer< CRITICAL_SECTION >( criticalSection ) );
	return AutomaticPointer< Mutex >( mutex );
}

// static
Mutex *static_factory_OperatingSystemSpecial::takeOperatingSystemMutex() throw() {
	if ( _static_operatingSystemMutex.get() == nullptr ) {
		initialize();
	}

	return _static_operatingSystemMutex.get();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void static_factory_OperatingSystemSpecial::initialize() throw() {
	if ( _static_operatingSystemMutex.get() == nullptr ) {
		_static_operatingSystemMutex = createAutomaticMutex();
//		_static_operatingSystemMutex.set( new ms_windows::ms_windows_Mutex( Pointer< CRITICAL_SECTION >::createUnique( new CRITICAL_SECTION ) ) );
	}
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
static_factory_OperatingSystemSpecial::~static_factory_OperatingSystemSpecial() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_factory_OperatingSystemSpecial::static_factory_OperatingSystemSpecial() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_factory_OperatingSystemSpecial::static_factory_OperatingSystemSpecial( const static_factory_OperatingSystemSpecial & ) throw() // other
{}

const static_factory_OperatingSystemSpecial &static_factory_OperatingSystemSpecial::operator =( const static_factory_OperatingSystemSpecial &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
AutomaticPointer< Mutex > static_factory_OperatingSystemSpecial::_static_operatingSystemMutex;

} // namespace osie
} // namespace jmsf
