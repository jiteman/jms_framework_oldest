#include "exception_FileException.h"


#include "jmsf/texting/factory_TextObject.h"


namespace jmsf {
namespace osie {
namespace exceptions {


// static
const typing::internals::platform_char *const exception_FileException::UNKNOWN_FILE_EXCEPTION = "Unknown File exception";


exception_FileException::~exception_FileException() throw()
{}

exception_FileException::exception_FileException( const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( CONSTANT_TEXT_STRING( UNKNOWN_FILE_EXCEPTION ), fileAndLine )
{}

exception_FileException::exception_FileException( const pointing::ConstantProxy< texting::TextString > &message, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( message, fileAndLine )
{}

exception_FileException::exception_FileException( const pointing::Proxy< texting::TextStream > &message, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( message, fileAndLine )
{}


} // namespace
}
}
