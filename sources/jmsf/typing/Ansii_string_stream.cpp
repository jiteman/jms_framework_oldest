#include "Ansii_string_stream.h"

//#include "internals/String_input_and_output.h"

#include "Integers.inl"
#include "Naturals.inl"
#include "Reals.inl"
#include "jmsf/structing/containing/List.inl"
#include "jmsf/structing/traversing/List_traverser.inl"

#include <cstdio>


namespace jmsf {
namespace typing {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Ansii_string_stream::put_string( const Ansii_string &a_string ) noexept {
	Ansii_string ansii_string = Ansii_string::create_from_another( _character_array_allocator, a_string );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_character( const Ansii_character &a_character ) noexept {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const structing::containing::List< Ansii_string > &Ansii_string_stream::get_ansii_string_list() const noexept {
	return _ansii_string_list;
}

Ansii_string Ansii_string_stream::create_consolidated_ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const noexept {
	return Ansii_string::create_from_list( character_array_allocator, _ansii_string_list );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_string_stream::~Ansii_string_stream() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
Ansii_string_stream Ansii_string_stream::create( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept {
	return Ansii_string_stream( character_array_allocator, list_node_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string_stream::Ansii_string_stream( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept
	:
		_character_array_allocator( character_array_allocator ),
		_list_node_allocator( list_node_allocator )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string_stream::Ansii_string_stream( const Ansii_string_stream &another ) noexept
	:
		_character_array_allocator( another._character_array_allocator ),
		_list_node_allocator( another._list_node_allocator ),
		_ansii_string_list( another._ansii_string_list )
{
	Ansii_string_stream &non_contant_another = const_cast< Ansii_string_stream & >( another );
	non_contant_another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	non_contant_another._list_node_allocator = memorying::Womp< memorying::Allocator >();
	non_contant_another._ansii_string_list = structing::containing::List< Ansii_string >();
}

const Ansii_string_stream &Ansii_string_stream::operator =( const Ansii_string_stream &another ) noexept {
	if ( &another == this ) return *this;

	_character_array_allocator = another._character_array_allocator;
	_list_node_allocator = another._list_node_allocator;
	_ansii_string_list = another._ansii_string_list;

	Ansii_string_stream &non_contant_another = const_cast< Ansii_string_stream & >( another );
	non_contant_another._character_array_allocator = memorying::Womp< memorying::Allocator >();
	non_contant_another._list_node_allocator = memorying::Womp< memorying::Allocator >();
	non_contant_another._ansii_string_list = structing::containing::List< Ansii_string >();
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
static const memory_size_value_type buffer_size_constant = 40;

void Ansii_string_stream::put_integer_32( const Integer integer_number ) noexept {
// 	internals::String_input_and_output converter;
// 	converter.put_integer( integer_number.get_value() );

	char output_buffer[ buffer_size_constant ];
	const integer_value_type integer = integer_number.get_value();
	::sprintf( output_buffer, "%d", integer );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_integer_64( const Long_integer integer_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const long_integer_value_type integer = integer_number.get_value();
	::sprintf( output_buffer, "%lld", integer );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_natural_32( const Natural natural_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const natural_value_type natural = natural_number.get_value();
	::sprintf( output_buffer, "%u", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_natural_64( const Long_natural natural_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const long_natural_value_type natural = natural_number.get_value();
	::sprintf( output_buffer, "%llu", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_hexadecimal_32( const Natural hexadecimal_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const natural_value_type natural = hexadecimal_number.get_value();
	::sprintf( output_buffer, "%x", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_hexadecimal_64( const Long_natural hexadecimal_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const long_natural_value_type natural = hexadecimal_number.get_value();
	::sprintf( output_buffer, "%llx", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_real_double( const Real real_number ) noexept {
	char output_buffer[ buffer_size_constant ];
	const real_value_type real = real_number.get_value();
	::sprintf( output_buffer, "%G", real );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf


// #include "Aso.inl"


namespace jmsf {
namespace typing {


template<>
void Ansii_string_stream::put_integer( const Integers< internals::platform_signed_long_int > integer_number ) noexept {
	put_integer_64( integer_number );
}

template<>
void Ansii_string_stream::put_natural( const Naturals< internals::platform_unsigned_long_int > natural_number ) noexept {
	put_natural_64( natural_number );
}

template<>
void Ansii_string_stream::put_hexadecimal( const Integers< internals::platform_signed_long_int > hexadecimal_number ) noexept {
	const Long_natural natural_number = Long_natural::create( static_cast< long_natural_value_type >( hexadecimal_number.get_value() ) );
	put_hexadecimal_64( natural_number );
}

template<>
void Ansii_string_stream::put_hexadecimal( const Naturals< internals::platform_unsigned_long_int > hexadecimal_number ) noexept {
	put_hexadecimal_64( hexadecimal_number );
}

template<>
void Ansii_string_stream::put_real( const Reals< short_real_value_type > real_number ) noexept {
	put_real_double( Real::create( real_number.get_value() ) );
}


} // namespace typing
} // namespace jmsf
