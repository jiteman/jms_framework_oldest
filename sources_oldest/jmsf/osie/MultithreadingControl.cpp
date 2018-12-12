#include "MultithreadingControl.h"
#include "Event.h"
#include "EventArray.h"
#include "Mutex.h"
#include "jmsf/osie/osie_Thread.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_MultithreadingControl :
	public MultithreadingControl,
	public mixins::mixin_null_Object,
	public Singleton< null_MultithreadingControl >
{

public:
	// virtuals MultithreadingControl
 	Proxy< Event > createEvent() const throw() {
		return Proxy< Event >();
	}

 	Proxy< EventArray > createEventArray() const throw() {
		return Proxy< EventArray >();
	}

	Proxy< Mutex > createMutex() const throw() {
		return Proxy< Mutex >();
	}

	void launchThread( Pointer< osie_Thread > , natural_size  ) const throw( Exception ) {} // thread, priorityLevel
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
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullMultithreadingControl, MACROS_FILE_AND_LINE ) );
		return nullMultithreadingControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MultithreadingControl > createClone() const throw() {
		return Proxy< MultithreadingControl >::createUnique( this );
	}

private:
	null_MultithreadingControl( const null_MultithreadingControl & ) throw() {} // other
	
	const null_MultithreadingControl &operator =( const null_MultithreadingControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_MultithreadingControl::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_MultithreadingControl :
	public MultithreadingControl,
	public mixins::mixin_exception_Object,
	public Singleton< exception_MultithreadingControl > {

public:
	// virtuals MultithreadingControl
 	Proxy< Event > createEvent() const throw() {
		return Proxy< Event >();
	}

 	Proxy< EventArray > createEventArray() const throw() {
		return Proxy< EventArray >();
	}

	Proxy< Mutex > createMutex() const throw() {
		return Proxy< Mutex >();
	}

	void launchThread( Pointer< osie_Thread > , natural_size  ) const throw( Exception ) {} // thread, priorityLevel
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
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionMultithreadingControl, MACROS_FILE_AND_LINE ) );
		return exceptionMultithreadingControl;
	}

private:
	exception_MultithreadingControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MultithreadingControl > createClone() const throw() {
		return Proxy< MultithreadingControl >::createUnique( this );
	}

private:
	exception_MultithreadingControl( const exception_MultithreadingControl & ) throw() {} // other

	const exception_MultithreadingControl &operator =( const exception_MultithreadingControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_MultithreadingControl::operator =()" );
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
