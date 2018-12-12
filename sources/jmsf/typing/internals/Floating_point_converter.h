#pragma once


#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {
namespace internals {


typedef size_t short_nat;
typedef unsigned __int64 long_nat;


class Floating_point_converter {

public:
	bool is_nill() const noexept;
	bool is_negative() const noexept;
	bool is_not_normalized() const noexept;
	bool is_infinity() const noexept;
	bool is_not_a_number() const noexept;
	bool is_another_special_case() const noexept;
	long_nat get_mantissa() const noexept;
	bool is_exponent_negative() const noexept;
	short_nat get_exponent() const noexept;

	Floating_point_converter get_converted_to_decimal() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Floating_point_converter() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Floating_point_converter() noexept;
	Floating_point_converter( float single_precision_floating_point ) noexept;
	Floating_point_converter( double double_precision_floating_point ) noexept;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Floating_point_converter( const Floating_point_converter &another ) noexept;
	const Floating_point_converter &operator =( const Floating_point_converter &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void detect_special_case( short_nat exponent, short_nat exponent_sign_value ) noexept;
	void normalize( long_nat mantissa_mask, size_t mantissa_bits ) noexept;
	void clear() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	bool _is_negative;
	long_nat _mantissa;
	bool _is_exponent_negative;
	short_nat _exponent;

	bool _is_not_normalized;
	bool _is_not_a_number;
	bool _is_nill;
	bool _is_positive_infinity;
	bool _is_negative_infinity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const size_t _float_sign_mask = 1;
	static const size_t _float_sign_shift = 31;
	static const size_t _float_exponent_mask = 0xFF;
	static const size_t _float_exponent_shift = 23;
	static const size_t _float_significand_mask = 0x7FFFFF;
	static const size_t _float_mantissa_bits = 23;
	static const size_t _float_significand_shift = 0;
	static const size_t _float_exponent_sign_number = 127;

	static const unsigned __int64 _double_sign_mask = 1;
	static const unsigned __int64 _double_sign_shift = 63;
	static const unsigned __int64 _double_exponent_mask = 0x7FF;
	static const unsigned __int64 _double_exponent_shift = 52;
	static const unsigned __int64 _double_significand_mask = 0x0FFFFFFFFFFFFF;
	static const long_nat _double_mantissa_bits = 52;
	static const size_t _double_significand_shift = 0;
	static const size_t _double_exponent_sign_number = 1023;

	static const long_nat _highest_bit = long_nat( 1 ) << 63;
	static const long_nat _lowest_bit = 1;

};


} // namespace internals
} // namespace typing
} // namespace jmsf
