#include "Mutex.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace osie {


class null_Mutex :
	public Mutex,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_Mutex >
{

public:
	// virtuals Mutex
	void lock() throw() {}
	void unlock() throw() {}

	typing::Boolean tryToLock() throw() {
		return typing::False;
	}

	typing::Boolean isLocked() const throw() {
		return typing::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_Mutex >;
	static null_Mutex *createInstance() throw() {
		null_Mutex *nullMutex = new null_Mutex;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullMutex, MACROS_FILE_AND_LINE ) );
		return nullMutex;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Mutex > createClone() const throw() {
		return pointing::Proxy< Mutex >::createUnique( this );
	}

private:
	null_Mutex( const null_Mutex & ) throw() {} // other
	
	const null_Mutex &operator =( const null_Mutex &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_Mutex::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_Mutex :
	public Mutex,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_Mutex > {

public:
	// virtuals Mutex
	void lock() throw() {}
	void unlock() throw() {}

	typing::Boolean tryToLock() throw() {
		return typing::False;
	}

	typing::Boolean isLocked() const throw() {
		return typing::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_Mutex >;
	static exception_Mutex *createInstance() throw() {
		exception_Mutex *exceptionMutex = new exception_Mutex;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionMutex, MACROS_FILE_AND_LINE ) );
		return exceptionMutex;
	}

private:
	exception_Mutex() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Mutex > createClone() const throw() {
		return pointing::Proxy< Mutex >::createUnique( this );
	}

private:
	exception_Mutex( const exception_Mutex & ) throw() {} // other

	const exception_Mutex &operator =( const exception_Mutex &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_Mutex::operator =()", FILE_AND_LINE );
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
