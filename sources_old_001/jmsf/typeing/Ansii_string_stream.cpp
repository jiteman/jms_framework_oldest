#include "Ansii_string_stream.h"

//#include "internals/String_input_and_output.h"

#include "Integers.hin"
#include "Naturals.hin"
#include "Reals.hin"
#include "jmsf/structing/containing/List.hin"
#include "jmsf/structing/traversing/List_traverser.hin"
#include "jmsf/validating/Should.h"
#include "jmsf/validating/logging_macroses.h"

#include <cstdio>


namespace jmsf {
namespace typeing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Ansii_string_stream::put_string( const Ansii_string &a_string ) {
	if ( a_string.is_not_empty() ) {
		//Ansii_string ansii_string = Ansii_string::create_from_another( _character_array_allocator, a_string );
		_ansii_string_list.append_to_end( _list_node_allocator, Ansii_string::create_from_another( _character_array_allocator, a_string ) );
	}
}

void Ansii_string_stream::put_character( const Ansii_character &/*a_character*/ ) noexcept {

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const structing::containing::List< Ansii_string > &Ansii_string_stream::get_ansii_string_list() const noexcept {
	return _ansii_string_list;
}

Ansii_string Ansii_string_stream::create_consolidated_ansii_string_( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( character_array_allocator.is_empty(), "Ansii_string_stream::create_consolidated_ansii_string( allocator )" );
	jmsf_Should_never_be_null( character_array_allocator );

	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( _ansii_string_list.is_empty(), "Ansii_string_stream::create_consolidated_ansii_string( allocator )" );
	jmsf_Should_never_be( _ansii_string_list.is_empty() );
	return Ansii_string::create_from_list( character_array_allocator, _ansii_string_list );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_string_stream::~Ansii_string_stream() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
Ansii_string_stream Ansii_string_stream::create( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept {
	return Ansii_string_stream( character_array_allocator, list_node_allocator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string_stream::Ansii_string_stream( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept
	:
		_character_array_allocator( character_array_allocator ),
		_list_node_allocator( list_node_allocator )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string_stream::Ansii_string_stream( const Ansii_string_stream &another ) noexcept
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

const Ansii_string_stream &Ansii_string_stream::operator =( const Ansii_string_stream &another ) noexcept {
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
static const memory_natural_value_type buffer_size_constant = 40;

void Ansii_string_stream::put_integer_32( const Integer integer_number ) noexcept {
	char output_buffer[ buffer_size_constant ];
	const internals::platform_small_integer integer = static_cast< internals::platform_small_integer >( integer_number.get_native_value() );
	::sprintf( output_buffer, "%d", integer );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_integer_64( const Long_integer integer_number ) noexcept {
	char output_buffer[ buffer_size_constant ];

#if defined( JMSF_MEMORY_MODEL_IS_LP64 )
	::sprintf( output_buffer, "%ld", integer_number.get_native_value() );

#elif defined( JMSF_MEMORY_MODEL_IS_ILP32 )
	::sprintf( output_buffer, "%lld", integer_number.get_native_value() );

#else
	#error This file "jmsf/typeing/Ansii_string_stream.cpp" - no supported memory model detected.

#endif

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_natural_32( const Natural natural_number ) noexcept {
	char output_buffer[ buffer_size_constant ];
	const internals::platform_small_natural natural = static_cast< internals::platform_small_natural >( natural_number.get_native_value() );
	::sprintf( output_buffer, "%u", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_natural_64( const Long_natural natural_number ) noexcept {
	char output_buffer[ buffer_size_constant ];

#if defined( JMSF_MEMORY_MODEL_IS_LP64 )
	::sprintf( output_buffer, "%lu", natural_number.get_native_value() );

#elif defined( JMSF_MEMORY_MODEL_IS_ILP32 )
	::sprintf( output_buffer, "%llu", natural_number.get_native_value() );

#else
	#error This file "jmsf/typeing/Ansii_string_stream.cpp" - no supported memory model detected.

#endif

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_hexadecimal_32( const Natural hexadecimal_number ) noexcept {
	char output_buffer[ buffer_size_constant ];
	const internals::platform_small_natural natural = static_cast< internals::platform_small_natural >( hexadecimal_number.get_native_value() );
	::sprintf( output_buffer, "%x", natural );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_hexadecimal_64( const Long_natural hexadecimal_number ) noexcept {
	char output_buffer[ buffer_size_constant ];

#if defined( JMSF_MEMORY_MODEL_IS_LP64 )
	::sprintf( output_buffer, "%lu", hexadecimal_number.get_native_value() );

#elif defined( JMSF_MEMORY_MODEL_IS_ILP32 )
	::sprintf( output_buffer, "%llu", hexadecimal_number.get_native_value() );

#else
	#error This file "jmsf/typeing/Ansii_string_stream.cpp" - no supported memory model detected.

#endif

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

void Ansii_string_stream::put_real_double( const Real real_number ) noexcept {
	char output_buffer[ buffer_size_constant ];
	const real_value_type real = real_number.get_native_value();
	::sprintf( output_buffer, "%G", real );

	Ansii_string ansii_string = Ansii_string::create_from_c_language_string( _character_array_allocator, output_buffer );
	_ansii_string_list.append_to_end( _list_node_allocator, ansii_string );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typeing
} // namespace jmsf


// #include "Aso.inl"


namespace jmsf {
namespace typeing {


template<>
void Ansii_string_stream::put_integer( const Long_integer integer_number ) noexcept {
	put_integer_64( integer_number );
}

template<>
void Ansii_string_stream::put_natural( const Long_natural natural_number ) noexcept {
	put_natural_64( natural_number );
}

//template<>
//void Ansii_string_stream::put_hexadecimal( const Long_integer hexadecimal_number ) noexcept {
//	const Long_natural natural_number = Long_natural::create( static_cast< long_natural_value_type >( hexadecimal_number.get_value() ) );
//	put_hexadecimal_64( natural_number );
//}

template<>
void Ansii_string_stream::put_hexadecimal( const Long_natural hexadecimal_number ) noexcept {
	put_hexadecimal_64( hexadecimal_number );
}

template<>
void Ansii_string_stream::put_real( const Short_real real_number ) noexcept {
	put_real_double( Real::create( real_number.get_native_value() ) );
}


} // namespace typeing
} // namespace jmsf
