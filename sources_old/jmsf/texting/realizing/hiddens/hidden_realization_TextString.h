#pragma once


#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/typing/Boolean.hxx"

#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace texting {
namespace realizations {
namespace hiddens {


class hidden_realization_TextString {

public:
	typing::Boolean isEqual( const typing::internals::platform_char *c_text ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const typing::internals::platform_char *get() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~hidden_realization_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextString( const typing::internals::platform_char *c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextString( const hidden_realization_TextString &other ) throw();
	const hidden_realization_TextString &operator =( const hidden_realization_TextString &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::string _text;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace hiddens
} // namespace realizations
} // namespace texting
} // namespace jsmf
