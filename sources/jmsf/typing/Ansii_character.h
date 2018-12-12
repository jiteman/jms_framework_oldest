#pragma once


#include "Ansii_character.hxx"

#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace typing {


class Ansii_character {

public:
	typing::internals::platform_character_type getAsC() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_character() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_character() throw();
	Ansii_character( typing::internals::platform_character_type platformCharacter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_character( const Ansii_character &another ) throw();
	const Ansii_character &operator =( const Ansii_character &another ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::internals::platform_character_type _platformCharacter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typing
} // namespace jmsf
