#include "hidden_realization_TextString.h"


#include "../../Boolean.h"


namespace jmsf {
namespace realizations {
namespace hiddens {


Boolean hidden_realization_TextString::isEqual( const char_type *const c_text ) const throw() {
	return _text == std::string( c_text );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const char_type *hidden_realization_TextString::get() const throw() {
	return _text.c_str();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
hidden_realization_TextString::~hidden_realization_TextString() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
hidden_realization_TextString::hidden_realization_TextString( const char_type *const c_text ) throw()
	: _text( c_text == nullptr ? std::string() : std::string( c_text ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
hidden_realization_TextString::hidden_realization_TextString( const hidden_realization_TextString &other ) throw()
	: _text( other._text )
{}

const hidden_realization_TextString &hidden_realization_TextString::operator =( const hidden_realization_TextString &other ) throw() {
	if ( this == &other ) return *this;

	_text = other._text;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
