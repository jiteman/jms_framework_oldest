#pragma once

#include "Ansii_string_stream.h"

#include "Integers.inl"
#include "Naturals.inl"
#include "Reals.inl"

//#include "Aso.inl"


namespace jmsf {
namespace typing {


template< class A_type >
void Ansii_string_stream::put_integer( const Integers< A_type > p_integer_number ) noexept {
	const Integer integer_number = Integer::create( p_integer_number.get_value() );
	put_integer_32( integer_number );
}

// template<>
// void Ansii_string_stream::put_integer( const Integers< internals::platform_signed_long_int > integer_number ) noexept {
// 	put_integer_64( integer_number );
// }

template< class A_type >
void Ansii_string_stream::put_natural( const Naturals< A_type > p_natural_number ) noexept {
	const Natural natural_number = Natural::create( p_natural_number.get_value() );
	put_natural_32( natural_number );
}

// template<>
// void Ansii_string_stream::put_natural( const Naturals< internals::platform_unsigned_long_int > natural_number ) noexept {
// 	put_natural_64( natural_number );
// }

// template< class A_type >
// void Ansii_string_stream::put_hexadecimal( const A_type hexadecimal_number ) noexept {
// 	const Natural natural_number = Natural::create( static_cast< natural_value_type >( hexadecimal_number.get_value() ) );
// 	put_hexadecimal_32( natural_number );
// }

// template<>
// void Ansii_string_stream::put_hexadecimal( const Integers< internals::platform_signed_long_int > hexadecimal_number ) noexept {
// 	const Long_natural natural_number = Long_natural::create( static_cast< long_natural_value_type >( hexadecimal_number.get_value() ) );
// 	put_hexadecimal_64( natural_number );
// }

// template<>
// void Ansii_string_stream::put_hexadecimal( const Naturals< internals::platform_unsigned_long_int > hexadecimal_number ) noexept {
// 	put_hexadecimal_64( hexadecimal_number );
// }

// template<>
// void Ansii_string_stream::put_real( const Reals< short_real_value_type > real_number ) noexept {
// 	put_real_double( Real::create( real_number.get_value() ) );
// }


} // namespace typing
} // namespace jmsf
