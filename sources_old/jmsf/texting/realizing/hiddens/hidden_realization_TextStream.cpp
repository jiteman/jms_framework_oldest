#include "hidden_realization_TextStream.h"


#include "jmsf/typing/LongNatural.h"
#include "jmsf/typing/Natural.h"
#include "jmsf/typing/LongInteger.h"
#include "jmsf/typing/Integer.h"
#include "jmsf/typing/ShortestNatural.h"
#include "jmsf/typing/Real.h"
#include "jmsf/typing/ShortReal.h"


namespace jmsf {
namespace texting {
namespace realizations {
namespace hiddens {


void hidden_realization_TextStream::put( const typing::internals::platform_char *c_text ) throw() {
	_stream << c_text;
}

void hidden_realization_TextStream::putInteger( const typing::Integer value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

void hidden_realization_TextStream::putInteger( const typing::LongInteger value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

void hidden_realization_TextStream::putNatural( const typing::Natural value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

void hidden_realization_TextStream::putNatural( const typing::LongNatural value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

void hidden_realization_TextStream::putReal( const typing::ShortReal value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

void hidden_realization_TextStream::putReal( const typing::Real value, const typing::ShortestNatural base, const typing::Natural width, const typing::internals::platform_char fill ) throw() {
	_stream << std::setbase( base.getPlatformValue() ) << std::setw( static_cast< std::streamsize >( width.getPlatformValue() ) ) << std::setfill( fill ) << value.getPlatformValue();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const typing::internals::platform_char *hidden_realization_TextStream::get() const throw() {
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


} // namespace hiddens
} // namespace realizations
} // namespace texting
} // namespace jmsf
