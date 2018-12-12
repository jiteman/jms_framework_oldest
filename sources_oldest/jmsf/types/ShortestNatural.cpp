#include "ShortestNatural.h"


#include "Boolean.h"


namespace jmsf {
namespace types {

// math
ShortestNatural ShortestNatural::operator +( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) + static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator +=( const ShortestNatural &other ) throw() {
	_shortestNatural += other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator -( const ShortestNatural &other ) const throw( Exception ) {
	if ( _shortestNatural < other._shortestNatural ) {
		// throw underflow
	}

	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) - static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural ShortestNatural::operator -=( const ShortestNatural &other ) throw( Exception ) {
	if ( _shortestNatural < other._shortestNatural ) {
		// throw underflow
	}

	_shortestNatural -= other._shortestNatural;
	return *this;
}

// ShortestNatural ShortestNatural::operator -() const throw() {
// 	return -_shortestNatural;
// }

ShortestNatural ShortestNatural::operator *( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) * static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator *=( const ShortestNatural &other ) throw() {
	_shortestNatural *= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator /( const ShortestNatural &other ) const throw( Exception ) {
	if ( other._shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw division by zero
	}

	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) / static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator /=( const ShortestNatural &other ) throw( Exception ) {
	if ( other._shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw division by zero
	}

	_shortestNatural /= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator %( const ShortestNatural &other ) const throw( Exception ) {
	if ( other._shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw division by zero
	}

	return ShortestNatural( static_cast< internals::platform_unsigned_char >( _shortestNatural % other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator %=( const ShortestNatural &other ) throw( Exception ) {
	if ( other._shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw division by zero
	}

	_shortestNatural %= other._shortestNatural;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
ShortestNatural ShortestNatural::operator ^( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >(  _shortestNatural ) ^ static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator ^=( const ShortestNatural &other ) throw() {
	_shortestNatural ^= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator &( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) & static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator &=( const ShortestNatural &other ) throw() {
	_shortestNatural &= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator |( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) | static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator |=( const ShortestNatural &other ) throw() {
	_shortestNatural |= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator ~() const throw() {
	return ShortestNatural( ~static_cast< internals::platform_unsigned_int >( _shortestNatural ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Byte Byte::operator !() const throw() {
// 	return Byte( !_smallestNatural );
// }
// 
// Byte Byte::operator &&( const Byte &other ) const throw() {
// 	return Byte( _smallestNatural && other._smallestNatural );
// }
// 
// Byte Byte::operator ||( const Byte &other ) const throw() {
// 	return Byte( _smallestNatural || other._smallestNatural );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean ShortestNatural::operator ==( const ShortestNatural &other ) const throw() {
	return Boolean::create( _shortestNatural == other._shortestNatural );
}

Boolean ShortestNatural::operator !=( const ShortestNatural &other ) const throw() {
	return operator ==( other._shortestNatural ).not();
}

Boolean ShortestNatural::operator <( const ShortestNatural &other ) const throw() {
	return Boolean::create( _shortestNatural < other._shortestNatural );
}

Boolean ShortestNatural::operator <=( const ShortestNatural &other ) const throw() {
	return Boolean::create( _shortestNatural <= other._shortestNatural );
}

Boolean ShortestNatural::operator >( const ShortestNatural &other ) const throw() {
	return Boolean::create( _shortestNatural > other._shortestNatural );
}

Boolean ShortestNatural::operator >=( const ShortestNatural &other ) const throw() {
	return Boolean::create( _shortestNatural >= other._shortestNatural );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
ShortestNatural ShortestNatural::operator <<( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) << static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator <<=( const ShortestNatural &other ) throw() {
	_shortestNatural <<= other._shortestNatural;
	return *this;
}

ShortestNatural ShortestNatural::operator >>( const ShortestNatural &other ) const throw() {
	return ShortestNatural( static_cast< internals::platform_unsigned_int >( _shortestNatural ) >> static_cast< internals::platform_unsigned_int >( other._shortestNatural ) );
}

ShortestNatural &ShortestNatural::operator >>=( const ShortestNatural &other ) throw() {
	_shortestNatural >>= other._shortestNatural;
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
ShortestNatural &ShortestNatural::operator ++() throw() {
	_shortestNatural += 1;
	return *this;
}

ShortestNatural ShortestNatural::operator ++( int ) throw() {
	const internals::platform_unsigned_char shortestNatural = _shortestNatural;
	_shortestNatural += 1;
	return ShortestNatural( shortestNatural );
}

ShortestNatural &ShortestNatural::operator --() throw( Exception ) {
	if ( _shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw underflow
	}

	_shortestNatural -= 1;
	return *this;
}

ShortestNatural ShortestNatural::operator --( int ) throw( Exception ) {
	if ( _shortestNatural == internals::platform_unsigned_char( 0 ) ) {
		// throw underflow
	}

	const internals::platform_unsigned_char shortestNatural = _shortestNatural;
	_shortestNatural -= 1;
	return ShortestNatural( shortestNatural );
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
Boolean ShortestNatural::isNull() const throw() {
	return Boolean( _shortestNatural == internals::platform_unsigned_char( 0 ) );
}

Boolean ShortestNatural::isNotNull() const throw() {
	return isNull().not();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Byte::operator internals::platform_unsigned_char() const throw() {
// 	return _boolValue;
// }

internals::platform_unsigned_char ShortestNatural::getPlatformValue() const throw() {
	return _shortestNatural;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ShortestNatural::~ShortestNatural() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortestNatural::ShortestNatural() throw() {
	_shortestNatural = internals::platform_unsigned_char( 0 );
}

// static
ShortestNatural ShortestNatural::create( const internals::platform_unsigned_char shortestNatural /*= default*/ ) {
	return ShortestNatural( shortestNatural );
}


ShortestNatural::ShortestNatural( const internals::platform_unsigned_char shortestNatural ) throw() {
	_shortestNatural = shortestNatural;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortestNatural::ShortestNatural( const ShortestNatural &other ) throw() {
	_shortestNatural = other._shortestNatural;
}

const ShortestNatural &ShortestNatural::operator =( const ShortestNatural &other ) throw() {
	if ( &other != this ) {
		_shortestNatural = other._shortestNatural;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
