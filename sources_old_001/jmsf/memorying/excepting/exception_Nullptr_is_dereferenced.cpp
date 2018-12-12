#include "exception_Nullptr_is_dereferenced.h"


namespace jmsf {
namespace memorying {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Nullptr_is_dereferenced::~exception_Nullptr_is_dereferenced() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Nullptr_is_dereferenced::exception_Nullptr_is_dereferenced( const typeing::Ansii_string &a_reason, const validating::File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, file_and_line )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Nullptr_is_dereferenced::exception_Nullptr_is_dereferenced( const exception_Nullptr_is_dereferenced &another ) noexcept
	:
		mixin_Exception( another )
{}

const exception_Nullptr_is_dereferenced &exception_Nullptr_is_dereferenced::operator =( const exception_Nullptr_is_dereferenced &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace memorying
} // namespace jmsf
