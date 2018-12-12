#include "ms_windows_Stopwatch.h"


#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"
#include "jmsf/typing/ShortReal.h"

#include "ms_windows_include.h"


namespace jmsf {
namespace osie {
namespace ms_windows {


typing::Boolean ms_windows_Stopwatch::isSupported() const throw() {
	return _isSupported;
}

typing::LongInteger ms_windows_Stopwatch::getFrequency() throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return _frequency;
}

static typing::LongInteger static_getHighResolutionStopwatchCounts() throw() {
	LARGE_INTEGER currentCounterValue = {};
	::QueryPerformanceCounter( &currentCounterValue );
	return typing::LongInteger::create( currentCounterValue.QuadPart );
}

typing::LongInteger ms_windows_Stopwatch::getCounts() const throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return static_getHighResolutionStopwatchCounts();
}

void ms_windows_Stopwatch::restartTiming() throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	_start = static_getHighResolutionStopwatchCounts();
}

typing::LongInteger ms_windows_Stopwatch::countSplitCounts( const typing::LongInteger time ) const throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return time - _start;
}

typing::LongInteger ms_windows_Stopwatch::getSplitCounts() const throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return countSplitCounts( getCounts() );
}

typing::ShortReal ms_windows_Stopwatch::getSplitCountsInSeconds() const throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return getCountsInSeconds( getSplitCounts() );
}

typing::ShortReal ms_windows_Stopwatch::getCountsInSeconds( const typing::LongInteger counts ) const throw( validating::Exception ) {
	validating::Should::alwaysBe( isSupported(), FILE_AND_LINE );
	return typing::ShortReal::create( static_cast< typing::internals::platform_short_real >( counts.getPlatformValue() ) ) / typing::ShortReal::create( static_cast< typing::internals::platform_short_real >( _frequency.getPlatformValue() ) );
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
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< Stopwatch > ms_windows_Stopwatch::createClone() const throw() {
	ms_windows_Stopwatch *stopwatch = new ms_windows_Stopwatch( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( stopwatch, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< Stopwatch >::createUnique( stopwatch );
}

ms_windows_Stopwatch::ms_windows_Stopwatch( const ms_windows_Stopwatch &other ) throw() // other
	:
		_frequency( other._frequency ),
		_isSupported( other._isSupported )
{}

const ms_windows_Stopwatch &ms_windows_Stopwatch::operator =( const ms_windows_Stopwatch &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	validating::Should::neverViolateCopyingProhibition( "ms_windows_Stopwatch::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
typing::LongInteger ms_windows_Stopwatch::static_getHighResolutionStopwatchFrequency() throw() {
	LARGE_INTEGER frequency = {};
	::QueryPerformanceFrequency( &frequency );
	return typing::LongInteger::create( frequency.QuadPart );	
}

// static
typing::Boolean ms_windows_Stopwatch::static_isHighResolutionStopwatchSupported() throw() {
	LARGE_INTEGER frequency = {};
	return typing::Boolean::create( ::QueryPerformanceFrequency( &frequency ) != 0 );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
