#pragma once


#include "Reals.hpp"

#include "Boolean.h"


namespace jmsf {
namespace typing {


template< class A_type >
Reals< A_type > Reals< A_type >::get_absolute() const noexept {
	return Reals< A_type >( math_compute_absolute( _real_value ) );
}

template< class A_type >
Boolean Reals< A_type >::is_about_zero() const noexept {
	return math_is_about_zero( _real_value );
}

// math
template< class A_type >
Reals< A_type > Reals< A_type >::operator +( const Reals< A_type > &another ) const noexept {
	Reals< A_type > result = *this;
	result += another;
	return result;
}

template< class A_type >
Reals< A_type > &Reals< A_type >::operator +=( const Reals< A_type > &another ) noexept {
	_real_value += another._real_value;
	return *this;
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator -( const Reals< A_type > &another ) const noexept {
	Reals< A_type > result = *this;
	result -= another;
	return result;
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator -=( const Reals< A_type > &another ) noexept {
	_real_value -= another._real_value;
	return *this;
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator -() const noexept {
	return Real( -_real_value );
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator *( const Reals< A_type > &another ) const noexept {
	Reals< A_type > result = *this;
	result *= another;
	return result;
}

template< class A_type >
Reals< A_type > &Reals< A_type >::operator *=( const Reals< A_type > &another ) noexept {
	_real_value *= another._real_value;
	return *this;
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator /( const Reals< A_type > &another ) const {
	if ( another.is_about_zero() ) {
		// throw division by zero
	}

	Reals< A_type > result = *this;
	result *= another;
	return result;
}

template< class A_type >
Reals< A_type > &Reals< A_type >::operator /=( const Reals< A_type > &another ) {
	if ( another.is_about_zero() ) {
		// throw division by zero
	}

	_real_value *= another._real_value;
	return *this;
}

template< class A_type >
Reals< A_type > Reals< A_type >::operator %( const Reals< A_type > &another ) const {
	if ( another.is_about_zero() ) {
		// throw division by zero
	}

	Reals< A_type > result = *this;
	result %= another;
	return result;
}

template< class A_type >
Reals< A_type > &Reals< A_type >::operator %=( const Reals< A_type > &another ) {
	if ( another.is_about_zero() ) {
		// throw division by zero
	}

	_real_value  = ::fmod( math_compute_absolute( _real_value ), math_compute_absolute( another._real_value ) );
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
template< class A_type >
Boolean Reals< A_type >::operator ==( const Reals< A_type > &another ) const noexept {
	return math_are_almost_equal( _real_value, another._real_value );
}

template< class A_type >
Boolean Reals< A_type >::operator !=( const Reals< A_type > &another ) const noexept {
	return ( *this == another ).not();
}

template< class A_type >
Boolean Reals< A_type >::operator <( const Reals< A_type > &another ) const noexept {
	return math_are_almost_equal( _real_value, another._real_value ) ? False : Boolean::create( _real_value < another._real_value );
}

template< class A_type >
Boolean Reals< A_type >::operator <=( const Reals< A_type > &another ) const noexept {
	return math_are_almost_equal( _real_value, another._real_value ) ? True : Boolean::create( _real_value < another._real_value );
}

template< class A_type >
Boolean Reals< A_type >::operator >( const Reals< A_type > &another ) const noexept {
	return math_are_almost_equal( _real_value, another._real_value ) ? False : Boolean::create( _real_value > another._real_value );
}

template< class A_type >
Boolean Reals< A_type >::operator >=( const Reals< A_type > &another ) const noexept {
	return math_are_almost_equal( _real_value, another._real_value ) ? True : Boolean::create( _real_value > another._real_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Boolean Reals< A_type >::is_nill() const noexept {
	const Boolean is_this_real_zero = math_is_about_zero( _real_value );

	if ( is_this_real_zero ) {
		Reals< A_type > &non_constant_this = const_cast< Reals< A_type > & >( *this );
		non_constant_this._real_value = A_type( 0 );
	}

	return is_this_real_zero;
}

template< class A_type >
Boolean Reals< A_type >::is_not_nill() const noexept {
	return is_nill().not();
}

template< class A_type >
Boolean Reals< A_type >::is_positive() const noexept {
	return is_negative().not();
}

template< class A_type >
Boolean Reals< A_type >::is_negative() const noexept {
	if ( is_nill() ) return False;

	return Boolean::create( _real_value < A_type( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type Reals< A_type >::get_value() const noexept {
	return _real_value;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Reals< A_type >::~Reals() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Reals< A_type >::Reals() noexept {
	_real_value = A_type( 0 );
}

// static
template< class A_type >
Reals< A_type > Reals< A_type >::create( const A_type real_value ) noexept {
	return Reals< A_type >( real_value );
}

template< class A_type >
Reals< A_type >::Reals( const A_type real_value ) noexept {
	_real_value = real_value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Reals< A_type >::Reals( const Reals< A_type > &another ) noexept {
	_real_value = another._real_value;
}

template< class A_type >
const Reals< A_type > &Reals< A_type >::operator =( const Reals< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_real_value = another._real_value;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// statics
template< class A_type >
A_type Reals< A_type >::math_compute_absolute( const A_type real_value ) noexept {
	return real_value < A_type( 0 ) ? -real_value : real_value;
}

// template<>
// Boolean Reals< internals::platform_short_real >::math_is_about_zero( const internals::platform_short_real real_value ) noexept {
// 	return Boolean::create( !( math_compute_absolute( real_value ) > SHORT_REAL_DEFAULT_ACCURACY ) );
// }
// 
// template<>
// Boolean Reals< internals::platform_real >::math_is_about_zero( const internals::platform_real real_value ) noexept {
// 	return Boolean::create( !( math_compute_absolute( real_value ) > REAL_DEFAULT_ACCURACY ) );
// }

template< class A_type >
Boolean Reals< A_type >::math_are_almost_equal( const A_type real_value, const A_type another_real_value ) noexept {
	return math_is_about_zero( real_value - another_real_value );
}
//~statics


} // namespace typing
} // namespace jmsf
