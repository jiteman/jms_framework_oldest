#include "Natural.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
Natural Natural::operator +( const Natural &other ) const throw() {
	return Natural( _natural + other._natural );
}

Natural &Natural::operator +=( const Natural &other ) throw() {
	_natural += other._natural;
	return *this;
}

Natural Natural::operator -( const Natural &other ) const throw( Exception ) {
	if ( _natural < other._natural ) {
		// throw underflow
	}

	return Natural( _natural - other._natural );
}

Natural Natural::operator -=( const Natural &other ) throw( Exception ) {
	if ( _natural < other._natural ) {
		// throw underflow
	}

	_natural -= other._natural;
	return *this;
}

// Natural Natural::operator -() const throw() {
// 	return -_natural;
// }

Natural Natural::operator *( const Natural &other ) const throw() {
	return Natural( _natural * other._natural );
}

Natural &Natural::operator *=( const Natural &other ) throw() {
	_natural *= other._natural;
	return *this;
}

Natural Natural::operator /( const Natural &other ) const throw( Exception ) {
	if ( other._natural == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	return Natural( _natural / other._natural );
}

Natural &Natural::operator /=( const Natural &other ) throw( Exception ) {
	if ( other._natural == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	_natural /= other._natural;
	return *this;
}

Natural Natural::operator %( const Natural &other ) const throw( Exception ) {
	if ( other._natural == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	return Natural( _natural % other._natural );
}

Natural &Natural::operator %=( const Natural &other ) throw( Exception ) {
	if ( other._natural == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	_natural %= other._natural;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
Natural Natural::operator ^( const Natural &other ) const throw() {
	return Natural( _natural ^ other._natural );
}

Natural &Natural::operator ^=( const Natural &other ) throw() {
	_natural ^= other._natural;
	return *this;
}

Natural Natural::operator &( const Natural &other ) const throw() {
	return Natural( _natural & other._natural );
}

Natural &Natural::operator &=( const Natural &other ) throw() {
	_natural &= other._natural;
	return *this;
}

Natural Natural::operator |( const Natural &other ) const throw() {
	return Natural( _natural | other._natural );
}

Natural &Natural::operator |=( const Natural &other ) throw() {
	_natural |= other._natural;
	return *this;
}

Natural Natural::operator ~() const throw() {
	return Natural( ~_natural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Byte Byte::operator !() const throw() {
// 	return Byte( !_natural );
// }
// 
// Byte Byte::operator &&( const Byte &other ) const throw() {
// 	return Byte( _natural && other._natural );
// }
// 
// Byte Byte::operator ||( const Byte &other ) const throw() {
// 	return Byte( _natural || other._natural );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean Natural::operator ==( const Natural &other ) const throw() {
	return Boolean::create( _natural == other._natural );
}

Boolean Natural::operator !=( const Natural &other ) const throw() {
	return operator ==( other._natural ).not();
}

Boolean Natural::operator <( const Natural &other ) const throw() {
	return Boolean::create( _natural < other._natural );
}

Boolean Natural::operator <=( const Natural &other ) const throw() {
	return Boolean::create( _natural <= other._natural );
}

Boolean Natural::operator >( const Natural &other ) const throw() {
	return Boolean::create( _natural > other._natural );
}

Boolean Natural::operator >=( const Natural &other ) const throw() {
	return Boolean::create( _natural >= other._natural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
Natural Natural::operator <<( const ShortestNatural &other ) const throw() {
	return Natural( _natural << other.getPlatformValue() );
}

Natural &Natural::operator <<=( const ShortestNatural &other ) throw() {
	_natural <<= other.getPlatformValue();
	return *this;
}

Natural Natural::operator >>( const ShortestNatural &other ) const throw() {
	return Natural( _natural >> other.getPlatformValue() );
}

Natural &Natural::operator >>=( const ShortestNatural &other ) throw() {
	_natural >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
Natural &Natural::operator ++() throw() {
	_natural += 1;
	return *this;
}

Natural Natural::operator ++( int ) throw() {
	const internals::platform_unsigned_int natural = _natural;
	_natural += 1;
	return Natural( natural );
}

Natural &Natural::operator --() throw( Exception ) {
	if ( _natural == internals::platform_unsigned_int( 0 ) ) {
		// throw underflow
	}

	_natural -= 1;
	return *this;
}

Natural Natural::operator --( int ) throw( Exception ) {
	if ( _natural == internals::platform_unsigned_int( 0 ) ) {
		// throw underflow
	}

	const internals::platform_unsigned_int natural = _natural;
	_natural -= 1;
	return Natural( natural );
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
Boolean Natural::isNull() const throw() {
	return Boolean( _natural == internals::platform_unsigned_int( 0 ) );
}

Boolean Natural::isNotNull() const throw() {
	return isNull().not();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Byte::operator internals::platform_unsigned_int() const throw() {
// 	return _boolValue;
// }

internals::platform_unsigned_int Natural::getPlatformValue() const throw() {
	return _natural;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Natural::~Natural() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Natural::Natural() throw() {
	_natural = internals::platform_unsigned_int( 0 );
}

// static
Natural Natural::create( const internals::platform_unsigned_int natural /*= default*/ ) {
	return Natural( natural );
}


Natural::Natural( const internals::platform_unsigned_int natural ) throw() {
	_natural = natural;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Natural::Natural( const Natural &other ) throw() {
	_natural = other._natural;
}

const Natural &Natural::operator =( const Natural &other ) throw() {
	if ( &other != this ) {
		_natural = other._natural;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
