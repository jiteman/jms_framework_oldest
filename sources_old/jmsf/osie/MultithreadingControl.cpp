#include "MultithreadingControl.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"

#include "Event.h"
#include "EventArray.h"
#include "Mutex.h"
#include "jmsf/osie/osie_Thread.h"

#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/Pointer.inl"


namespace jmsf {
namespace osie {


class null_MultithreadingControl :
	public MultithreadingControl,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_MultithreadingControl >
{

public:
	// virtuals MultithreadingControl
 	pointing::Proxy< Event > createEvent() const throw() {
		return pointing::Proxy< Event >();
	}

 	pointing::Proxy< EventArray > createEventArray() const throw() {
		return pointing::Proxy< EventArray >();
	}

	pointing::Proxy< Mutex > createMutex() const throw() {
		return pointing::Proxy< Mutex >();
	}

	void launchThread( pointing::Pointer< osie_Thread > , typing::Natural  ) const throw( validating::Exception ) {} // thread, priorityLevel
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_MultithreadingControl >;
	static null_MultithreadingControl *createInstance() throw() {
		null_MultithreadingControl *nullMultithreadingControl = new null_MultithreadingControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullMultithreadingControl, MACROS_FILE_AND_LINE ) );
		return nullMultithreadingControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< MultithreadingControl > createClone() const throw() {
		return pointing::Proxy< MultithreadingControl >::createUnique( this );
	}

private:
	null_MultithreadingControl( const null_MultithreadingControl & ) throw() {} // other
	
	const null_MultithreadingControl &operator =( const null_MultithreadingControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_MultithreadingControl::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_MultithreadingControl :
	public MultithreadingControl,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_MultithreadingControl > {

public:
	// virtuals MultithreadingControl
 	pointing::Proxy< Event > createEvent() const throw() {
		return pointing::Proxy< Event >();
	}

 	pointing::Proxy< EventArray > createEventArray() const throw() {
		return pointing::Proxy< EventArray >();
	}

	pointing::Proxy< Mutex > createMutex() const throw() {
		return pointing::Proxy< Mutex >();
	}

	void launchThread( pointing::Pointer< osie_Thread > , typing::Natural  ) const throw( validating::Exception ) {} // thread, priorityLevel
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_MultithreadingControl >;
	static exception_MultithreadingControl *createInstance() throw() {
		exception_MultithreadingControl *exceptionMultithreadingControl = new exception_MultithreadingControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionMultithreadingControl, MACROS_FILE_AND_LINE ) );
		return exceptionMultithreadingControl;
	}

private:
	exception_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< MultithreadingControl > createClone() const throw() {
		return pointing::Proxy< MultithreadingControl >::createUnique( this );
	}

private:
	exception_MultithreadingControl( const exception_MultithreadingControl & ) throw() {} // other

	const exception_MultithreadingControl &operator =( const exception_MultithreadingControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_MultithreadingControl::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
MultithreadingControl *MultithreadingControl::getNull() throw() {
	return null_MultithreadingControl::instance();
}

// static
MultithreadingControl *MultithreadingControl::getException() throw() {
	return exception_MultithreadingControl::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace osie
} // namespace jmsf
