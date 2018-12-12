#include "hidden_realization_TextString.h"


#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace texting {
namespace realizations {
namespace hiddens {


typing::Boolean hidden_realization_TextString::isEqual( const typing::internals::platform_char *const c_text ) const throw() {
	return typing::Boolean::create( _text == std::string( c_text ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const typing::internals::platform_char *hidden_realization_TextString::get() const throw() {
	return _text.c_str();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
hidden_realization_TextString::~hidden_realization_TextString() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
hidden_realization_TextString::hidden_realization_TextString( const typing::internals::platform_char *const c_text ) throw()
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


} // namespace hiddens
} // namespace realizations
} // namespace texting
} // namespace jmsf
