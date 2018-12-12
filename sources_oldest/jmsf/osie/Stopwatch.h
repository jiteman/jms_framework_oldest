#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"
#include "jmsf/Real.hxx"

#include "../jmsf.h"


namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE Stopwatch :
	public virtual Object
{

public:
	virtual Boolean isSupported() const throw() = 0;
	virtual integer_big getFrequency() throw() = 0;
	virtual integer_big getCounts() const throw( Exception ) = 0;

	virtual void restartTiming() throw( Exception ) = 0;
	virtual integer_big countSplitCounts( integer_big time ) const throw( Exception ) = 0;
	virtual integer_big getSplitCounts() const throw( Exception ) = 0;
	virtual Real getSplitCountsInSeconds() const throw( Exception ) = 0;

	virtual Real getCountsInSeconds( integer_big counts ) const throw( Exception ) = 0;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Stopwatch *getNull() throw();
	static Stopwatch *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< Stopwatch > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
