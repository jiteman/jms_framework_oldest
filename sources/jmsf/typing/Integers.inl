#pragma once


#include "Integers.hpp"

#include "Naturals.inl"


namespace jmsf {
namespace typing {

// math
template< class A_type >
Integers< A_type > Integers< A_type >::operator +( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result += another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator +=( const Integers< A_type > &another ) noexept {
	_integer_value += another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator -( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result -= another;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator -=( const Integers< A_type > &another ) noexept {
	_integer_value -= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator -() const noexept {
	return create( -_integer_value );
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator *( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result *= another._integer_value;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator *=( const Integers< A_type > &another ) noexept {
	_integer_value *= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator /( const Integers< A_type > &another ) const {
	if ( another._integer_value == A_type( 0 ) ) {
		// throw division by zero
	}

	Integers< A_type > result = *this;
	return result /= another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator /=( const Integers< A_type > &another ) {
	if ( another._integer_value == A_type( 0 ) ) {
		// throw division by zero
	}

	_integer_value /= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator %( const Integers< A_type > &another ) const {
	if ( another._integer_value == A_type( 0 ) ) {
		// throw division by zero
	}

	Integers< A_type > result = *this;
	return result %= another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator %=( const Integers< A_type > &another ) {
	if ( another._integer_value == A_type( 0 ) ) {
		// throw division by zero
	}

	if ( _integer_value < A_type( 0 ) ) {
		_integer_value = -_integer_value;
	}

	_integer_value %= another._integer_value < A_type( 0 ) ? -another._integer_value : another._integer_value;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
template< class A_type >
Integers< A_type > Integers< A_type >::operator ^( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result ^= another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator ^=( const Integers< A_type > &another ) noexept {
	_integer_value ^= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator &( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result &= another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator &=( const Integers< A_type > &another ) noexept {
	_integer_value &= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator |( const Integers< A_type > &another ) const noexept {
	Integers< A_type > result = *this;
	return result |= another;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator |=( const Integers< A_type > &another ) noexept {
	_integer_value |= another._integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator ~() const noexept {
	return Integers< A_type >( ~_integer_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
template< class A_type >
Boolean Integers< A_type >::operator ==( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value == another._integer_value );
}

template< class A_type >
Boolean Integers< A_type >::operator !=( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value != another._integer_value );
}

template< class A_type >
Boolean Integers< A_type >::operator <( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value < another._integer_value );
}

template< class A_type >
Boolean Integers< A_type >::operator <=( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value <= another._integer_value );
}

template< class A_type >
Boolean Integers< A_type >::operator >( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value > another._integer_value );
}

template< class A_type >
Boolean Integers< A_type >::operator >=( const Integers< A_type > &another ) const noexept {
	return Boolean::create( _integer_value >= another._integer_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
template< class A_type >
Integers< A_type > Integers< A_type >::get_shifted_left() const noexept {
	Integers< A_type > result = *this;
	return result.shift_left();
}

template< class A_type >
Integers< A_type > &Integers< A_type >::shift_left() noexept {
	_integer_value <<= Memory_size_one.get_value();
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator <<( const Memory_size shift_value ) const noexept {
	Integers< A_type > result = *this;
	return result <<= shift_value;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator <<=( const Memory_size shift_value ) noexept {
	_integer_value <<= shift_value.get_value();
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::get_shifted_right() const noexept {
	Integers< A_type > result = *this;
	return result.shift_right();
}

template< class A_type >
Integers< A_type > &Integers< A_type >::shift_right() noexept {
	_integer_value <<= Memory_size_one.get_value();
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator >>( const Memory_size shift_value ) const noexept {
	Integers< A_type < result = *this;
	return result >>= shift_value;
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator >>=( const Memory_size shift_value ) noexept {
	_integer_value >>= shift_value.get_value();
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
template< class A_type >
Integers< A_type > &Integers< A_type >::operator ++() noexept {
	++_integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator ++( int ) noexept {
	return Integers< A_type >( _integer_value++ );
}

template< class A_type >
Integers< A_type > &Integers< A_type >::operator --() noexept {
	--_integer_value;
	return *this;
}

template< class A_type >
Integers< A_type > Integers< A_type >::operator --( int ) noexept {
	return Integers< A_type >( _integer_value-- );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Boolean Integers< A_type >::is_nill() const noexept {
	return Boolean::create( _integer_value == A_type( 0 ) );
}

template< class A_type >
Boolean Integers< A_type >::is_not_nill() const noexept {
	return Boolean::create( _integer_value != A_type( 0 ) );
}

template< class A_type >
Boolean Integers< A_type >::is_positive() const noexept {
	return Boolean::create( _integer_value >= A_type( 0 ) );
}

template< class A_type >
Boolean Integers< A_type >::is_negative() const noexept {
	return Boolean::create( _integer_value < A_type( 0 ) );
}

template< class A_type >
Boolean Integers< A_type >::is_max() const noexept {
	return Boolean::create( _integer_value == ~A_type( 0 ) );
}

template< class A_type >
Boolean Integers< A_type >::is_not_max() const noexept {
	return Boolean::create( _integer_value != ~A_type( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	operator internals::platform_template_type() const noexept;
template< class A_type >
A_type Integers< A_type >::get_value() const noexept {
	return _integer_value;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Integers< A_type >::~Integers() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Integers< A_type >::Integers() noexept {
	_integer_value = A_type( 0 );
}

// static
template< class A_type >
Integers< A_type > Integers< A_type >::create( const A_type integer_value ) noexept {
	return Integers< A_type >( integer_value );
}

template< class A_type >
Integers< A_type >::Integers( A_type integer_value ) noexept {
	_integer_value = integer_value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Integers< A_type >::Integers( const Integers< A_type > &another ) noexept { // another
	_integer_value = another._integer_value;
}

template< class A_type >
const Integers< A_type > &Integers< A_type >::operator =( const Integers< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_integer_value = another._integer_value;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf
