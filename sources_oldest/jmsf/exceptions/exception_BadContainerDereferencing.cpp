#include "exception_BadContainerDereferencing.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace exceptions {

// static
const char_type *exception_BadContainerDereferencing::EXCEPTION_MESSAGE_exception_BadContainerDereferencing = " - exception_BadContainerDereferencing";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_BadContainerDereferencing::~exception_BadContainerDereferencing() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_BadContainerDereferencing::exception_BadContainerDereferencing( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_BadContainerDereferencing ) ) )
{}

exception_BadContainerDereferencing::exception_BadContainerDereferencing( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_BadContainerDereferencing ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_BadContainerDereferencing::exception_BadContainerDereferencing( const exception_BadContainerDereferencing &other ) throw()
	: mixin_Exception( other )
{}

const exception_BadContainerDereferencing &exception_BadContainerDereferencing::operator =( const exception_BadContainerDereferencing &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace exceptions
} // namespace jmsf
