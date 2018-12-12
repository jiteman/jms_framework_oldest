#pragma once


#include "../Exception.h"
#include "../File_and_line.h"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.hpp"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {
namespace mixing {


class JMSF_DLL_INTERFACE mixin_Exception :
	public Exception
{

public:
	// virtuals
	const typing::Ansii_string &get_description() const throw();
	const typing::Ansii_string &get_filename() const throw();
	typing::Memory_size get_line_number() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~mixin_Exception() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const typing::Ansii_string &name, const File_and_line &fileAndLine ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const mixin_Exception &other ) throw();

protected:
	const mixin_Exception &operator =( const mixin_Exception &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Ansii_string _theDescription;
	typing::Ansii_string _filename;
	typing::Memory_size _lineNumber;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixing
} // namespace validating
} // namespace jmsf
