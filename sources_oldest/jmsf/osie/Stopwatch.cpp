#include "Stopwatch.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/Real.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_Stopwatch :
	public Stopwatch,
	public mixins::mixin_null_Object,
	public Singleton< null_Stopwatch >
{

public:
	// virtuals Stopwatch
	Boolean isSupported() const throw() {
		return False;
	}

	integer_big getFrequency() throw() {
		return integer_big( 0 );
	}

	integer_big getCounts() const throw( Exception ) {
		return integer_big( 0 );
	}

	void restartTiming() throw( Exception ) {}

	integer_big countSplitCounts( integer_big  ) const throw( Exception ) { // time
		return integer_big( 0 );
	}

	integer_big getSplitCounts() const throw( Exception ) {
		return integer_big( 0 );
	}

	Real getSplitCountsInSeconds() const throw( Exception ) {
		return Real::Null;
	}

	Real getCountsInSeconds( integer_big  ) const throw( Exception ) { // counts
		return Real::Null;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Stopwatch >;
	static null_Stopwatch *createInstance() throw() {
		null_Stopwatch *nullStopwatch = new null_Stopwatch;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullStopwatch, MACROS_FILE_AND_LINE ) );
		return nullStopwatch;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Stopwatch > createClone() const throw() {
		return Proxy< Stopwatch >::createUnique( this );
	}

private:
	null_Stopwatch( const null_Stopwatch & ) throw() {} // other
	
	const null_Stopwatch &operator =( const null_Stopwatch &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Stopwatch::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_Stopwatch :
	public Stopwatch,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Stopwatch > {

public:
	// virtuals Stopwatch
	Boolean isSupported() const throw() {
		return False;
	}

	integer_big getFrequency() throw() {
		return integer_big( 0 );
	}

	integer_big getCounts() const throw( Exception ) {
		return integer_big( 0 );
	}

	void restartTiming() throw( Exception ) {}

	integer_big countSplitCounts( integer_big  ) const throw( Exception ) { // time
		return integer_big( 0 );
	}

	integer_big getSplitCounts() const throw( Exception ) {
		return integer_big( 0 );
	}

	Real getSplitCountsInSeconds() const throw( Exception ) {
		return Real::Null;
	}

	Real getCountsInSeconds( integer_big  ) const throw( Exception ) { // counts
		return Real::Null;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Stopwatch >;
	static exception_Stopwatch *createInstance() throw() {
		exception_Stopwatch *exceptionStopwatch = new exception_Stopwatch;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionStopwatch, MACROS_FILE_AND_LINE ) );
		return exceptionStopwatch;
	}

private:
	exception_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Stopwatch > createClone() const throw() {
		return Proxy< Stopwatch >::createUnique( this );
	}

private:
	exception_Stopwatch( const exception_Stopwatch & ) throw() {} // other

	const exception_Stopwatch &operator =( const exception_Stopwatch &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Stopwatch::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Stopwatch *Stopwatch::getNull() throw() {
	return null_Stopwatch::instance();
}

// static
Stopwatch *Stopwatch::getException() throw() {
	return exception_Stopwatch::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace osie
} // namespace jmsf
