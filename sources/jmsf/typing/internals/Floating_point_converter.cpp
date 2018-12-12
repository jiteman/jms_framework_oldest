#include "Floating_point_converter.h"

#include <cmath>


namespace jmsf {
namespace typing {
namespace internals {


template< class A_type >
A_type get_bits( const A_type where_from, const A_type bit_mask, const size_t bit_shift ) noexept {
	return ( where_from >> bit_shift ) & bit_mask;
}

template< class A_type >
A_type set_bits( const A_type where_to, const A_type bits, const size_t bit_shift ) noexept {
	return ( bits << bit_shift ) | where_to;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool Floating_point_converter::is_nill() const noexept {
	return _is_nill;
}

bool Floating_point_converter::is_negative() const noexept {
	return _is_negative;
}

bool Floating_point_converter::is_not_normalized() const noexept {
	return _is_not_normalized;
}

bool Floating_point_converter::is_infinity() const noexept {
	return _is_positive_infinity || _is_negative_infinity;
}

bool Floating_point_converter::is_not_a_number() const noexept {
	return _is_not_a_number;
}

bool Floating_point_converter::is_another_special_case() const noexept {
	return is_infinity() || is_not_a_number();
}

long_nat Floating_point_converter::get_mantissa() const noexept {
	return _mantissa;
}

bool Floating_point_converter::is_exponent_negative() const noexept {
	return _is_exponent_negative;
}

short_nat Floating_point_converter::get_exponent() const noexept {
	return _exponent;
}

Floating_point_converter Floating_point_converter::get_converted_to_decimal() const noexept {
	Floating_point_converter result = *this;

	// preventing high presicion loss at the ranges
	const int exponent = is_exponent_negative() ? -static_cast< int >( _exponent ) : static_cast< int >( _exponent );
	const int first_half_of_exponent = exponent / 2;
	const int second_half_of_exponent = exponent - first_half_of_exponent;

	const double decimal_exponent = ::log10( ::pow( 2.0, first_half_of_exponent ) ) + ::log10( ::pow( 2.0, second_half_of_exponent ) );
	const double integer_part_of_decimal_exponent = static_cast< int >( decimal_exponent );
	const double fraction_part_of_decimal_exponent = decimal_exponent - integer_part_of_decimal_exponent;
	const double decimal_multiplier = ::pow( 10.0, fraction_part_of_decimal_exponent );
//		const double inversion_of_decimal_multiplier = 1.0 / decimal_multiplier;
		
//		long_nat result_mantissa = static_cast< long_nat >( result.get_mantissa() / inversion_of_decimal_multiplier );
	long_nat result_mantissa = static_cast< long_nat >( result.get_mantissa() * decimal_multiplier );
	int decimal_integer_part_of_decimal_exponent = static_cast< int >( integer_part_of_decimal_exponent );

	while ( ( result_mantissa % 10 ) == 0 ) {
		result_mantissa /= 10;
		++decimal_integer_part_of_decimal_exponent;
	}

	const bool result_is_decimal_exponent_negative = decimal_integer_part_of_decimal_exponent < 0;
	const size_t result_integer_part_of_decimal_exponent = result_is_decimal_exponent_negative ? static_cast< size_t >( -decimal_integer_part_of_decimal_exponent ) : static_cast< size_t >( decimal_integer_part_of_decimal_exponent );
	result._mantissa = result_mantissa;
	result._is_exponent_negative = result_is_decimal_exponent_negative;
	result._exponent = result_integer_part_of_decimal_exponent;
	return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Floating_point_converter::~Floating_point_converter() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Floating_point_converter::Floating_point_converter() noexept {
	clear();
}

Floating_point_converter::Floating_point_converter( const float single_precision_floating_point ) noexept {
	clear();
	const short_nat bits_of_spfp = *reinterpret_cast< const short_nat * >( &single_precision_floating_point );
	_is_negative = get_bits( bits_of_spfp, _float_sign_mask, _float_sign_shift ) != 0;
	_mantissa = get_bits( bits_of_spfp, _float_significand_mask, _float_significand_shift );
	const int exponent = static_cast< int >( get_bits( bits_of_spfp, _float_exponent_mask, _float_exponent_shift ) ) - static_cast< int >( _float_exponent_sign_number );
	_is_exponent_negative = exponent < 0;
	_exponent = static_cast< short_nat >( exponent < 0 ? -exponent : exponent );

// 		short_nat result = 0;
// 		result = set_bits( result, is_negative() ? _float_sign_mask : 0, _float_sign_shift );
// 		result = set_bits( result, static_cast< short_nat >( _mantissa ), _float_significand_shift );
// 		result = set_bits( result, static_cast< short_nat >( ( is_exponent_negative() ? -static_cast< int >( _exponent ) : static_cast< int >( _exponent ) ) + static_cast< int >( _float_exponent_sign_number ) ), _float_exponent_shift );
// 		const float original = *reinterpret_cast< const float * >( &result );

	detect_special_case( _float_exponent_mask, _float_exponent_sign_number );

	if ( is_nill() || is_another_special_case() ) return;
		
	normalize( _float_significand_mask, _float_mantissa_bits );
}

Floating_point_converter::Floating_point_converter( const double double_precision_floating_point ) noexept {
	clear();
	const long_nat bits_of_dpfp = *reinterpret_cast< const long_nat * >( &double_precision_floating_point );
	_is_negative = get_bits( bits_of_dpfp, _double_sign_mask, _double_sign_shift ) != 0;
	_mantissa = get_bits( bits_of_dpfp, _double_significand_mask, _double_significand_shift );
	const int exponent = static_cast< int >( get_bits( bits_of_dpfp, _double_exponent_mask, _double_exponent_shift ) ) - static_cast< int >( _double_exponent_sign_number );
	_is_exponent_negative = exponent < 0;
	_exponent = static_cast< short_nat >( exponent < 0 ? -exponent : exponent );

// 		long_nat result = 0;
// 		result = set_bits( result, is_negative() ? _double_sign_mask : 0, _double_sign_shift );
// 		result = set_bits( result, static_cast< long_nat >( _mantissa ), _double_significand_shift );
// 		result = set_bits( result, static_cast< long_nat >( ( is_exponent_negative() ? -static_cast< int >( _exponent ) : static_cast< int >( _exponent ) ) + static_cast< int >( _double_exponent_sign_number ) ), _double_exponent_shift );
// 		const double original = *reinterpret_cast< const double * >( &result );

	detect_special_case( _double_exponent_mask, _double_exponent_sign_number );

	if ( is_nill() || is_another_special_case() ) return;

	normalize( _double_significand_mask, _double_mantissa_bits );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Floating_point_converter::Floating_point_converter( const Floating_point_converter &another ) noexept { // another
	_is_negative = another._is_negative;
	_mantissa = another._mantissa;
	_is_exponent_negative = another._is_exponent_negative;
	_exponent = another._exponent;
	_is_not_normalized = another._is_not_normalized;
	_is_not_a_number = another._is_not_a_number;
	_is_nill = another._is_nill;
	_is_positive_infinity = another._is_positive_infinity;
	_is_negative_infinity = another._is_negative_infinity;
}

const Floating_point_converter &Floating_point_converter::operator =( const Floating_point_converter &another ) noexept {
	if ( &another == this ) return *this;

	_is_negative = another._is_negative;
	_mantissa = another._mantissa;
	_is_exponent_negative = another._is_exponent_negative;
	_exponent = another._exponent;
	_is_not_normalized = another._is_not_normalized;
	_is_not_a_number = another._is_not_a_number;
	_is_nill = another._is_nill;
	_is_positive_infinity = another._is_positive_infinity;
	_is_negative_infinity = another._is_negative_infinity;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
void Floating_point_converter::detect_special_case( const short_nat exponent, const short_nat exponent_sign_value ) noexept {
	if ( _is_exponent_negative && _exponent == exponent_sign_value && _mantissa == 0 ) {
		_is_nill = true;
	} else if ( _is_exponent_negative && _exponent == exponent_sign_value ) {
		_is_not_normalized = true;
	} else if ( _exponent == ( exponent - exponent_sign_value ) ) {
		if ( _mantissa == 0 ) {
			if ( _is_negative ) {
				_is_negative_infinity = true;
			} else {
				_is_positive_infinity = true;
			}
		} else {
			_is_not_a_number = true;
		}
	}
}

void Floating_point_converter::normalize( const long_nat mantissa_mask, const size_t mantissa_bits ) noexept {
	if ( is_not_normalized() ) {
		--_exponent;
	} else {
		_mantissa = _mantissa | ( mantissa_mask + 1 );
	}

	int temporary_exponent = ( is_exponent_negative() ? -static_cast< int >( _exponent ) : static_cast< int >( _exponent ) ) - static_cast< int >( mantissa_bits );
		
	while ( ( _mantissa & _lowest_bit ) == 0 ) {
		_mantissa >>= 1;
		++temporary_exponent;
	}

	_is_exponent_negative = temporary_exponent < 0;
	_exponent = static_cast< size_t >( _is_exponent_negative ? -temporary_exponent : temporary_exponent );
}

void Floating_point_converter::clear() noexept {
	_is_negative = false;
	_mantissa = 0;
	_is_exponent_negative = false;
	_exponent = 0;

	_is_not_normalized = false;
	_is_not_a_number = false;
	_is_nill = false;
	_is_positive_infinity = false;
	_is_negative_infinity = false;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace internals
} // namespace typing
} // namespace jmsf
