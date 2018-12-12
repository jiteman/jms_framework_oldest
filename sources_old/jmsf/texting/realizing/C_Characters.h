#pragma once


#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace texting {
namespace realizations {


class C_Characters {

public:	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~C_Characters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	C_Characters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	C_Characters( const C_Characters &other ) throw();
	const C_Characters &operator =( const C_Characters &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
public:
	static const typing::internals::platform_char *NULL_TEXT;
	static const typing::internals::platform_char *END_OF_LINE_TEXT;
	static const typing::internals::platform_char *SPACE_TEXT;

	static const typing::internals::platform_char NULL_CHAR;
	static const typing::internals::platform_char END_OF_LINE_CHAR;
	static const typing::internals::platform_char SPACE_CHAR;

private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizations
} // namespace texting
} // namespace jmsf
