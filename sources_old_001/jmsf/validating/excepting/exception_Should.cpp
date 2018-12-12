#include "exception_Should.h"


//#include "jmsf/typeing/AnsiiString.h"

#include "jmsf/jmsf_Allocators.h"
#include "jmsf/patterning/Singleton.hin"
#include "jmsf/typeing/Native_C_string.hin"

#include "jmsf/validating/logging_macroses.h"

#include <iostream>


namespace jmsf {
namespace validating {
namespace excepting {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should::~exception_Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const typeing::Ansii_string &a_reason, const File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason, file_and_line )
{
	::std::cout << ::std::endl;
	::std::cout << "exception Should: in ";
	::std::cout << get_filename().get_as_native_C_string( jmsf_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//	::std::cout << file_and_line.get_debug_filename();
	::std::cout << ", at ";
	::std::cout << get_line_number().get_native_value();
//	::std::cout << file_and_line.get_debug_line_number();
	::std::cout << ::std::endl;
	::std::cout << "with reason: ";
	::std::cout << a_reason.get_as_native_C_string( jmsf_Allocators::instance()->get_character_array_allocator() ).get_array().get();
	::std::cout << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const exception_Should &another ) noexcept
	:
		mixin_Exception( another )
{
	JMSF_LOG_ERROR_OUTPUT( "exception_Should::exception_Should( another )" );
}

const exception_Should &exception_Should::operator =( const exception_Should &another ) noexcept {
	JMSF_LOG_ERROR_OUTPUT( "exception_Should::operator =( another )" );

	if ( this == &another ) return *this;

	mixin_Exception::operator =( another );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace jmsf
