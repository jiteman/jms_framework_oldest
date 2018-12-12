#pragma once


#include "jmsf/stdal/stdal_stl.h"

#include "../../types.h"

#include "../../Boolean.hxx"


namespace jmsf {
namespace realizations {
namespace hiddens {


class hidden_realization_TextString {

public:
	Boolean isEqual( const char_type *c_text ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const char_type *get() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~hidden_realization_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextString( const char_type *c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextString( const hidden_realization_TextString &other ) throw();
	const hidden_realization_TextString &operator =( const hidden_realization_TextString &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::string _text;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace
}
}
