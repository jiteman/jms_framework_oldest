#include "LongInteger.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
LongInteger LongInteger::operator +( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger + other._longInteger );
}

LongInteger &LongInteger::operator +=( const LongInteger &other ) throw() {
	_longInteger += other._longInteger;
	return *this;
}

LongInteger LongInteger::operator -( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger - other._longInteger );
}

LongInteger LongInteger::operator -=( const LongInteger &other ) throw() {
	_longInteger -= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator -() const throw() {
	return -_longInteger;
}

LongInteger LongInteger::operator *( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger * other._longInteger );
}

LongInteger &LongInteger::operator *=( const LongInteger &other ) throw() {
	_longInteger *= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator /( const LongInteger &other ) const throw( Exception ) {
	if ( other._longInteger == internals::platform_signed_long_int( 0 ) ) {
		// throw division by zero
	}

	return LongInteger( _longInteger / other._longInteger );
}

LongInteger &LongInteger::operator /=( const LongInteger &other ) throw( Exception ) {
	if ( other._longInteger == internals::platform_signed_long_int( 0 ) ) {
		// throw division by zero
	}

	_longInteger /= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator %( const LongInteger &other ) const throw( Exception ) {
	if ( other._longInteger == internals::platform_signed_long_int( 0 ) ) {
		// throw division by zero
	}

	return LongInteger( _longInteger % other._longInteger );
}

LongInteger &LongInteger::operator %=( const LongInteger &other ) throw( Exception ) {
	if ( other._longInteger == internals::platform_signed_long_int( 0 ) ) {
		// throw division by zero
	}

	_longInteger %= other._longInteger;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
LongInteger LongInteger::operator ^( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger ^ other._longInteger );
}

LongInteger &LongInteger::operator ^=( const LongInteger &other ) throw() {
	_longInteger ^= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator &( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger & other._longInteger );
}

LongInteger &LongInteger::operator &=( const LongInteger &other ) throw() {
	_longInteger &= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator |( const LongInteger &other ) const throw() {
	return LongInteger( _longInteger | other._longInteger );
}

LongInteger &LongInteger::operator |=( const LongInteger &other ) throw() {
	_longInteger |= other._longInteger;
	return *this;
}

LongInteger LongInteger::operator ~() const throw() {
	return LongInteger( ~_longInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// LongInteger LongInteger::operator !() const throw() {
// 	return LongInteger( !_smallestInteger );
// }
// 
// LongInteger LongInteger::operator &&( const LongInteger &other ) const throw() {
// 	return LongInteger( _smallestInteger && other._smallestInteger );
// }
// 
// LongInteger LongInteger::operator ||( const LongInteger &other ) const throw() {
// 	return LongInteger( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean LongInteger::operator ==( const LongInteger &other ) const throw() {
	return Boolean::create( _longInteger == other._longInteger );
}

Boolean LongInteger::operator !=( const LongInteger &other ) const throw() {
	return operator ==( other._longInteger ).not();
}

Boolean LongInteger::operator <( const LongInteger &other ) const throw() {
	return Boolean::create( _longInteger < other._longInteger );
}

Boolean LongInteger::operator <=( const LongInteger &other ) const throw() {
	return Boolean::create( _longInteger <= other._longInteger );
}

Boolean LongInteger::operator >( const LongInteger &other ) const throw() {
	return Boolean::create( _longInteger > other._longInteger );
}

Boolean LongInteger::operator >=( const LongInteger &other ) const throw() {
	return Boolean::create( _longInteger >= other._longInteger );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
LongInteger LongInteger::operator <<( const ShortestNatural &other ) const throw() {
	return LongInteger( _longInteger << other.getPlatformValue() );
}

LongInteger &LongInteger::operator <<=( const ShortestNatural &other ) throw() {
	_longInteger <<= other.getPlatformValue();
	return *this;
}

LongInteger LongInteger::operator >>( const ShortestNatural &other ) const throw() {
	return LongInteger( _longInteger >> other.getPlatformValue() );
}

LongInteger &LongInteger::operator >>=( const ShortestNatural &other ) throw() {
	_longInteger >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
LongInteger &LongInteger::operator ++() throw() {
	_longInteger += 1;
	return *this;
}

LongInteger LongInteger::operator ++( int ) throw() {
	const internals::platform_signed_long_int longInteger = _longInteger;
	_longInteger += 1;
	return LongInteger( longInteger );
}

LongInteger &LongInteger::operator --() throw() {
	_longInteger -= 1;
	return *this;
}

LongInteger LongInteger::operator --( int ) throw() {
	const internals::platform_signed_long_int longInteger = _longInteger;
	_longInteger -= 1;
	return LongInteger( longInteger );
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
Boolean LongInteger::isNull() const throw() {
	return Boolean( _longInteger == internals::platform_signed_int( 0 ) );
}

Boolean LongInteger::isNotNull() const throw() {
	return isNull().not();
}

Boolean LongInteger::isPositive() const throw() {
	return isNegative().not();
}

Boolean LongInteger::isNegative() const throw() {
	return Boolean( _longInteger < internals::platform_signed_int( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// LongInteger::operator internals::platform_signed_long_int() const throw() {
// 	return _boolValue;
// }

internals::platform_signed_long_int LongInteger::getPlatformValue() const throw() {
	return _longInteger;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
LongInteger::~LongInteger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
LongInteger::LongInteger() throw() {
	_longInteger = internals::platform_signed_long_int( 0 );
}

// static
LongInteger LongInteger::create( const internals::platform_signed_long_int longInteger /*= default*/ ) {
	return LongInteger( longInteger );
}


LongInteger::LongInteger( const internals::platform_signed_long_int longInteger ) throw() {
	_longInteger = longInteger;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
LongInteger::LongInteger( const LongInteger &other ) throw() {
	_longInteger = other._longInteger;
}

const LongInteger &LongInteger::operator =( const LongInteger &other ) throw() {
	if ( &other != this ) {
		_longInteger = other._longInteger;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
