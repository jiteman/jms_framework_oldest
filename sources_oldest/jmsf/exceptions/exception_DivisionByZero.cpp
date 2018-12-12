#include "exception_DivisionByZero.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace exceptions {

// static
const char_type *exception_DivisionByZero::EXCEPTION_MESSAGE_exception_DivisionByZero = " - exception_DivisionByZero";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_DivisionByZero::~exception_DivisionByZero() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_DivisionByZero::exception_DivisionByZero( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_DivisionByZero ) ) )
{}

exception_DivisionByZero::exception_DivisionByZero( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_DivisionByZero ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_DivisionByZero::exception_DivisionByZero( const exception_DivisionByZero &other ) throw()
	: mixin_Exception( other )
{}

const exception_DivisionByZero &exception_DivisionByZero::operator =( const exception_DivisionByZero &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace exceptions

} // namespace jmsf
