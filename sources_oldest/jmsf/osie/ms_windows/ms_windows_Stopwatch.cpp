#include "ms_windows_Stopwatch.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/Real.h"
#include "jmsf/debugging/ObjectCreationLogging.h"
#include "ms_windows_include.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

Boolean ms_windows_Stopwatch::isSupported() const throw() {
	return _isSupported;
}

integer_big ms_windows_Stopwatch::getFrequency() throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return _frequency;
}

static integer_big static_getHighResolutionStopwatchCounts() throw() {
	LARGE_INTEGER currentCounterValue = {};
	::QueryPerformanceCounter( &currentCounterValue );
	return currentCounterValue.QuadPart;
}

integer_big ms_windows_Stopwatch::getCounts() const throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return static_getHighResolutionStopwatchCounts();
}

void ms_windows_Stopwatch::restartTiming() throw( Exception ) {
	Should::alwaysBe( isSupported() );
	_start = static_getHighResolutionStopwatchCounts();
}

integer_big ms_windows_Stopwatch::countSplitCounts( const integer_big time ) const throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return time - _start;
}

integer_big ms_windows_Stopwatch::getSplitCounts() const throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return countSplitCounts( getCounts() );
}

Real ms_windows_Stopwatch::getSplitCountsInSeconds() const throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return getCountsInSeconds( getSplitCounts() );
}

Real ms_windows_Stopwatch::getCountsInSeconds( const integer_big counts ) const throw( Exception ) {
	Should::alwaysBe( isSupported() );
	return Real( static_cast< real >( counts ) ) / Real( static_cast< real >( _frequency ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_Stopwatch::~ms_windows_Stopwatch() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_Stopwatch::ms_windows_Stopwatch() throw()
	:
		_frequency( static_getHighResolutionStopwatchFrequency() ),
		_isSupported( static_isHighResolutionStopwatchSupported() )
{
	_start = integer_big( 0 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< Stopwatch > ms_windows_Stopwatch::createClone() const throw() {
	ms_windows_Stopwatch *stopwatch = new ms_windows_Stopwatch( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( stopwatch, MACROS_FILE_AND_LINE ) );
	return Proxy< Stopwatch >::createUnique( stopwatch );
}

ms_windows_Stopwatch::ms_windows_Stopwatch( const ms_windows_Stopwatch &other ) throw() // other
	:
		_frequency( other._frequency ),
		_isSupported( other._isSupported )
{}

const ms_windows_Stopwatch &ms_windows_Stopwatch::operator =( const ms_windows_Stopwatch &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_Stopwatch::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
integer_big ms_windows_Stopwatch::static_getHighResolutionStopwatchFrequency() throw() {
	LARGE_INTEGER frequency = {};
	::QueryPerformanceFrequency( &frequency );
	return frequency.QuadPart;	
}

// static
const Boolean ms_windows_Stopwatch::static_isHighResolutionStopwatchSupported() throw() {
	LARGE_INTEGER frequency = {};
	return ::QueryPerformanceFrequency( &frequency ) != 0;	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
