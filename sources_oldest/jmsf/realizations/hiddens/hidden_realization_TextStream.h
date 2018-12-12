#pragma once

#include "jmsf/stdal/stdal_stl.h"

#include "../../types.h"


namespace jmsf {
namespace realizations {
namespace hiddens {

class hidden_realization_TextStream {

public:
	void put( const char_type *c_text ) throw();
	void putInteger( integer_big value, natural base, natural_size width, char_type fill ) throw();
	void putNatural( natural_big value, natural base, natural_size width, char_type fill ) throw();
	void putReal( real value, natural base, natural_size width, char_type fill ) throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const char_type *get() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~hidden_realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	hidden_realization_TextStream( const hidden_realization_TextStream &other ) throw();
	const hidden_realization_TextStream &operator =( const hidden_realization_TextStream &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::stringstream _stream;
	mutable std::string _toReturn;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
