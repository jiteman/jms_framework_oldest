#pragma once


#include "jmsf/typing/Integer.hxx"
#include "jmsf/typing/LongInteger.hxx"
#include "jmsf/typing/Natural.hxx"
#include "jmsf/typing/LongNatural.hxx"
#include "jmsf/typing/ShortestNatural.hxx"
#include "jmsf/typing/ShortReal.hxx"
#include "jmsf/typing/Real.hxx"

#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace texting {
namespace realizations {
namespace hiddens {


class hidden_realization_TextStream {

public:
	void put( const typing::internals::platform_char *c_text ) throw();
	void putInteger( typing::Integer value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();
	void putInteger( typing::LongInteger value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();
	void putNatural( typing::Natural value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();
	void putNatural( typing::LongNatural value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();

	void putReal( typing::ShortReal value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();
	void putReal( typing::Real value, typing::ShortestNatural base, typing::Natural width, typing::internals::platform_char fill ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const typing::internals::platform_char *get() const throw();

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


} // namespace hiddens
} // namespace realizations
} // namespace texting
} // namespace jmsf
