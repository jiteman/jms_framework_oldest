#pragma once


#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {
namespace internals {


class Floating_point_converter;


class String_input_and_output {

public:
	const char *get_string() const noexept;
	size_t get_quantity() const noexept;

	String_input_and_output &put_integer( int integer ) noexept;
	String_input_and_output & put_long_integer( __int64 integer ) noexept;
	String_input_and_output &put_natural( unsigned int natural ) noexept;
	String_input_and_output &put_long_natural( unsigned __int64 natural ) noexept;
	String_input_and_output &put_hexadecimal( unsigned int natural ) noexept;
	String_input_and_output &put_long_hexadecimal( unsigned __int64 natural ) noexept;
	String_input_and_output &put_binary( unsigned int natural ) noexept;
	String_input_and_output &put_long_binary( unsigned __int64 natural ) noexept;
	String_input_and_output &put_real( float real ) noexept;
	String_input_and_output &put_real( double real ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~String_input_and_output() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	String_input_and_output() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	String_input_and_output( const String_input_and_output &another ) noexept;
	const String_input_and_output &operator =( const String_input_and_output &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void clear_buffer() noexept;
	void clear_reversed_buffer() noexept;

	void put_floating_point( const Floating_point_converter &floating_point ) noexept;

	void append_char( char character ) noexept;
	void reversed_append_char( char character ) noexept;
	void convert( unsigned int natural, size_t base ) noexept;
	void convert_long( unsigned __int64 natural, size_t base ) noexept;
// 	void convert_long_skipping_trailing_zeroes( unsigned __int64 natural, size_t base ) noexept;
	void convert_long_with_separator( unsigned __int64 natural, size_t base, size_t separator_size ) noexept;
	void move_reversed_buffer() noexept;
	void finalize() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const size_t _character_string_buffer_size_constant = 128;

	char _buffer[ _character_string_buffer_size_constant ];
	char _reversed_buffer[ _character_string_buffer_size_constant ];
	size_t _quantity_used;
	size_t _reversed_quantity_used;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:	
	static const char _digits[ 16 ];// = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	static const char _minus = '-';
	static const char _plus = '+';
	static const char _null = '\0';
	static const char _period = '.';
	static const char _comma = ',';
	static const char _exponent = 'E';
	static const char _number = '#';
	static const char *_not_a_number;
	static const char *_infinity;
};


} // namespace internals
} // namespace typing
} // namespace jmsf
