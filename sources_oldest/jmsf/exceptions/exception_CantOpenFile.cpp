#include "exception_CantOpenFile.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace exceptions {

// static
const char_type *exception_CantOpenFile::EXCEPTION_MESSAGE_exception_CantOpenFile = " - exception_CantOpenFile";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_CantOpenFile::~exception_CantOpenFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantOpenFile::exception_CantOpenFile( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_CantOpenFile ) ) )
{}

exception_CantOpenFile::exception_CantOpenFile( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_CantOpenFile ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantOpenFile::exception_CantOpenFile( const exception_CantOpenFile &other ) throw()
	: mixin_Exception( other )
{}

const exception_CantOpenFile &exception_CantOpenFile::operator =( const exception_CantOpenFile &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace exceptions

} // namespace jmsf