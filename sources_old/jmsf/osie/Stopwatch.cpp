#include "Stopwatch.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"
#include "jmsf/typing/LongInteger.h"
#include "jmsf/typing/ShortReal.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {


class null_Stopwatch :
	public Stopwatch,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_Stopwatch >
{

public:
	// virtuals Stopwatch
	typing::Boolean isSupported() const throw() {
		return typing::False;
	}

	typing::LongInteger getFrequency() throw() {
		return typing::LongInteger::create( 0 );
	}

	typing::LongInteger getCounts() const throw( validating::Exception ) {
		return typing::LongInteger::create( 0 );
	}

	void restartTiming() throw( validating::Exception ) {}

	typing::LongInteger countSplitCounts( typing::LongInteger  ) const throw( validating::Exception ) { // time
		return typing::LongInteger::create( 0 );
	}

	typing::LongInteger getSplitCounts() const throw( validating::Exception ) {
		return typing::LongInteger::create( 0 );
	}

	typing::ShortReal getSplitCountsInSeconds() const throw( validating::Exception ) {
		return typing::ShortRealZero;
	}

	typing::ShortReal getCountsInSeconds( typing::LongInteger  ) const throw( validating::Exception ) { // counts
		return typing::ShortRealZero;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_Stopwatch >;
	static null_Stopwatch *createInstance() throw() {
		null_Stopwatch *nullStopwatch = new null_Stopwatch;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullStopwatch, MACROS_FILE_AND_LINE ) );
		return nullStopwatch;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Stopwatch > createClone() const throw() {
		return pointing::Proxy< Stopwatch >::createUnique( this );
	}

private:
	null_Stopwatch( const null_Stopwatch & ) throw() {} // other
	
	const null_Stopwatch &operator =( const null_Stopwatch &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_Stopwatch::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_Stopwatch :
	public Stopwatch,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_Stopwatch > {

public:
	// virtuals Stopwatch
	typing::Boolean isSupported() const throw() {
		return typing::False;
	}

	typing::LongInteger getFrequency() throw() {
		return typing::LongInteger::create( 0 );
	}

	typing::LongInteger getCounts() const throw( validating::Exception ) {
		return typing::LongInteger::create( 0 );
	}

	void restartTiming() throw( validating::Exception ) {}

	typing::LongInteger countSplitCounts( typing::LongInteger  ) const throw( validating::Exception ) { // time
		return typing::LongInteger::create( 0 );
	}

	typing::LongInteger getSplitCounts() const throw( validating::Exception ) {
		return typing::LongInteger::create( 0 );
	}

	typing::ShortReal getSplitCountsInSeconds() const throw( validating::Exception ) {
		return typing::ShortRealZero;
	}

	typing::ShortReal getCountsInSeconds( typing::LongInteger  ) const throw( validating::Exception ) { // counts
		return typing::ShortRealZero;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_Stopwatch >;
	static exception_Stopwatch *createInstance() throw() {
		exception_Stopwatch *exceptionStopwatch = new exception_Stopwatch;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionStopwatch, MACROS_FILE_AND_LINE ) );
		return exceptionStopwatch;
	}

private:
	exception_Stopwatch() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Stopwatch > createClone() const throw() {
		return pointing::Proxy< Stopwatch >::createUnique( this );
	}

private:
	exception_Stopwatch( const exception_Stopwatch & ) throw() {} // other

	const exception_Stopwatch &operator =( const exception_Stopwatch &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_Stopwatch::operator =()", FILE_AND_LINE );
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
