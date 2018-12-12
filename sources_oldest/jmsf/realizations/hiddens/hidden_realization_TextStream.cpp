#include "hidden_realization_TextStream.h"


namespace jmsf {
namespace realizations {
namespace hiddens {


void hidden_realization_TextStream::put( const char_type *c_text ) throw() {
	_stream << c_text;
}

void hidden_realization_TextStream::putInteger( const integer_big value, const natural base, const natural_size width, const char_type fill ) throw() {
	_stream << std::setbase( static_cast< integer >( base ) ) << std::setw( static_cast< std::streamsize >( width ) ) << std::setfill( fill ) << value;
}

void hidden_realization_TextStream::putNatural( const natural_big value, const natural base, const natural_size width, const char_type fill ) throw() {
	_stream << std::setbase( static_cast< integer >( base ) ) << std::setw( static_cast< std::streamsize >( width ) ) << std::setfill( fill ) << value;
}

void hidden_realization_TextStream::putReal( const real value, const natural base, const natural_size width, const char_type fill ) throw() {
	_stream << std::setbase( static_cast< integer >( base ) ) << std::setw( static_cast< std::streamsize >( width ) ) << std::setfill( fill ) << value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const char_type *hidden_realization_TextStream::get() const throw() {
	_toReturn = _stream.str();
	return _toReturn.c_str();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
hidden_realization_TextStream::~hidden_realization_TextStream() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
hidden_realization_TextStream::hidden_realization_TextStream() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
hidden_realization_TextStream::hidden_realization_TextStream( const hidden_realization_TextStream &other ) throw()
	: _stream( other._stream.str() )
{}

const hidden_realization_TextStream &hidden_realization_TextStream::operator =( const hidden_realization_TextStream &other ) throw() {
	if ( this == &other ) return *this;

	_stream.clear();
	_stream << other._stream.str();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
