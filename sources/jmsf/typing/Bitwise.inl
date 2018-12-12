#pragma once


#include "Bitwise.hpp"


#include "Naturals.inl"
#include "Aso.inl"
#include "internals/internal_types.h"


namespace jmsf {
namespace typing {


template< class A_type >
A_type Bitwise< A_type >::get_bits( const Memory_size source_start_bit, const Memory_size a_quantity ) const {
	if ( isInRange( source_start_bit, a_quantity ).not() ) {
		// throw 
	}
	const A_type value_mask = create_value_mask( a_quantity );
	const A_type bit_mask = create_bit_mask_from_value_mask( value_mask, source_start_bit );
	return ( _the_value & bit_mask ) >> source_start_bit;
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::set_bits( const Memory_size destination_start_bit, const Memory_size a_quantity ) {
	if ( isInRange( destination_start_bit, a_quantity ).not() ) {
		// throw
		return *this;
	}

	const A_type value_mask = create_value_mask( a_quantity );
	const A_type bit_mask = create_bit_mask_from_value_mask( value_mask, destination_start_bit );
	_the_value |= bit_mask;
	return *this;
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::reset_bits( const Memory_size destination_start_bit, const Memory_size a_quantity ) {
	if ( isInRange( destination_start_bit, a_quantity ).not() ) {
		// throw
		return *this;
	}

	const A_type value_mask = ~create_value_mask( a_quantity );
	const A_type bit_mask = create_bit_mask_from_value_mask( value_mask, destination_start_bit );
	_the_value &= bit_mask;
	return *this;
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::copy_bits_from( const Memory_size destination_start_bit, const A_type a_value, const Memory_size source_start_bit, const Memory_size a_quantity ) {
	if ( isInRange( source_start_bit, a_quantity).not() ) {
		// throw
		return *this;
	}

	if ( isInRange( destination_start_bit, a_quantity ).not() ) {
		// throw
	}

	const A_type source_value_mask = Bitwise< A_type >( a_value ).get_bits( source_start_bit, a_quantity );
	const A_type destination_bit_mask = create_bit_mask_from_value_mask( source_value_mask, destination_start_bit );
	reset_bits( destination_start_bit, a_quantity );
	_the_value |= destination_bit_mask;
	return *this;
}

template< class A_type >
Boolean Bitwise< A_type >::is_set( const Memory_size bit_index ) const {
	return Boolean::create( get_bits( bit_index, Memory_size_one ).is_not_nill() );
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::set( const Memory_size bit_index ) {
	set_bits( bit_index, Memory_size_one );
	return *this;
}

template< class A_type >
Boolean Bitwise< A_type >::is_reset( const Memory_size bit_index ) const {
	return Boolean::create( get_bits( bit_index, Memory_size_one ).is_nill() );
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::reset( const Memory_size bit_index ) {
	reset_bits( bit_index, Memory_size_one );
	return *this;
}

template< class A_type >
Boolean Bitwise< A_type >::get_status( const Memory_size bit_index ) const {
	return is_set( bit_index );
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::set_status( const Memory_size bit_index, const Boolean a_status ) const {
	if ( a_status ) {
		set( bit_index );
	} else {
		reset( bit_index );
	}

	return *this;
}

template< class A_type >
Memory_size Bitwise< A_type >::get_first_set_bit_index() const noexept {
	Memory_size result_index = Memory_size_badmax;

	if ( _the_value.is_nill() ) {		
	} else if ( _the_value.is_max() ) {
		result_index = Memory_size_nill;
	} else {
		A_type the_value = Bitwise< A_type >().set( Memory_size_nill ).get_value();

		for ( Shortest_natural counter = _bit_size_of< A_type >(); counter.is_not_nill(); --counter ) {
			if ( ( the_value & _the_value ) != A_type() ) {
				result_index = _bit_size_of< A_type >() - counter;
				break;
			}

			the_value.shift_left();
		}
	}

	return result_index;
}

template< class A_type >
Memory_size Bitwise< A_type >::get_last_set_bit_index() const noexept {
	Memory_size result_index = Memory_size_badmax;

	if ( _the_value.is_nill() ) {
	} else if ( _the_value.is_max() ) {
		result_index = --_bit_size_of< A_type >();
	} else { 
		A_type the_value = Bitwise< A_type >().set( --_bit_size_of< A_type >() ).get_value();

		for ( Memory_size counter = _bit_size_of< A_type >(); counter.is_not_nill(); --counter ) {
			if ( ( the_value & _the_value ) != A_type() ) {
				result_index = --counter;
				break;
			}

			the_value.shift_right();
		}
	}

	return result_index;
}

template< class A_type >
Memory_size Bitwise< A_type >::get_first_reset_bit_index() const noexept {
	Memory_size result_index = Memory_size_badmax;

	if ( _the_value.is_nill() ) {
		result_index = Memory_size_nill;
	} else if ( _the_value.is_max() ) {
	} else {
		A_type the_value = Bitwise< A_type >().set( Memory_size_nill ).get_value();

		for ( Memory_size counter = _bit_size_of< A_type >(); counter.is_not_nill(); --counter ) {
			if ( ( the_value & _the_value ) == A_type() ) {
				result_index = _bit_size_of< A_type >() - counter;
				break;
			}

			the_value.shift_left();
		}
	}

	return result_index;
}

template< class A_type >
Memory_size Bitwise< A_type >::get_last_reset_bit_index() const noexept {
	Memory_size result_index = Memory_size_badmax;

	if ( _the_value.is_nill() ) {
		result_index = --_bit_size_of< A_type >();
	} else if ( _the_value.is_max() ) {
	} else {
		A_type the_value = Bitwise< A_type >().set( --_bit_size_of< A_type >() ).get_value();

		for ( Memory_size counter = bit_size_of< A_type >(); counter.is_not_nill(); --counter ) {
			if ( ( the_value & _the_value ) == A_type() ) {
				result_index = --counter;
				break;
			}

			the_value.shift_right();
		}
	}

	return result_index;
}

template< class A_type >
Memory_size Bitwise< A_type >::get_quantity_of_bits() const noexept {
	return Shortest_natural::create( _bit_size_of< A_type >().get_value() );
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::clear() noexept {
	_the_value = A_type();
	return *this;
}

template< class A_type >
Bitwise< A_type > &Bitwise< A_type >::fill() noexept {
	_the_value = ~A_type();
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type Bitwise< A_type >::get_value() const noexept {
	return _the_value;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Bitwise< A_type >::~Bitwise() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Bitwise< A_type >::Bitwise() noexept
	:
		_the_value( A_type() )
{}

// static
template< class A_type >
Bitwise< A_type > Bitwise< A_type >::create( const A_type a_value ) noexept {
	return Bitwise( a_value );
}

template< class A_type >
Bitwise< A_type >::Bitwise( const A_type a_value ) noexept
	:
		_the_value( a_value )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Bitwise< A_type >::Bitwise( const Bitwise< A_type > &another ) noexept
	:
		_the_value( another._the_value )
{}

template< class A_type >
const Bitwise< A_type > &Bitwise< A_type >::operator =( const Bitwise< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_the_value = another._the_value;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
Boolean Bitwise< A_type >::isInRange( const Memory_size start_bit_index, const Memory_size a_quantity ) noexept {
	const Memory_size end_bit_index = start_bit_index + a_quantity;
	const Memory_size maximum_bit_index = --_bit_size_of< A_type >();

	return Boolean::create( !( end_bit_index > maximum_bit_index || start_bit_index > maximum_bit_index || start_bit_index > end_bit_index ) );
}

// static
template< class A_type >
A_type Bitwise< A_type >::create_value_mask( const Memory_size a_quantity ) noexept {
	return ~( A_type() ) >> ( _bit_size_of< A_type >() - a_quantity );
}

// static
template< class A_type >
A_type Bitwise< A_type >::create_bit_mask_from_value_mask( const A_type a_value, const Memory_size start_bit_index ) noexept {
	return a_value << start_bit_index;
}

} // namespace typing
} // namespace jmsf
