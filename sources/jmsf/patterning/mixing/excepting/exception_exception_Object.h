#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"


namespace jmsf {
namespace patterning {
namespace mixing {
namespace exceptions {


class exception_exception_Object :
	public validating::mixing::mixin_Exception
{

public:
	// virtuals
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_exception_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_exception_Object( const typing::Ansii_string &a_reason, const validating::File_and_line &file_and_line ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	exception_exception_Object( const exception_exception_Object &another ) noexept;

private:
	const exception_exception_Object &operator =( const exception_exception_Object &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace exceptions
} // namespace mixing
} // namespace patterning
} // namespace jmsf
