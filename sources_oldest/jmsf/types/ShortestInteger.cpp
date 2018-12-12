#include "ShortestInteger.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
ShortestInteger ShortestInteger::operator +( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger + other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator +=( const ShortestInteger &other ) throw() {
	_shortestInteger += other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator -( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger - other._shortestInteger );
}

ShortestInteger ShortestInteger::operator -=( const ShortestInteger &other ) throw() {
	_shortestInteger -= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator -() const throw() {
	return -_shortestInteger;
}

ShortestInteger ShortestInteger::operator *( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger * other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator *=( const ShortestInteger &other ) throw() {
	_shortestInteger *= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator /( const ShortestInteger &other ) const throw( Exception ) {
	if ( other._shortestInteger == internals::platform_signed_char( 0 ) ) {
		// throw division by zero
	}

	return ShortestInteger( _shortestInteger / other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator /=( const ShortestInteger &other ) throw( Exception ) {
	if ( other._shortestInteger == internals::platform_signed_char( 0 ) ) {
		// throw division by zero
	}

	_shortestInteger /= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator %( const ShortestInteger &other ) const throw( Exception ) {
	if ( other._shortestInteger == internals::platform_signed_char( 0 ) ) {
		// throw division by zero
	}

	return ShortestInteger( _shortestInteger % other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator %=( const ShortestInteger &other ) throw( Exception ) {
	if ( other._shortestInteger == internals::platform_signed_char( 0 ) ) {
		// throw division by zero
	}

	_shortestInteger %= other._shortestInteger;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
ShortestInteger ShortestInteger::operator ^( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger ^ other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator ^=( const ShortestInteger &other ) throw() {
	_shortestInteger ^= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator &( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger & other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator &=( const ShortestInteger &other ) throw() {
	_shortestInteger &= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator |( const ShortestInteger &other ) const throw() {
	return ShortestInteger( _shortestInteger | other._shortestInteger );
}

ShortestInteger &ShortestInteger::operator |=( const ShortestInteger &other ) throw() {
	_shortestInteger |= other._shortestInteger;
	return *this;
}

ShortestInteger ShortestInteger::operator ~() const throw() {
	return ShortestInteger( ~_shortestInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// ShortestInteger ShortestInteger::operator !() const throw() {
// 	return ShortestInteger( !_smallestInteger );
// }
// 
// ShortestInteger ShortestInteger::operator &&( const ShortestInteger &other ) const throw() {
// 	return ShortestInteger( _smallestInteger && other._smallestInteger );
// }
// 
// ShortestInteger ShortestInteger::operator ||( const ShortestInteger &other ) const throw() {
// 	return ShortestInteger( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean ShortestInteger::operator ==( const ShortestInteger &other ) const throw() {
	return Boolean::create( _shortestInteger == other._shortestInteger );
}

Boolean ShortestInteger::operator !=( const ShortestInteger &other ) const throw() {
	return operator ==( other._shortestInteger ).not();
}

Boolean ShortestInteger::operator <( const ShortestInteger &other ) const throw() {
	return Boolean::create( _shortestInteger < other._shortestInteger );
}

Boolean ShortestInteger::operator <=( const ShortestInteger &other ) const throw() {
	return Boolean::create( _shortestInteger <= other._shortestInteger );
}

Boolean ShortestInteger::operator >( const ShortestInteger &other ) const throw() {
	return Boolean::create( _shortestInteger > other._shortestInteger );
}

Boolean ShortestInteger::operator >=( const ShortestInteger &other ) const throw() {
	return Boolean::create( _shortestInteger >= other._shortestInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
ShortestInteger ShortestInteger::operator <<( const ShortestNatural &other ) const throw() {
	return ShortestInteger( _shortestInteger << other.getPlatformValue() );
}

ShortestInteger &ShortestInteger::operator <<=( const ShortestNatural &other ) throw() {
	_shortestInteger <<= other.getPlatformValue();
	return *this;
}

ShortestInteger ShortestInteger::operator >>( const ShortestNatural &other ) const throw() {
	return ShortestInteger( _shortestInteger >> other.getPlatformValue() );
}

ShortestInteger &ShortestInteger::operator >>=( const ShortestNatural &other ) throw() {
	_shortestInteger >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
ShortestInteger &ShortestInteger::operator ++() throw() {
	_shortestInteger += 1;
	return *this;
}

ShortestInteger ShortestInteger::operator ++( int ) throw() {
	const internals::platform_signed_char shortestInteger = _shortestInteger;
	_shortestInteger += 1;
	return ShortestInteger( shortestInteger );
}

ShortestInteger &ShortestInteger::operator --() throw() {
	_shortestInteger -= 1;
	return *this;
}

ShortestInteger ShortestInteger::operator --( int ) throw() {
	const internals::platform_signed_char shortestInteger = _shortestInteger;
	_shortestInteger -= 1;
	return ShortestInteger( shortestInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// access
// 	ret_type &operator *() throw();
// 	const ret_type &operator *() const throw();
// 	ret_type *operator ->() throw();
// 	const ret_type *operator ->() const throw();
	
// 	ret_type &operator []( Unsigned index ) throw();
// 	const ret_type &operator []( Unsigned index ) const throw();
		
// 	ret_type operator()( parameters ) const throw();
// 	ret_type operator()( parameters ) throw();

//	operator ->*(); // pointer-to-member selection

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean ShortestInteger::isNull() const throw() {
	return Boolean( _shortestInteger == internals::platform_unsigned_char( 0 ) );
}

Boolean ShortestInteger::isNotNull() const throw() {
	return isNull().not();
}

Boolean ShortestInteger::isPositive() const throw() {
	return isNegative().not();
}

Boolean ShortestInteger::isNegative() const throw() {
	return Boolean( _shortestInteger < internals::platform_unsigned_char( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ShortestInteger::operator internals::platform_signed_char() const throw() {
// 	return _boolValue;
// }

internals::platform_signed_char ShortestInteger::getPlatformValue() const throw() {
	return _shortestInteger;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ShortestInteger::~ShortestInteger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortestInteger::ShortestInteger() throw() {
	_shortestInteger = internals::platform_signed_char( 0 );
}

// static
ShortestInteger ShortestInteger::create( const internals::platform_signed_char shortestInteger /*= default*/ ) {
	return ShortestInteger( shortestInteger );
}


ShortestInteger::ShortestInteger( const internals::platform_signed_char shortestInteger ) throw() {
	_shortestInteger = shortestInteger;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortestInteger::ShortestInteger( const ShortestInteger &other ) throw() {
	_shortestInteger = other._shortestInteger;
}

const ShortestInteger &ShortestInteger::operator =( const ShortestInteger &other ) throw() {
	if ( &other != this ) {
		_shortestInteger = other._shortestInteger;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
