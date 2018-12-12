#include "Log.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace debugging {

class null_Log :
	public Log,
	public mixins::mixin_null_Object,
	public Singleton< null_Log >
{

public:
	// virtuals Log
	void putWithEol( const ConstantProxy< TextString > & ) throw() {} // message

	Proxy< Log > put( const ConstantProxy< TextString > & ) throw() { // message
		return Proxy< Log >();
	}

	void putEol() throw() {}

	Proxy< Log > putInteger( integer_big  ) throw() { // value
		return Proxy< Log >();
	}

	Proxy< Log > putNatural( natural_big  ) throw() { // value
		return Proxy< Log >();
	}

	Proxy< Log > putReal( const Real & ) throw() { // value
		return Proxy< Log >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Log() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Log >;
	static null_Log *createInstance() throw() {
		null_Log *nullLog = new null_Log;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullLog, MACROS_FILE_AND_LINE ) );
		return nullLog;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Log() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Log > createClone() const throw() {
		return Proxy< Log >::createUnique( this );
	}

private:
	null_Log( const null_Log & ) throw() {} // other
	
	const null_Log &operator =( const null_Log &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Log::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_Log :
	public Log,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Log > {

public:
	// virtuals Log
	void putWithEol( const ConstantProxy< TextString > & ) throw() {} // message

	Proxy< Log > put( const ConstantProxy< TextString > & ) throw() { // message
		return Proxy< Log >();
	}

	void putEol() throw() {}

	Proxy< Log > putInteger( integer_big  ) throw() { // value
		return Proxy< Log >();
	}

	Proxy< Log > putNatural( natural_big  ) throw() { // value
		return Proxy< Log >();
	}

	Proxy< Log > putReal( const Real & ) throw() { // value
		return Proxy< Log >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Log() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Log >;
	static exception_Log *createInstance() throw() {
		exception_Log *exceptionLog = new exception_Log;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionLog, MACROS_FILE_AND_LINE ) );
		return exceptionLog;
	}

private:
	exception_Log() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Log > createClone() const throw() {
		return Proxy< Log >::createUnique( this );
	}

private:
	exception_Log( const exception_Log & ) throw() {} // other

	const exception_Log &operator =( const exception_Log &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Log::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Log *Log::getNull() throw() {
	return null_Log::instance();
}

// static
Log *Log::getException() throw() {
	return exception_Log::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace debugging
} // namespace jmsf
