#include "exception_exception_Object.h"


//#include "jmsf/typing/AnsiiString.h"
#include "jmsf/pointing/Constant_proxy.inl"


namespace jmsf {
namespace patterning {
namespace mixing {
namespace exceptions {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_exception_Object::~exception_exception_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const typing::Ansii_string &a_reason, const validating::File_and_line &file_and_line ) noexept
	: mixin_Exception( a_reason, file_and_line )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const exception_exception_Object &another ) noexept
	: mixin_Exception( another )
{}

const exception_exception_Object &exception_exception_Object::operator =( const exception_exception_Object &another ) noexept {
	if ( &another == this ) return *this;

	mixin_Exception::operator =( another );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exceptions
} // namespace mixing
} // namespace patterning
} // namespace jmsf
