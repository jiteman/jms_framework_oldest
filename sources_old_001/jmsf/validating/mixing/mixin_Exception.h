#pragma once


#include "../Exception.h"
#include "jmsf/validating/File_and_line.hxx"

#include "jmsf/typeing/Ansii_string.h"
#include "jmsf/typeing/Naturals.hpp"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {
namespace mixing {


class JMSF_SHARED_INTERFACE mixin_Exception :
	public virtual Exception
{

public:
	// virtuals Exception
	const typeing::Ansii_string &get_reason_description() const noexcept;
	const typeing::Ansii_string &get_detailed_description() const noexcept;
	const typeing::Ansii_string &get_type_information() const noexcept;
	const typeing::Ansii_string &get_filename() const noexcept;
	typeing::Memory_natural get_line_number() const noexcept;
	//~virtuals Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~mixin_Exception() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const typeing::Ansii_string &a_reason_description, const File_and_line &a_file_and_line ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const mixin_Exception &other ) noexcept;

protected:
	const mixin_Exception &operator =( const mixin_Exception &other );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Ansii_string _the_reason_description;
	typeing::Ansii_string _mixins_detailed_description;
	typeing::Ansii_string _mixins_type_information;
	typeing::Ansii_string _the_file_name;
	typeing::Memory_natural _the_line_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixing
} // namespace validating
} // namespace jmsf
