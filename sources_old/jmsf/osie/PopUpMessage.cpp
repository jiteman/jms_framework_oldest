#include "PopUpMessage.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/ConstantProxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace osie {


class null_PopUpMessage :
	public PopUpMessage,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_PopUpMessage >
{

public:
	// virtuals PopUpMessage
	void showOk( const pointing::ConstantProxy< texting::TextString > & ) const throw() {} // message

	const typing::Boolean showOkCancel( const pointing::ConstantProxy< texting::TextString > & ) const throw() { // message
		return typing::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_PopUpMessage >;
	static null_PopUpMessage *createInstance() throw() {
		null_PopUpMessage *nullPopUpMessage = new null_PopUpMessage;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullPopUpMessage, MACROS_FILE_AND_LINE ) );
		return nullPopUpMessage;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< PopUpMessage > createClone() const throw() {
		return pointing::Proxy< PopUpMessage >::createUnique( this );
	}

private:
	null_PopUpMessage( const null_PopUpMessage & ) throw() {} // other
	
	const null_PopUpMessage &operator =( const null_PopUpMessage &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_PopUpMessage::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_PopUpMessage :
	public PopUpMessage,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_PopUpMessage > {

public:
	// virtuals PopUpMessage
	void showOk( const pointing::ConstantProxy< texting::TextString > & ) const throw() {} // message

	const typing::Boolean showOkCancel( const pointing::ConstantProxy< texting::TextString > & ) const throw() { // message
		return typing::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_PopUpMessage >;
	static exception_PopUpMessage *createInstance() throw() {
		exception_PopUpMessage *exceptionPopUpMessage = new exception_PopUpMessage;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionPopUpMessage, MACROS_FILE_AND_LINE ) );
		return exceptionPopUpMessage;
	}

private:
	exception_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< PopUpMessage > createClone() const throw() {
		return pointing::Proxy< PopUpMessage >::createUnique( this );
	}

private:
	exception_PopUpMessage( const exception_PopUpMessage & ) throw() {} // other

	const exception_PopUpMessage &operator =( const exception_PopUpMessage &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_PopUpMessage::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
PopUpMessage *PopUpMessage::getNull() throw() {
	return null_PopUpMessage::instance();
}

// static
PopUpMessage *PopUpMessage::getException() throw() {
	return exception_PopUpMessage::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace osie
} // namespace jmsf
