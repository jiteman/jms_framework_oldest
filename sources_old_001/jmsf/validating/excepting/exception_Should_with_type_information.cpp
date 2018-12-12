#include "exception_Should_with_type_information.h"


//#include "jmsf/typeing/AnsiiString.h"

#include "jmsf/jmsf_Allocators.h"
#include "jmsf/patterning/Singleton.hin"
#include "jmsf/typeing/Native_C_string.hin"


#include "jmsf/validating/logging_macroses.h"

#include <iostream>


namespace jmsf {
namespace validating {
namespace excepting {


const typeing::Ansii_string &exception_Should_with_type_information::get_detailed_description() const noexcept {
	return _the_detailed_information;
}

const typeing::Ansii_string &exception_Should_with_type_information::get_type_information() const noexcept {
	return _the_type_information;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should_with_type_information::~exception_Should_with_type_information() noexcept {
//	JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT( "exception_Should_with_type_information::~exception_Should_with_type_information()" );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should_with_type_information::exception_Should_with_type_information(
	const typeing::Ansii_string &a_reason_description,
	const typeing::Ansii_string &a_detailed_description,
	const typeing::Ansii_string &a_type_information,
	const File_and_line &file_and_line ) noexcept
	:
		mixin_Exception( a_reason_description, file_and_line ),
		_the_detailed_information( a_detailed_description ),
		_the_type_information( a_type_information )

{
	::std::cout << ::std::endl;
	::std::cout << "exception Should_with_type_information( reason, type, file_line ): in ";
	::std::cout << get_filename().get_as_native_C_string( jmsf_Allocators::instance()->get_character_array_allocator() ).get_array().get();
//	::std::cout << file_and_line.get_debug_filename();
	::std::cout << ", at ";
	::std::cout << get_line_number().get_native_value();
//	::std::cout << file_and_line.get_debug_line_number();
	::std::cout << ", for a type: < ";
	::std::cout << _the_type_information.get_as_native_C_string( jmsf_Allocators::instance()->get_character_array_allocator() ).get_array().get();
	::std::cout << " >";
	::std::cout << ::std::endl;
	::std::cout << "with reason: ";

	{
		typeing::Native_C_string reason_native_c_string =
			get_reason_description().get_as_native_C_string(
				jmsf_Allocators::instance()->get_character_array_allocator() );

		::std::cout << reason_native_c_string.get_array().get();
	}

	::std::cout << ::std::endl;
	::std::cout << "with details: ";

	{
		typeing::Native_C_string detail_native_c_string =
			_the_detailed_information.get_as_native_C_string(
				jmsf_Allocators::instance()->get_character_array_allocator() );

		::std::cout << detail_native_c_string.get_array().get();
	}

	::std::cout << ::std::endl;
	::std::cout << "with type: ";
	::std::cout << _the_type_information.get_as_native_C_string( jmsf_Allocators::instance()->get_character_array_allocator() ).get_array().get();
	::std::cout << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should_with_type_information::exception_Should_with_type_information( const exception_Should_with_type_information &another ) noexcept
	:
		mixin_Exception( another )
{
	JMSF_LOG_ERROR_OUTPUT( "exception_Should_with_type_information::exception_Should_with_type_information( another )" );
}

const exception_Should_with_type_information &exception_Should_with_type_information::operator =( const exception_Should_with_type_information &another ) noexcept {
	JMSF_LOG_ERROR_OUTPUT( "exception_Should_with_type_information::operator =( another )" );

	if ( this == &another ) return *this;

	mixin_Exception::operator =( another );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace excepting
} // namespace validating
} // namespace jmsf

