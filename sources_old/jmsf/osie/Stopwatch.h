#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/typing/LongInteger.hxx"
#include "jmsf/typing/ShortReal.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE Stopwatch :
	public virtual patterning::Object
{

public:
	virtual typing::Boolean isSupported() const throw() = 0;
	virtual typing::LongInteger getFrequency() throw() = 0;
	virtual typing::LongInteger getCounts() const throw( validating::Exception ) = 0;

	virtual void restartTiming() throw( validating::Exception ) = 0;
	virtual typing::LongInteger countSplitCounts( typing::LongInteger time ) const throw( validating::Exception ) = 0;
	virtual typing::LongInteger getSplitCounts() const throw( validating::Exception ) = 0;
	virtual typing::ShortReal getSplitCountsInSeconds() const throw( validating::Exception ) = 0;

	virtual typing::ShortReal getCountsInSeconds( typing::LongInteger counts ) const throw( validating::Exception ) = 0;
	
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
	virtual pointing::Proxy< Stopwatch > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
