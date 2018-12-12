#include "C_Characters.h"


namespace jmsf {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
C_Characters::~C_Characters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
C_Characters::C_Characters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
C_Characters::C_Characters( const C_Characters &  ) throw() // other
{}

const C_Characters &C_Characters::operator =( const C_Characters &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// statics
const char_type *C_Characters::NULL_TEXT = "";
const char_type *C_Characters::END_OF_LINE_TEXT = "\n";
const char_type *C_Characters::SPACE_TEXT = " ";

const char_type C_Characters::NULL_CHAR = *NULL_TEXT;
const char_type C_Characters::END_OF_LINE_CHAR = *END_OF_LINE_TEXT;
const char_type C_Characters::SPACE_CHAR = *SPACE_TEXT;
//~statics
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
