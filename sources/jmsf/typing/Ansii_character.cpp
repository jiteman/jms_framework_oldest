#include "Ansii_character.h"


namespace jmsf {
namespace typing {


typing::internals::platform_character_type Ansii_character::getAsC() const throw() {
	return _platformCharacter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_character::~Ansii_character() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_character::Ansii_character() throw() {
	_platformCharacter = typing::internals::platform_character_type( 0 );
}

Ansii_character::Ansii_character( typing::internals::platform_character_type platformCharacter ) throw() {
	_platformCharacter = platformCharacter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_character::Ansii_character( const Ansii_character &another ) throw() {
	_platformCharacter = another._platformCharacter;
}

const Ansii_character &Ansii_character::operator =( const Ansii_character &another ) throw() {
	if ( &another == this ) return *this;

	_platformCharacter = another._platformCharacter;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf
