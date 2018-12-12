#include "exception_RunnableException.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace mtf {
namespace exceptions {

// static
const char_type *exception_RunnableException::EXCEPTION_MESSAGE_exception_RunnableException = " - exception_RunnableException";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_RunnableException::~exception_RunnableException() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_RunnableException::exception_RunnableException( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_RunnableException ) ) )
{}

exception_RunnableException::exception_RunnableException( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_RunnableException ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_RunnableException::exception_RunnableException( const exception_RunnableException &other ) throw()
	: mixin_Exception( other )
{}

const exception_RunnableException &exception_RunnableException::operator =( const exception_RunnableException &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace exceptions
} // namespace mtf
} // namespace jmsf
