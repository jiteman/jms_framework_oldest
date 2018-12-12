#include "UtilityControl.h"
#include "Stopwatch.h"
#include "PopUpMessage.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_UtilityControl :
	public UtilityControl,
	public mixins::mixin_null_Object,
	public Singleton< null_UtilityControl >
{

public:
	// virtuals UtilityControl
	Proxy< Stopwatch > createStopwatch() const throw() {
		return Proxy< Stopwatch >();
	}

	Proxy< PopUpMessage > createPopUpMessage() const throw() {
		return Proxy< PopUpMessage >();
	}

	Proxy< PopUpMessage > createPopUpMessage( const ConstantProxy< TextString > & ) const throw() { // caption
		return Proxy< PopUpMessage >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_UtilityControl >;
	static null_UtilityControl *createInstance() throw() {
		null_UtilityControl *nullUtilityControl = new null_UtilityControl;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullUtilityControl, MACROS_FILE_AND_LINE ) );
		return nullUtilityControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< UtilityControl > createClone() const throw() {
		return Proxy< UtilityControl >::createUnique( this );
	}

private:
	null_UtilityControl( const null_UtilityControl & ) throw() {} // other
	
	const null_UtilityControl &operator =( const null_UtilityControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_UtilityControl::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_UtilityControl :
	public UtilityControl,
	public mixins::mixin_exception_Object,
	public Singleton< exception_UtilityControl > {

public:
	// virtuals UtilityControl
	Proxy< Stopwatch > createStopwatch() const throw() {
		return Proxy< Stopwatch >();
	}

	Proxy< PopUpMessage > createPopUpMessage() const throw() {
		return Proxy< PopUpMessage >();
	}

	Proxy< PopUpMessage > createPopUpMessage( const ConstantProxy< TextString > & ) const throw() { // caption
		return Proxy< PopUpMessage >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_UtilityControl >;
	static exception_UtilityControl *createInstance() throw() {
		exception_UtilityControl *exceptionUtilityControl = new exception_UtilityControl;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionUtilityControl, MACROS_FILE_AND_LINE ) );
		return exceptionUtilityControl;
	}

private:
	exception_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< UtilityControl > createClone() const throw() {
		return Proxy< UtilityControl >::createUnique( this );
	}

private:
	exception_UtilityControl( const exception_UtilityControl & ) throw() {} // other

	const exception_UtilityControl &operator =( const exception_UtilityControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_UtilityControl::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
UtilityControl *UtilityControl::getNull() throw() {
	return null_UtilityControl::instance();
}

// static
UtilityControl *UtilityControl::getException() throw() {
	return exception_UtilityControl::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace osie
} // namespace jmsf
