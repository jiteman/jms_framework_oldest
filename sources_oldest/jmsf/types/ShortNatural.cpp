#include "ShortNatural.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


// math
ShortNatural ShortNatural::operator +( const ShortNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) + static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator +=( const ShortNatural &other ) throw() {
	_shortNatural += other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator -( const ShortNatural &other ) const throw( Exception ) {
	if ( _shortNatural < other._shortNatural ) {
		// throw underflow
	}

	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) - static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural ShortNatural::operator -=( const ShortNatural &other ) throw( Exception ) {
	if ( _shortNatural < other._shortNatural ) {
		// throw underflow
	}

	_shortNatural -= other._shortNatural;
	return *this;
}

// ShortNatural ShortNatural::operator -() const throw() {
// 	return -_shortNatural;
// }

ShortNatural ShortNatural::operator *( const ShortNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) * static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator *=( const ShortNatural &other ) throw() {
	_shortNatural *= other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator /( const ShortNatural &other ) const throw( Exception ) {
	if ( other._shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw division by zero
	}

	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) / static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator /=( const ShortNatural &other ) throw( Exception ) {
	if ( other._shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw division by zero
	}

	_shortNatural /= other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator %( const ShortNatural &other ) const throw( Exception ) {
	if ( other._shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw division by zero
	}

	return ShortNatural( static_cast< internals::platform_unsigned_short_int >( _shortNatural % other._shortNatural ) );
}

ShortNatural &ShortNatural::operator %=( const ShortNatural &other ) throw( Exception ) {
	if ( other._shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw division by zero
	}

	_shortNatural %= other._shortNatural;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
ShortNatural ShortNatural::operator ^( const ShortNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >(  _shortNatural ) ^ static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator ^=( const ShortNatural &other ) throw() {
	_shortNatural ^= other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator &( const ShortNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) & static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator &=( const ShortNatural &other ) throw() {
	_shortNatural &= other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator |( const ShortNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) | static_cast< internals::platform_unsigned_int >( other._shortNatural ) );
}

ShortNatural &ShortNatural::operator |=( const ShortNatural &other ) throw() {
	_shortNatural |= other._shortNatural;
	return *this;
}

ShortNatural ShortNatural::operator ~() const throw() {
	return ShortNatural( ~static_cast< internals::platform_unsigned_int >( _shortNatural ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Byte Byte::operator !() const throw() {
// 	return Byte( !_smallNatural );
// }
// 
// Byte Byte::operator &&( const Byte &other ) const throw() {
// 	return Byte( _smallNatural && other._smallNatural );
// }
// 
// Byte Byte::operator ||( const Byte &other ) const throw() {
// 	return Byte( _smallNatural || other._smallNatural );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean ShortNatural::operator ==( const ShortNatural &other ) const throw() {
	return Boolean::create( _shortNatural == other._shortNatural );
}

Boolean ShortNatural::operator !=( const ShortNatural &other ) const throw() {
	return operator ==( other._shortNatural ).not();
}

Boolean ShortNatural::operator <( const ShortNatural &other ) const throw() {
	return Boolean::create( _shortNatural < other._shortNatural );
}

Boolean ShortNatural::operator <=( const ShortNatural &other ) const throw() {
	return Boolean::create( _shortNatural <= other._shortNatural );
}

Boolean ShortNatural::operator >( const ShortNatural &other ) const throw() {
	return Boolean::create( _shortNatural > other._shortNatural );
}

Boolean ShortNatural::operator >=( const ShortNatural &other ) const throw() {
	return Boolean::create( _shortNatural >= other._shortNatural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
ShortNatural ShortNatural::operator <<( const ShortestNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) << static_cast< internals::platform_unsigned_int >( other.getPlatformValue() ) );
}

ShortNatural &ShortNatural::operator <<=( const ShortestNatural &other ) throw() {
	_shortNatural <<= other.getPlatformValue();
	return *this;
}

ShortNatural ShortNatural::operator >>( const ShortestNatural &other ) const throw() {
	return ShortNatural( static_cast< internals::platform_unsigned_int >( _shortNatural ) >> static_cast< internals::platform_unsigned_int >( other.getPlatformValue() ) );
}

ShortNatural &ShortNatural::operator >>=( const ShortestNatural &other ) throw() {
	_shortNatural >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
ShortNatural &ShortNatural::operator ++() throw() {
	_shortNatural += 1;
	return *this;
}

ShortNatural ShortNatural::operator ++( int ) throw() {
	const internals::platform_unsigned_short_int shortNatural = _shortNatural;
	_shortNatural += 1;
	return ShortNatural( shortNatural );
}

ShortNatural &ShortNatural::operator --() throw( Exception ) {
	if ( _shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw underflow
	}

	_shortNatural -= 1;
	return *this;
}

ShortNatural ShortNatural::operator --( int ) throw( Exception ) {
	if ( _shortNatural == internals::platform_unsigned_short_int( 0 ) ) {
		// throw underflow
	}

	const internals::platform_unsigned_short_int shortNatural = _shortNatural;
	_shortNatural -= 1;
	return ShortNatural( shortNatural );
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
Boolean ShortNatural::isNull() const throw() {
	return Boolean( _shortNatural == internals::platform_unsigned_short_int( 0 ) );
}

Boolean ShortNatural::isNotNull() const throw() {
	return isNull().not();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Byte::operator internals::platform_unsigned_short_int() const throw() {
// 	return _boolValue;
// }

internals::platform_unsigned_short_int ShortNatural::getPlatformValue() const throw() {
	return _shortNatural;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ShortNatural::~ShortNatural() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortNatural::ShortNatural() throw() {
	_shortNatural = internals::platform_unsigned_short_int( 0 );
}

// static
ShortNatural ShortNatural::create( const internals::platform_unsigned_short_int shortNatural /*= default*/ ) {
	return ShortNatural( shortNatural );
}


ShortNatural::ShortNatural( const internals::platform_unsigned_short_int shortNatural ) throw() {
	_shortNatural = shortNatural;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortNatural::ShortNatural( const ShortNatural &other ) throw() {
	_shortNatural = other._shortNatural;
}

const ShortNatural &ShortNatural::operator =( const ShortNatural &other ) throw() {
	if ( &other != this ) {
		_shortNatural = other._shortNatural;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
