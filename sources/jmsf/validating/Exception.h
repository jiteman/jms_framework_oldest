#pragma once


#include "jmsf/typing/Ansii_string.hxx"
#include "jmsf/typing/Naturals.hxx"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_DLL_INTERFACE Exception {

public:
 	virtual const typing::Ansii_string &get_description() const noexept = 0;
 	virtual const typing::Ansii_string &get_filename() const noexept = 0;
	virtual typing::Memory_size get_line_number() const noexept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Exception() noexept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace validating
} // namespace jmsf
