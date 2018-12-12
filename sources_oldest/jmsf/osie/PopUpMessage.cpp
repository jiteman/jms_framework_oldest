#include "PopUpMessage.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_PopUpMessage :
	public PopUpMessage,
	public mixins::mixin_null_Object,
	public Singleton< null_PopUpMessage >
{

public:
	// virtuals PopUpMessage
	void showOk( const ConstantProxy< TextString > & ) const throw() {} // message

	const Boolean showOkCancel( const ConstantProxy< TextString > & ) const throw() { // message
		return False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_PopUpMessage >;
	static null_PopUpMessage *createInstance() throw() {
		null_PopUpMessage *nullPopUpMessage = new null_PopUpMessage;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullPopUpMessage, MACROS_FILE_AND_LINE ) );
		return nullPopUpMessage;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< PopUpMessage > createClone() const throw() {
		return Proxy< PopUpMessage >::createUnique( this );
	}

private:
	null_PopUpMessage( const null_PopUpMessage & ) throw() {} // other
	
	const null_PopUpMessage &operator =( const null_PopUpMessage &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_PopUpMessage::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_PopUpMessage :
	public PopUpMessage,
	public mixins::mixin_exception_Object,
	public Singleton< exception_PopUpMessage > {

public:
	// virtuals PopUpMessage
	void showOk( const ConstantProxy< TextString > & ) const throw() {} // message

	const Boolean showOkCancel( const ConstantProxy< TextString > & ) const throw() { // message
		return False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_PopUpMessage >;
	static exception_PopUpMessage *createInstance() throw() {
		exception_PopUpMessage *exceptionPopUpMessage = new exception_PopUpMessage;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionPopUpMessage, MACROS_FILE_AND_LINE ) );
		return exceptionPopUpMessage;
	}

private:
	exception_PopUpMessage() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< PopUpMessage > createClone() const throw() {
		return Proxy< PopUpMessage >::createUnique( this );
	}

private:
	exception_PopUpMessage( const exception_PopUpMessage & ) throw() {} // other

	const exception_PopUpMessage &operator =( const exception_PopUpMessage &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_PopUpMessage::operator =()" );
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
