#include "Mutex.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_Mutex :
	public Mutex,
	public mixins::mixin_null_Object,
	public Singleton< null_Mutex >
{

public:
	// virtuals Mutex
	void lock() throw() {}
	void unlock() throw() {}

	Boolean tryToLock() throw() {
		return False;
	}

	Boolean isLocked() const throw() {
		return False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Mutex >;
	static null_Mutex *createInstance() throw() {
		null_Mutex *nullMutex = new null_Mutex;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullMutex, MACROS_FILE_AND_LINE ) );
		return nullMutex;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Mutex > createClone() const throw() {
		return Proxy< Mutex >::createUnique( this );
	}

private:
	null_Mutex( const null_Mutex & ) throw() {} // other
	
	const null_Mutex &operator =( const null_Mutex &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Mutex::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_Mutex :
	public Mutex,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Mutex > {

public:
	// virtuals Mutex
	void lock() throw() {}
	void unlock() throw() {}

	Boolean tryToLock() throw() {
		return False;
	}

	Boolean isLocked() const throw() {
		return False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Mutex >;
	static exception_Mutex *createInstance() throw() {
		exception_Mutex *exceptionMutex = new exception_Mutex;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionMutex, MACROS_FILE_AND_LINE ) );
		return exceptionMutex;
	}

private:
	exception_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Mutex > createClone() const throw() {
		return Proxy< Mutex >::createUnique( this );
	}

private:
	exception_Mutex( const exception_Mutex & ) throw() {} // other

	const exception_Mutex &operator =( const exception_Mutex &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Mutex::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Mutex *Mutex::getNull() throw() {
	return null_Mutex::instance();
}

// static
Mutex *Mutex::getException() throw() {
	return exception_Mutex::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace osie
} // namespace jmsf
