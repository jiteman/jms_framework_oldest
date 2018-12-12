#pragma once


#include "jmsf/typeing/Ansii_string.hxx"
#include "jmsf/typeing/Naturals.hxx"

#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_SHARED_INTERFACE Exception {

public:
	virtual const typeing::Ansii_string &get_reason_description() const noexcept = 0;
	virtual const typeing::Ansii_string &get_detailed_description() const noexcept = 0;
	virtual const typeing::Ansii_string &get_type_information() const noexcept = 0;
	virtual const typeing::Ansii_string &get_filename() const noexcept = 0;
	virtual typeing::Memory_natural get_line_number() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	virtual ~Exception() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace validating
} // namespace jmsf
