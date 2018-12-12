#include "ShortInteger.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
ShortInteger ShortInteger::operator +( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger + other._shortInteger );
}

ShortInteger &ShortInteger::operator +=( const ShortInteger &other ) throw() {
	_shortInteger += other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator -( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger - other._shortInteger );
}

ShortInteger ShortInteger::operator -=( const ShortInteger &other ) throw() {
	_shortInteger -= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator -() const throw() {
	return -_shortInteger;
}

ShortInteger ShortInteger::operator *( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger * other._shortInteger );
}

ShortInteger &ShortInteger::operator *=( const ShortInteger &other ) throw() {
	_shortInteger *= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator /( const ShortInteger &other ) const throw( Exception ) {
	if ( other._shortInteger == internals::platform_signed_short_int( 0 ) ) {
		// throw division by zero
	}

	return ShortInteger( _shortInteger / other._shortInteger );
}

ShortInteger &ShortInteger::operator /=( const ShortInteger &other ) throw( Exception ) {
	if ( other._shortInteger == internals::platform_signed_short_int( 0 ) ) {
		// throw division by zero
	}

	_shortInteger /= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator %( const ShortInteger &other ) const throw( Exception ) {
	if ( other._shortInteger == internals::platform_signed_short_int( 0 ) ) {
		// throw division by zero
	}

	return ShortInteger( _shortInteger % other._shortInteger );
}

ShortInteger &ShortInteger::operator %=( const ShortInteger &other ) throw( Exception ) {
	if ( other._shortInteger == internals::platform_signed_short_int( 0 ) ) {
		// throw division by zero
	}

	_shortInteger %= other._shortInteger;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
ShortInteger ShortInteger::operator ^( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger ^ other._shortInteger );
}

ShortInteger &ShortInteger::operator ^=( const ShortInteger &other ) throw() {
	_shortInteger ^= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator &( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger & other._shortInteger );
}

ShortInteger &ShortInteger::operator &=( const ShortInteger &other ) throw() {
	_shortInteger &= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator |( const ShortInteger &other ) const throw() {
	return ShortInteger( _shortInteger | other._shortInteger );
}

ShortInteger &ShortInteger::operator |=( const ShortInteger &other ) throw() {
	_shortInteger |= other._shortInteger;
	return *this;
}

ShortInteger ShortInteger::operator ~() const throw() {
	return ShortInteger( ~_shortInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// ShortInteger ShortInteger::operator !() const throw() {
// 	return ShortInteger( !_smallestInteger );
// }
// 
// ShortInteger ShortInteger::operator &&( const ShortInteger &other ) const throw() {
// 	return ShortInteger( _smallestInteger && other._smallestInteger );
// }
// 
// ShortInteger ShortInteger::operator ||( const ShortInteger &other ) const throw() {
// 	return ShortInteger( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean ShortInteger::operator ==( const ShortInteger &other ) const throw() {
	return Boolean::create( _shortInteger == other._shortInteger );
}

Boolean ShortInteger::operator !=( const ShortInteger &other ) const throw() {
	return operator ==( other._shortInteger ).not();
}

Boolean ShortInteger::operator <( const ShortInteger &other ) const throw() {
	return Boolean::create( _shortInteger < other._shortInteger );
}

Boolean ShortInteger::operator <=( const ShortInteger &other ) const throw() {
	return Boolean::create( _shortInteger <= other._shortInteger );
}

Boolean ShortInteger::operator >( const ShortInteger &other ) const throw() {
	return Boolean::create( _shortInteger > other._shortInteger );
}

Boolean ShortInteger::operator >=( const ShortInteger &other ) const throw() {
	return Boolean::create( _shortInteger >= other._shortInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
ShortInteger ShortInteger::operator <<( const ShortestNatural &other ) const throw() {
	return ShortInteger( _shortInteger << other.getPlatformValue() );
}

ShortInteger &ShortInteger::operator <<=( const ShortestNatural &other ) throw() {
	_shortInteger <<= other.getPlatformValue();
	return *this;
}

ShortInteger ShortInteger::operator >>( const ShortestNatural &other ) const throw() {
	return ShortInteger( _shortInteger >> other.getPlatformValue() );
}

ShortInteger &ShortInteger::operator >>=( const ShortestNatural &other ) throw() {
	_shortInteger >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
ShortInteger &ShortInteger::operator ++() throw() {
	_shortInteger += 1;
	return *this;
}

ShortInteger ShortInteger::operator ++( int ) throw() {
	const internals::platform_signed_short_int shortInteger = _shortInteger;
	_shortInteger += 1;
	return ShortInteger( shortInteger );
}

ShortInteger &ShortInteger::operator --() throw() {
	_shortInteger -= 1;
	return *this;
}

ShortInteger ShortInteger::operator --( int ) throw() {
	const internals::platform_signed_short_int shortInteger = _shortInteger;
	_shortInteger -= 1;
	return ShortInteger( shortInteger );
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
Boolean ShortInteger::isNull() const throw() {
	return Boolean( _shortInteger == internals::platform_signed_short_int( 0 ) );
}

Boolean ShortInteger::isNotNull() const throw() {
	return isNull().not();
}

Boolean ShortInteger::isPositive() const throw() {
	return isNegative().not();
}

Boolean ShortInteger::isNegative() const throw() {
	return Boolean( _shortInteger < internals::platform_signed_short_int( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ShortInteger::operator internals::platform_signed_short_int() const throw() {
// 	return _boolValue;
// }

internals::platform_signed_short_int ShortInteger::getPlatformValue() const throw() {
	return _shortInteger;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ShortInteger::~ShortInteger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortInteger::ShortInteger() throw() {
	_shortInteger = internals::platform_signed_short_int( 0 );
}

// static
ShortInteger ShortInteger::create( const internals::platform_signed_short_int shortInteger /*= default*/ ) {
	return ShortInteger( shortInteger );
}


ShortInteger::ShortInteger( const internals::platform_signed_short_int shortInteger ) throw() {
	_shortInteger = shortInteger;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortInteger::ShortInteger( const ShortInteger &other ) throw() {
	_shortInteger = other._shortInteger;
}

const ShortInteger &ShortInteger::operator =( const ShortInteger &other ) throw() {
	if ( &other != this ) {
		_shortInteger = other._shortInteger;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
