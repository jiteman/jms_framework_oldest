#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"


namespace jmsf {
namespace memorying {
namespace excepting {


class exception_Memory_is_depleted :
	public validating::mixing::mixin_Exception
{

public:
	// virtuals validating::mixing::mixin_Exception
	//~virtuals validating::mixing::mixin_Exception

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual validating::mixing::mixin_Exception
	~exception_Memory_is_depleted() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Memory_is_depleted( const typing::Ansii_string &a_reason, const validating::File_and_line &file_and_line ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_Memory_is_depleted( const exception_Memory_is_depleted &another ) noexept;
	const exception_Memory_is_depleted &operator =( const exception_Memory_is_depleted &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace excepting
} // namespace memorying
} // namespace jmsf
