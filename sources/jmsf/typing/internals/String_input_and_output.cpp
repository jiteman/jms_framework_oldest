#include "String_input_and_output.h"

#include "Floating_point_converter.h"

#include <cstring>


namespace jmsf {
namespace typing {
namespace internals {


const char *String_input_and_output::get_string() const noexept {
	return _buffer;
}

size_t String_input_and_output::get_quantity() const noexept {
	return _quantity_used;
}

String_input_and_output &String_input_and_output::put_integer( const int integer ) noexept {		
	clear_buffer();
	convert( size_t( integer < 0 ? -integer : integer ), 10 );

	if ( integer < 0 ) {
		append_char( _minus );
	}

	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_long_integer( const __int64 integer ) noexept {
	clear_buffer();
	convert_long( unsigned __int64( integer < 0 ? -integer : integer ), 10 );

	if ( integer < 0 ) {
		append_char( _minus );
	}

	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_natural( const unsigned int natural ) noexept {
	clear_buffer();
	convert( natural, 10 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_long_natural( const unsigned __int64 natural ) noexept {
	clear_buffer();
	convert_long( natural, 10 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_hexadecimal( const unsigned int natural ) noexept {
	clear_buffer();
	convert( natural, 16 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_long_hexadecimal( const unsigned __int64 natural ) noexept {
	clear_buffer();
	convert_long( natural, 16 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_binary( const unsigned int natural ) noexept {
	clear_buffer();
	convert( natural, 2 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_long_binary( const unsigned __int64 natural ) noexept {
	clear_buffer();
	convert_long( natural, 2 );
	move_reversed_buffer();
	finalize();
	return *this;
}

String_input_and_output &String_input_and_output::put_real( const float real ) noexept {
	put_floating_point( real );
	return *this;
}

String_input_and_output &String_input_and_output::put_real( const double real ) noexept {
	put_floating_point( real );
	return *this;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
String_input_and_output::~String_input_and_output() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
String_input_and_output::String_input_and_output() noexept {
	clear_buffer();
	clear_reversed_buffer();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
String_input_and_output::String_input_and_output( const String_input_and_output & ) noexept { // another
}

const String_input_and_output &String_input_and_output::operator =( const String_input_and_output &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
void String_input_and_output::clear_buffer() noexept {
	_buffer[ 0 ] = _null;
	_quantity_used = 0;
}

void String_input_and_output::clear_reversed_buffer() noexept {
	_reversed_buffer[ 0 ] = _null;
	_reversed_quantity_used = 0;
}

void String_input_and_output::put_floating_point( const Floating_point_converter &floating_point ) noexept {
	clear_buffer();

	if ( floating_point.is_nill() ) {
		append_char( _digits[ 0 ] );
		finalize();
		return;
	} else if ( floating_point.is_not_a_number() ) {
		append_char( _number );
		::strncpy( &_buffer[ _quantity_used ], _not_a_number, _character_string_buffer_size_constant - _quantity_used );
		return;
	} else if ( floating_point.is_infinity() ) {
		append_char( _number );
		append_char( floating_point.is_negative() ? _minus : _plus );
		::strncpy( &_buffer[ _quantity_used ], _infinity, _character_string_buffer_size_constant - _quantity_used );
		return;
	}

	const Floating_point_converter fp_decimal = floating_point.get_converted_to_decimal();

	if ( fp_decimal.is_negative() ) {
		append_char( _minus );
	}

	convert_long( fp_decimal.get_mantissa(), 10 );
	move_reversed_buffer();
		
	if ( fp_decimal.get_exponent() != 0 ) {
		append_char( _exponent );

		if ( fp_decimal.is_exponent_negative() ) {
			append_char( _minus );
		}

		convert( fp_decimal.get_exponent(), 10 );
		move_reversed_buffer();
	}

	finalize();
}

void String_input_and_output::append_char( const char character ) noexept {
	_buffer[ _quantity_used++ ] = character;
}

void String_input_and_output::reversed_append_char( const char character ) noexept {
	_reversed_buffer[ _reversed_quantity_used++ ] = character;
}

void String_input_and_output::convert( const unsigned int natural, const size_t base ) noexept {
	size_t accumulator = natural;

	do {
		const size_t remainder = accumulator % base;
		reversed_append_char( _digits[ remainder ] );
		accumulator /= base;
	} while ( accumulator != 0 );
}

void String_input_and_output::convert_long( const unsigned __int64 natural, const size_t base ) noexept {
	unsigned __int64 accumulator = natural;

	do {
		const size_t remainder = static_cast< size_t >( accumulator % static_cast< unsigned __int64 >( base ) );
		reversed_append_char( _digits[ remainder ] );
		accumulator /= base;
	} while ( accumulator != 0 );
}

// 	void String_input_and_output::convert_long_skipping_trailing_zeroes( const unsigned __int64 natural, const size_t base ) noexept {
// 		unsigned __int64 accumulator = natural;
// 
// 		bool is_in_trail = true;
// 
// 		do {
// 			const size_t remainder = static_cast< size_t >( accumulator % static_cast< unsigned __int64 >( base ) );
// 			accumulator /= base;
// 
// 			if ( is_in_trail ) {
// 				if ( remainder == 0 ) continue;
// 
// 				is_in_trail = false;
// 			}
// 
// 			reversed_append_char( _digits[ remainder ] );
// 			
// 		} while ( accumulator != 0 );
// 	}

void String_input_and_output::convert_long_with_separator( const unsigned __int64 natural, const size_t base, const size_t separator_size ) noexept {
	unsigned __int64 accumulator = natural;

	size_t separator_counter = separator_size;

	do {
		const size_t remainder = static_cast< size_t >( accumulator % static_cast< unsigned __int64 >( base ) );
		reversed_append_char( _digits[ remainder ] );
		accumulator /= base;

		if ( --separator_counter == 0 && accumulator != 0 ) {
			reversed_append_char( _comma );
			separator_counter = separator_size;
		}
	} while ( accumulator != 0 );
}

void String_input_and_output::move_reversed_buffer() noexept {
	const char *source = &_reversed_buffer[ _reversed_quantity_used - 1 ];
	char *destination = &_buffer[ _quantity_used ];

	for ( size_t counter = _reversed_quantity_used; counter != 0; --counter ) {
		*destination++ = *source--;
	}

	_quantity_used = _quantity_used + _reversed_quantity_used;
	clear_reversed_buffer();
}

void String_input_and_output::finalize() noexept {
	_buffer[ _quantity_used ] = _null;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// statics
const char String_input_and_output::_digits[ 16 ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
const char *String_input_and_output::_not_a_number = "NAN";
const char *String_input_and_output::_infinity = "INF";
//~statics

} // namespace internals
} // namespace typing
} // namespace jmsf
