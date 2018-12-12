#include "UtilityControl.h"


#include "Stopwatch.h"
#include "PopUpMessage.h"
#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace osie {


class null_UtilityControl :
	public UtilityControl,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_UtilityControl >
{

public:
	// virtuals UtilityControl
	pointing::Proxy< Stopwatch > createStopwatch() const throw() {
		return pointing::Proxy< Stopwatch >();
	}

	pointing::Proxy< PopUpMessage > createPopUpMessage() const throw() {
		return pointing::Proxy< PopUpMessage >();
	}

	pointing::Proxy< PopUpMessage > createPopUpMessage( const pointing::ConstantProxy< texting::TextString > & ) const throw() { // caption
		return pointing::Proxy< PopUpMessage >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_UtilityControl >;
	static null_UtilityControl *createInstance() throw() {
		null_UtilityControl *nullUtilityControl = new null_UtilityControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullUtilityControl, MACROS_FILE_AND_LINE ) );
		return nullUtilityControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< UtilityControl > createClone() const throw() {
		return pointing::Proxy< UtilityControl >::createUnique( this );
	}

private:
	null_UtilityControl( const null_UtilityControl & ) throw() {} // other
	
	const null_UtilityControl &operator =( const null_UtilityControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_UtilityControl::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_UtilityControl :
	public UtilityControl,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_UtilityControl > {

public:
	// virtuals UtilityControl
	pointing::Proxy< Stopwatch > createStopwatch() const throw() {
		return pointing::Proxy< Stopwatch >();
	}

	pointing::Proxy< PopUpMessage > createPopUpMessage() const throw() {
		return pointing::Proxy< PopUpMessage >();
	}

	pointing::Proxy< PopUpMessage > createPopUpMessage( const pointing::ConstantProxy< texting::TextString > & ) const throw() { // caption
		return pointing::Proxy< PopUpMessage >();
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_UtilityControl >;
	static exception_UtilityControl *createInstance() throw() {
		exception_UtilityControl *exceptionUtilityControl = new exception_UtilityControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionUtilityControl, MACROS_FILE_AND_LINE ) );
		return exceptionUtilityControl;
	}

private:
	exception_UtilityControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< UtilityControl > createClone() const throw() {
		return pointing::Proxy< UtilityControl >::createUnique( this );
	}

private:
	exception_UtilityControl( const exception_UtilityControl & ) throw() {} // other

	const exception_UtilityControl &operator =( const exception_UtilityControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_UtilityControl::operator =()", FILE_AND_LINE );
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
