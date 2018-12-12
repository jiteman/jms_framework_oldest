#include "exception_Cule.h"

#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace cule {


// statics
const typing::internals::platform_character_type *exception_Cule::UNKNOWN_EXCEPTION_REASON = "Unknown Exception";
//const typing::Natural exception_Cule::UNKNOWN_LINE_NUMBER = typing::Natural_nill;
//~statics


inline exception_Cule::~exception_Cule() throw()
{}

exception_Cule::exception_Cule( const typing::Ansii_string &reason, const validating::File_and_line &file_and_line ) throw()
	:
		mixin_Exception( reason, file_and_line )
{}

// exception_Cule::exception_Cule( const typing::Ansii_string &reason ) throw()
// 	:
// 		mixin_Exception( reason )
// {}

exception_Cule::exception_Cule( const exception_Cule &other ) throw()
	:
		mixin_Exception( other )
{}


} // namespace
}
