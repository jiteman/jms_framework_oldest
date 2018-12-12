#pragma once

#include "jmsf/osie/Stopwatch.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Boolean.h"

#include "jmsf/Exception.hxx"
#include "ms_windows_UtilityControl.hxx"
#include "../static_factory_OperatingSystemSpecial.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {

class ms_windows_Stopwatch :
	public Stopwatch,
	public mixins::mixin_Object
{

public:
	// virtuals Stopwatch
	Boolean isSupported() const throw();
	integer_big getFrequency() throw( Exception );
	integer_big getCounts() const throw( Exception );

	void restartTiming() throw( Exception );
	integer_big countSplitCounts( integer_big time ) const throw( Exception );
	integer_big getSplitCounts() const throw( Exception );
	Real getSplitCountsInSeconds() const throw( Exception );

	Real getCountsInSeconds( integer_big counts ) const throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_Stopwatch() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_UtilityControl;
	friend static_factory_OperatingSystemSpecial;
	ms_windows_Stopwatch() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Stopwatch > createClone() const throw();

private:
	ms_windows_Stopwatch( const ms_windows_Stopwatch &other ) throw();
	const ms_windows_Stopwatch &operator =( const ms_windows_Stopwatch &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static integer_big static_getHighResolutionStopwatchFrequency() throw();
	static const Boolean static_isHighResolutionStopwatchSupported() throw();

private:
	integer_big _start;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const integer_big _frequency;
	const Boolean _isSupported;

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
