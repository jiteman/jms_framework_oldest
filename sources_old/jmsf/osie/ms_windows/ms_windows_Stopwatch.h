#pragma once


#include "jmsf/osie/Stopwatch.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/typing/Boolean.h"
#include "jmsf/typing/LongInteger.h"
#include "jmsf/validating/Exception.hxx"
#include "ms_windows_UtilityControl.hxx"
#include "../static_factory_OperatingSystemSpecial.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_Stopwatch :
	public Stopwatch,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals Stopwatch
	typing::Boolean isSupported() const throw();
	typing::LongInteger getFrequency() throw( validating::Exception );
	typing::LongInteger getCounts() const throw( validating::Exception );

	void restartTiming() throw( validating::Exception );
	typing::LongInteger countSplitCounts( typing::LongInteger time ) const throw( validating::Exception );
	typing::LongInteger getSplitCounts() const throw( validating::Exception );
	typing::ShortReal getSplitCountsInSeconds() const throw( validating::Exception );

	typing::ShortReal getCountsInSeconds( typing::LongInteger counts ) const throw( validating::Exception );
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
	pointing::Proxy< Stopwatch > createClone() const throw();

private:
	ms_windows_Stopwatch( const ms_windows_Stopwatch &other ) throw();
	const ms_windows_Stopwatch &operator =( const ms_windows_Stopwatch &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static typing::LongInteger static_getHighResolutionStopwatchFrequency() throw();
	static typing::Boolean static_isHighResolutionStopwatchSupported() throw();

private:
	typing::LongInteger _start;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const typing::LongInteger _frequency;
	const typing::Boolean _isSupported;

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
