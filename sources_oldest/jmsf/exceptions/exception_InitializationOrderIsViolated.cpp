#include "exception_InitializationOrderIsViolated.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"


namespace jmsf {
namespace exceptions {


// static
const char_type *exception_InitializationOrderIsViolated::EXCEPTION_MESSAGE_exception_InitializationOrderIsViolated = " - exception_InitializationOrderIsViolated";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_InitializationOrderIsViolated::~exception_InitializationOrderIsViolated() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_InitializationOrderIsViolated::exception_InitializationOrderIsViolated( const char_type *const reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( CONSTANT_TEXT_STRING( reason ) )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_InitializationOrderIsViolated ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_InitializationOrderIsViolated::exception_InitializationOrderIsViolated( const exception_InitializationOrderIsViolated &other ) throw()
	: mixin_Exception( other )
{}

const exception_InitializationOrderIsViolated &exception_InitializationOrderIsViolated::operator =( const exception_InitializationOrderIsViolated &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exceptions

} // namespace jmsf
