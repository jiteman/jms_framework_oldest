#include "LongNatural.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
LongNatural LongNatural::operator +( const LongNatural &other ) const throw() {
	return LongNatural( _longNatural + other._longNatural );
}

LongNatural &LongNatural::operator +=( const LongNatural &other ) throw() {
	_longNatural += other._longNatural;
	return *this;
}

LongNatural LongNatural::operator -( const LongNatural &other ) const throw( Exception ) {
	if ( _longNatural < other._longNatural ) {
		// throw underflow
	}

	return LongNatural( _longNatural - other._longNatural );
}

LongNatural LongNatural::operator -=( const LongNatural &other ) throw( Exception ) {
	if ( _longNatural < other._longNatural ) {
		// throw underflow
	}

	_longNatural -= other._longNatural;
	return *this;
}

// LongNatural LongNatural::operator -() const throw() {
// 	return -_longNatural;
// }

LongNatural LongNatural::operator *( const LongNatural &other ) const throw() {
	return LongNatural( _longNatural * other._longNatural );
}

LongNatural &LongNatural::operator *=( const LongNatural &other ) throw() {
	_longNatural *= other._longNatural;
	return *this;
}

LongNatural LongNatural::operator /( const LongNatural &other ) const throw( Exception ) {
	if ( other._longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw division by zero
	}

	return LongNatural( _longNatural / other._longNatural );
}

LongNatural &LongNatural::operator /=( const LongNatural &other ) throw( Exception ) {
	if ( other._longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw division by zero
	}

	_longNatural /= other._longNatural;
	return *this;
}

LongNatural LongNatural::operator %( const LongNatural &other ) const throw( Exception ) {
	if ( other._longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw division by zero
	}

	return LongNatural( _longNatural % other._longNatural );
}

LongNatural &LongNatural::operator %=( const LongNatural &other ) throw( Exception ) {
	if ( other._longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw division by zero
	}

	_longNatural %= other._longNatural;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
LongNatural LongNatural::operator ^( const LongNatural &other ) const throw() {
	return LongNatural( _longNatural ^ other._longNatural );
}

LongNatural &LongNatural::operator ^=( const LongNatural &other ) throw() {
	_longNatural ^= other._longNatural;
	return *this;
}

LongNatural LongNatural::operator &( const LongNatural &other ) const throw() {
	return LongNatural( _longNatural & other._longNatural );
}

LongNatural &LongNatural::operator &=( const LongNatural &other ) throw() {
	_longNatural &= other._longNatural;
	return *this;
}

LongNatural LongNatural::operator |( const LongNatural &other ) const throw() {
	return LongNatural( _longNatural | other._longNatural );
}

LongNatural &LongNatural::operator |=( const LongNatural &other ) throw() {
	_longNatural |= other._longNatural;
	return *this;
}

LongNatural LongNatural::operator ~() const throw() {
	return LongNatural( ~_longNatural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Byte Byte::operator !() const throw() {
// 	return Byte( !_bigNatural );
// }
// 
// Byte Byte::operator &&( const Byte &other ) const throw() {
// 	return Byte( _bigNatural && other._bigNatural );
// }
// 
// Byte Byte::operator ||( const Byte &other ) const throw() {
// 	return Byte( _bigNatural || other._bigNatural );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean LongNatural::operator ==( const LongNatural &other ) const throw() {
	return Boolean::create( _longNatural == other._longNatural );
}

Boolean LongNatural::operator !=( const LongNatural &other ) const throw() {
	return operator ==( other._longNatural ).not();
}

Boolean LongNatural::operator <( const LongNatural &other ) const throw() {
	return Boolean::create( _longNatural < other._longNatural );
}

Boolean LongNatural::operator <=( const LongNatural &other ) const throw() {
	return Boolean::create( _longNatural <= other._longNatural );
}

Boolean LongNatural::operator >( const LongNatural &other ) const throw() {
	return Boolean::create( _longNatural > other._longNatural );
}

Boolean LongNatural::operator >=( const LongNatural &other ) const throw() {
	return Boolean::create( _longNatural >= other._longNatural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
LongNatural LongNatural::operator <<( const ShortestNatural &other ) const throw() {
	return LongNatural( _longNatural << other.getPlatformValue() );
}

LongNatural &LongNatural::operator <<=( const ShortestNatural &other ) throw() {
	_longNatural <<= other.getPlatformValue();
	return *this;
}

LongNatural LongNatural::operator >>( const ShortestNatural &other ) const throw() {
	return LongNatural( _longNatural >> other.getPlatformValue() );
}

LongNatural &LongNatural::operator >>=( const ShortestNatural &other ) throw() {
	_longNatural >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
LongNatural &LongNatural::operator ++() throw() {
	_longNatural += 1;
	return *this;
}

LongNatural LongNatural::operator ++( int ) throw() {
	const internals::platform_unsigned_long_int longNatural = _longNatural;
	_longNatural += 1;
	return LongNatural( longNatural );
}

LongNatural &LongNatural::operator --() throw( Exception ) {
	if ( _longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw underflow
	}

	_longNatural -= 1;
	return *this;
}

LongNatural LongNatural::operator --( int ) throw( Exception ) {
	if ( _longNatural == internals::platform_unsigned_long_int( 0 ) ) {
		// throw underflow
	}

	const internals::platform_unsigned_long_int longNatural = _longNatural;
	_longNatural -= 1;
	return LongNatural( longNatural );
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
Boolean LongNatural::isNull() const throw() {
	return Boolean( _longNatural == internals::platform_unsigned_long_int( 0 ) );
}

Boolean LongNatural::isNotNull() const throw() {
	return isNull().not();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Byte::operator internals::platform_unsigned_long_int() const throw() {
// 	return _boolValue;
// }

internals::platform_unsigned_long_int LongNatural::getPlatformValue() const throw() {
	return _longNatural;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
LongNatural::~LongNatural() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
LongNatural::LongNatural() throw() {
	_longNatural = internals::platform_unsigned_long_int( 0 );
}

// static
LongNatural LongNatural::create( const internals::platform_unsigned_long_int longNatural /*= default*/ ) {
	return LongNatural( longNatural );
}


LongNatural::LongNatural( const internals::platform_unsigned_long_int longNatural ) throw() {
	_longNatural = longNatural;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
LongNatural::LongNatural( const LongNatural &other ) throw() {
	_longNatural = other._longNatural;
}

const LongNatural &LongNatural::operator =( const LongNatural &other ) throw() {
	if ( &other != this ) {
		_longNatural = other._longNatural;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
