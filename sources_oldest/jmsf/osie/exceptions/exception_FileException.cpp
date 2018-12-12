#include "exception_FileException.h"
#include "jmsf/factory_TextObject.h"


namespace jmsf {
namespace osie {
namespace exceptions {


// static
const char_type *const exception_FileException::UNKNOWN_FILE_EXCEPTION = "Unknown File exception";


exception_FileException::~exception_FileException() throw()
{}

exception_FileException::exception_FileException() throw()
	: mixin_Exception( CONSTANT_TEXT_STRING( UNKNOWN_FILE_EXCEPTION ) )
{}

exception_FileException::exception_FileException( const ConstantProxy< TextString > &message ) throw()
	: mixin_Exception( message )
{}

exception_FileException::exception_FileException( const Proxy< TextStream > &message ) throw()
	: mixin_Exception( message )
{}


} // namespace
}
}
