#pragma once


#include "Bitwise.hpp"


#include "ShortestNatural.h"

#include "AlignmentAndSize.hpp"
#include "internals/internal_types.h"


namespace jmsf {
namespace types {


template< A_type >
A_type Bitwise< A_type >::getBits( const ShortestNatural startBitIndex, const ShortestNatural quantityOfBits ) const throw( Exception ) {
	if ( isInRange().not() ) {
		// throw 
	}

	const A_type valueMask = ~( A_type() ) >> ( BitSizeOf( A_type ) - quantityOfBits );
	const A_type bitMask = valueMask << startBitIndex;
	return ( _typeValue & bitMask ) >> startBitIndex;
}

template< A_type >
void Bitwise< A_type >::setBits( const A_type typeValue, const ShortestNatural startBitIndex, const ShortestNatural quantityOfBits ) throw( Exception ) {
	if ( isInRange().not() ) {
	}

	const A_type valueMask = ~( A_type() ) >> ( BitSizeOf( A_type ) - quantityOfBits );
	const A_type bitMask = valueMask << startBitIndex;
	_typeValue = ( ( _typeValue & ~bitMask ) || ( ( typeValue & valueMask ) << startBitIndex ) );	
}

template< A_type >
void Bitwise< A_type >::clear() throw() {
	_typeValue = A_type();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
A_type Bitwise< A_type >::getValue() const throw() {
	return _typeValue;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< A_type >
Bitwise< A_type >::~Bitwise() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
Bitwise< A_type >::Bitwise() throw()
{}

// static
template< A_type >
Bitwise Bitwise::create( const A_type typeValue ) throw() {
	return Bitwise( typeValue );
}

template< A_type >
Bitwise< A_type >::Bitwise( const A_type typeValue ) throw()
	:
		_typeValue( typeValue )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
Bitwise< A_type >::Bitwise( const Bitwise< A_type > & ) throw() { // other
}

template< A_type >
const Bitwise< A_type > &Bitwise< A_type >::operator =( const Bitwise< A_type > &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< A_type >
Boolean Bitwise< A_type >::isInRange( const ShortestNatural startBitIndex, const ShortestNatural quantityOfBits ) {
	const Natural naturalStartBitIndex = Natural::create( startBitIndex.getPlatformValue() );
	const Natural naturalQuantityOfBits = Natural::create( quantityOfBits.getPlatformValue() );
	const Natural maximumBitSize = Natural::create( CHAR_BIT_SIZE * sizeof( A_type ) );

	if ( naturalQuantityOfBits > maximumBitSize ) return False;

	if ( naturalStartBitIndex > maximumBitSize - 1 ) return False;

	if ( naturalStartBitIndex + naturalQuantityOfBits > maximumBitSize - 1 ) return False;

	return True;
}


} // namespace types
} // namespace jmsf
