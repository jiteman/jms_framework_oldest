#pragma once

#include "types.h"


namespace jmsf {


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
	static const char_type *NULL_TEXT;
	static const char_type *END_OF_LINE_TEXT;
	static const char_type *SPACE_TEXT;

	static const char_type NULL_CHAR;
	static const char_type END_OF_LINE_CHAR;
	static const char_type SPACE_CHAR;

private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
