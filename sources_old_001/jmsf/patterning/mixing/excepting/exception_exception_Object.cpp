#include "exception_exception_Object.h"


//#include "jmsf/typeing/AnsiiString.h"
//#include "jmsf/pointing/Constant_proxy.hin"


namespace jmsf {
namespace patterning {
namespace mixing {
namespace exceptions {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_exception_Object::~exception_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const typeing::Ansii_string &a_reason, const validating::File_and_line &file_and_line ) noexcept
	: mixin_Exception( a_reason, file_and_line )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const exception_exception_Object &another ) noexcept
	: mixin_Exception( another )
{}

const exception_exception_Object &exception_exception_Object::operator =( const exception_exception_Object &another ) noexcept {
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
