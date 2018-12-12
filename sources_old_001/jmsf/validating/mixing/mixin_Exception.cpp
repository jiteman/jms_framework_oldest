#include "mixin_Exception.h"


#include "jmsf/typeing/Naturals.hin"
#include "jmsf/validating/Should.h"

#include "jmsf/validating/logging_macroses.h"

//#include <iostream>


namespace jmsf {
namespace validating {
namespace mixing {


const typeing::Ansii_string &mixin_Exception::get_reason_description() const noexcept {
	return _the_reason_description;
}

const typeing::Ansii_string &mixin_Exception::get_detailed_description() const noexcept {
	return _mixins_detailed_description;
}

const typeing::Ansii_string &mixin_Exception::get_type_information() const noexcept {
	return _mixins_type_information;
}

const typeing::Ansii_string &mixin_Exception::get_filename() const noexcept {
	return _the_file_name;
}

typeing::Memory_natural mixin_Exception::get_line_number() const noexcept {
	return _the_line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Exception::~mixin_Exception() noexcept {
//	::std::cout << ::std::endl;
//	::std::cout << "mixin_Exception::~mixin_Exception()" << ::std::endl;
//	::std::cout << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const typeing::Ansii_string &a_reason_description, const File_and_line &a_file_and_line ) noexcept
	:
		_the_reason_description( a_reason_description ),
		_mixins_detailed_description( AS_string_literal( "[ no detailes ]" ) ),
		_mixins_type_information( AS_string_literal( "[ no type ]" ) ),
		_the_file_name( a_file_and_line.get_filename() ),
		_the_line_number( a_file_and_line.get_line_number() )
{
//	::std::cout << ::std::endl;
//	::std::cout << "mixin_Exception::mixin_Exception( a_reason_description, a_file_and_line )" << ::std::endl;
//	::std::cout << ::std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const mixin_Exception &another ) noexcept
	:
		_the_reason_description( another._the_reason_description ),
		_mixins_detailed_description( another._mixins_detailed_description ),
		_mixins_type_information( another._mixins_type_information ),
		_the_file_name( another._the_file_name ),
		_the_line_number( another._the_line_number )
{
	JMSF_LOG_ERROR_OUTPUT( "mixin_Exception::mixin_Exception( another )" );
//	::std::cout << ::std::endl;
//	::std::cout << "mixin_Exception::mixin_Exception( another )" << ::std::endl;
//	::std::cout << ::std::endl;
}

const mixin_Exception &mixin_Exception::operator =( const mixin_Exception &another ) {
	JMSF_LOG_ERROR_OUTPUT( "mixin_Exception::operator =( another )" );

	if ( this == &another ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace validating
} // namespace jmsf
