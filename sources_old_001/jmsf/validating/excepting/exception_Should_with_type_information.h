#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"


namespace jmsf {
namespace validating {
namespace excepting {


class exception_Should_with_type_information :
	public mixing::mixin_Exception
{

public:
	// virtuals Exception
	const typeing::Ansii_string &get_detailed_description() const noexcept;
	const typeing::Ansii_string &get_type_information() const noexcept;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_Should_with_type_information() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should_with_type_information(
		const typeing::Ansii_string &a_reason_description,
		const typeing::Ansii_string &a_detailed_description,
		const typeing::Ansii_string &a_type_information,
		const File_and_line &file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Should_with_type_information( const exception_Should_with_type_information &other ) noexcept;

private:
	const exception_Should_with_type_information &operator =( const exception_Should_with_type_information &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Ansii_string _the_detailed_information;
	typeing::Ansii_string _the_type_information;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace validating
} // namespace jmsf
