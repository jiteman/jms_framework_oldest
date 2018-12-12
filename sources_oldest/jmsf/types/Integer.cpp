#include "Integer.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
Integer Integer::operator +( const Integer &other ) const throw() {
	return Integer( _integer + other._integer );
}

Integer &Integer::operator +=( const Integer &other ) throw() {
	_integer += other._integer;
	return *this;
}

Integer Integer::operator -( const Integer &other ) const throw() {
	return Integer( _integer - other._integer );
}

Integer Integer::operator -=( const Integer &other ) throw() {
	_integer -= other._integer;
	return *this;
}

Integer Integer::operator -() const throw() {
	return -_integer;
}

Integer Integer::operator *( const Integer &other ) const throw() {
	return Integer( _integer * other._integer );
}

Integer &Integer::operator *=( const Integer &other ) throw() {
	_integer *= other._integer;
	return *this;
}

Integer Integer::operator /( const Integer &other ) const throw( Exception ) {
	if ( other._integer == internals::platform_signed_int( 0 ) ) {
		// throw division by zero
	}

	return Integer( _integer / other._integer );
}

Integer &Integer::operator /=( const Integer &other ) throw( Exception ) {
	if ( other._integer == internals::platform_signed_int( 0 ) ) {
		// throw division by zero
	}

	_integer /= other._integer;
	return *this;
}

Integer Integer::operator %( const Integer &other ) const throw( Exception ) {
	if ( other._integer == internals::platform_signed_int( 0 ) ) {
		// throw division by zero
	}

	return Integer( _integer % other._integer );
}

Integer &Integer::operator %=( const Integer &other ) throw( Exception ) {
	if ( other._integer == internals::platform_signed_int( 0 ) ) {
		// throw division by zero
	}

	_integer %= other._integer;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
Integer Integer::operator ^( const Integer &other ) const throw() {
	return Integer( _integer ^ other._integer );
}

Integer &Integer::operator ^=( const Integer &other ) throw() {
	_integer ^= other._integer;
	return *this;
}

Integer Integer::operator &( const Integer &other ) const throw() {
	return Integer( _integer & other._integer );
}

Integer &Integer::operator &=( const Integer &other ) throw() {
	_integer &= other._integer;
	return *this;
}

Integer Integer::operator |( const Integer &other ) const throw() {
	return Integer( _integer | other._integer );
}

Integer &Integer::operator |=( const Integer &other ) throw() {
	_integer |= other._integer;
	return *this;
}

Integer Integer::operator ~() const throw() {
	return Integer( ~_integer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Integer Integer::operator !() const throw() {
// 	return Integer( !_smallestInteger );
// }
// 
// Integer Integer::operator &&( const Integer &other ) const throw() {
// 	return Integer( _smallestInteger && other._smallestInteger );
// }
// 
// Integer Integer::operator ||( const Integer &other ) const throw() {
// 	return Integer( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean Integer::operator ==( const Integer &other ) const throw() {
	return Boolean::create( _integer == other._integer );
}

Boolean Integer::operator !=( const Integer &other ) const throw() {
	return operator ==( other._integer ).not();
}

Boolean Integer::operator <( const Integer &other ) const throw() {
	return Boolean::create( _integer < other._integer );
}

Boolean Integer::operator <=( const Integer &other ) const throw() {
	return Boolean::create( _integer <= other._integer );
}

Boolean Integer::operator >( const Integer &other ) const throw() {
	return Boolean::create( _integer > other._integer );
}

Boolean Integer::operator >=( const Integer &other ) const throw() {
	return Boolean::create( _integer >= other._integer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
Integer Integer::operator <<( const ShortestNatural &other ) const throw() {
	return Integer( _integer << other.getPlatformValue() );
}

Integer &Integer::operator <<=( const ShortestNatural &other ) throw() {
	_integer <<= other.getPlatformValue();
	return *this;
}

Integer Integer::operator >>( const ShortestNatural &other ) const throw() {
	return Integer( _integer >> other.getPlatformValue() );
}

Integer &Integer::operator >>=( const ShortestNatural &other ) throw() {
	_integer >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
Integer &Integer::operator ++() throw() {
	_integer += 1;
	return *this;
}

Integer Integer::operator ++( int ) throw() {
	const internals::platform_signed_int integer = _integer;
	_integer += 1;
	return Integer( integer );
}

Integer &Integer::operator --() throw() {
	_integer -= 1;
	return *this;
}

Integer Integer::operator --( int ) throw() {
	const internals::platform_signed_int integer = _integer;
	_integer -= 1;
	return Integer( integer );
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
Boolean Integer::isNull() const throw() {
	return Boolean( _integer == internals::platform_signed_int( 0 ) );
}

Boolean Integer::isNotNull() const throw() {
	return isNull().not();
}

Boolean Integer::isPositive() const throw() {
	return isNegative().not();
}

Boolean Integer::isNegative() const throw() {
	return Boolean( _integer < internals::platform_signed_int( 0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Integer::operator internals::platform_signed_int() const throw() {
// 	return _boolValue;
// }

internals::platform_signed_int Integer::getPlatformValue() const throw() {
	return _integer;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Integer::~Integer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Integer::Integer() throw() {
	_integer = internals::platform_signed_int( 0 );
}

// static
Integer Integer::create( const internals::platform_signed_int integer /*= default*/ ) {
	return Integer( integer );
}


Integer::Integer( const internals::platform_signed_int integer ) throw() {
	_integer = integer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Integer::Integer( const Integer &other ) throw() {
	_integer = other._integer;
}

const Integer &Integer::operator =( const Integer &other ) throw() {
	if ( &other != this ) {
		_integer = other._integer;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
