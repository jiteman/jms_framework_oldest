#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/validating/File_and_line.hxx"
#include "jmsf/typing/internals/internal_types.h"

//#include "jmsf/jmsf.h"


namespace jmsf {
namespace cule {


class exception_Cule :
	public validating::mixing::mixin_Exception
{

public:
	static const typing::internals::platform_character_type *UNKNOWN_EXCEPTION_REASON;

// private:
// 	static const typing::Natural UNKNOWN_LINE_NUMBER;

public:

public:
	virtual ~exception_Cule() throw();
	exception_Cule( const typing::Ansii_string &message, const validating::File_and_line &file_and_line ) throw();
//	exception_Cule( const typing::Ansii_string &message ) throw();

public:
	exception_Cule( const exception_Cule &other ) throw();

private:
	const exception_Cule &operator =( const exception_Cule &other ) throw();

private:


};

} // namespace
}
