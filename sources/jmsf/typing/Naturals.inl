#pragma once


#include "Naturals.hpp"

#include "Boolean.h"


namespace jmsf {
namespace typing {


// math
template< class A_type >
Naturals< A_type > Naturals< A_type >::operator +( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result += another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator +=( const Naturals< A_type > &another ) noexept {
	_natural_value += another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator -( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result -= another;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator -=( const Naturals< A_type > &another ) noexept {
	_natural_value -= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator *( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result *= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator *=( const Naturals< A_type > &another ) noexept {
	_natural_value *= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator /( const Naturals< A_type > &another ) const {
	if ( another._natural_value == A_type( 0 ) ) {
		// throw division by zero
	}

	Naturals< A_type > result = *this;
	return result /= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator /=( const Naturals< A_type > &another ) {
	if ( another._natural_value == A_type( 0 ) ) {
		// throw division by zero
	}

	_natural_value /= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator %( const Naturals< A_type > &another ) const {
	if ( another._natural_value == A_type( 0 ) ) {
		// throw division by zero
	}

	Naturals< A_type > result = *this;
	return result %= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator %=( const Naturals< A_type > &another ) {
	if ( another._natural_value == A_type( 0 ) ) {
		// throw division by zero
	}

	_natural_value %= another._natural_value;
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
template< class A_type >
Naturals< A_type > Naturals< A_type >::operator ^( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result ^= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator ^=( const Naturals< A_type > &another ) noexept {
	_natural_value ^= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator &( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result &= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator &=( const Naturals< A_type > &another ) noexept {
	_natural_value ^= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator |( const Naturals< A_type > &another ) const noexept {
	Naturals< A_type > result = *this;
	return result |= another;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator |=( const Naturals< A_type > &another ) noexept {
	_natural_value |= another._natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator ~() const noexept {
	return Naturals< A_type >( static_cast< A_type >( ~_natural_value ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
template< class A_type >
Boolean Naturals< A_type >::operator ==( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value == another._natural_value );
}

template< class A_type >
Boolean Naturals< A_type >::operator !=( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value != another._natural_value );
}

template< class A_type >
Boolean Naturals< A_type >::operator <( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value < another._natural_value );
}

template< class A_type >
Boolean Naturals< A_type >::operator <=( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value <= another._natural_value );
}

template< class A_type >
Boolean Naturals< A_type >::operator >( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value > another._natural_value );
}

template< class A_type >
Boolean Naturals< A_type >::operator >=( const Naturals< A_type > &another ) const noexept {
	return Boolean::create( _natural_value >= another._natural_value );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
template< class A_type >
Naturals< A_type > Naturals< A_type >::get_shifted_left() const noexept {
	Naturals< A_type > result = *this;
	return result.shift_left();
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::shift_left() noexept {
	_natural_value <<= Memory_size_one.get_value();
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator <<( const Memory_size shift_value ) const noexept {
	Naturals< A_type > result = *this;
	result <<= shift_value;
	return result;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator <<=( const Memory_size shift_value ) noexept {
	_natural_value <<= shift_value.get_value();
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::get_shifted_right() const noexept {
	Naturals< A_type > result = *this;
	return result.shift_right();
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::shift_right() noexept {
	_natural_value >>= Memory_size_one.get_value();
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator >>( const Memory_size shift_value ) const noexept {
	Naturals< A_type > result = *this;
	result >>= shift_value;
	return result;
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator >>=( const Memory_size shift_value ) noexept {
	_natural_value >>= shift_value.get_value();
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator ++() noexept {
	++_natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator ++( int ) noexept {
	return Naturals( _natural_value++ );
}

template< class A_type >
Naturals< A_type > &Naturals< A_type >::operator --() noexept {
	--_natural_value;
	return *this;
}

template< class A_type >
Naturals< A_type > Naturals< A_type >::operator --( int ) noexept {
	return Naturals( _natural_value-- );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Boolean Naturals< A_type >::is_nill() const noexept {
	return Boolean::create( _natural_value == A_type( 0 ) );
}

template< class A_type >
Boolean Naturals< A_type >::is_not_nill() const noexept {
	return Boolean::create( _natural_value != A_type( 0 ) );
}

template< class A_type >
Boolean Naturals< A_type >::is_max() const noexept {
	return Boolean::create( _natural_value == ~A_type( 0 ) );
}

template< class A_type >
Boolean Naturals< A_type >::is_not_max() const noexept {
	return Boolean::create( _natural_value != ~A_type( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	operator internals::platform_unsigned_char() const noexept;
template< class A_type >
A_type Naturals< A_type >::get_value() const noexept {
	return _natural_value;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Naturals< A_type >::~Naturals() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Naturals< A_type >::Naturals() noexept {
	_natural_value = A_type( 0 );
}

// static
template< class A_type >
Naturals< A_type > Naturals< A_type >::create( const A_type natural_value ) noexept {
	return Naturals< A_type >( natural_value );
}

template< class A_type >
Naturals< A_type >::Naturals( A_type natural_value ) noexept {
	_natural_value = natural_value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Naturals< A_type >::Naturals( const Naturals< A_type > &another ) noexept {
	_natural_value = another._natural_value;
}

template< class A_type >
const Naturals< A_type > &Naturals< A_type >::operator =( const Naturals< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_natural_value = another._natural_value;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


template< class A_type >
A_type *get_pointer_from_memory_size( const Memory_size memory_address ) noexept {
	return reinterpret_cast< A_type * >( memory_address.get_value() );
}


} // namespace typing
} // namespace jmsf
