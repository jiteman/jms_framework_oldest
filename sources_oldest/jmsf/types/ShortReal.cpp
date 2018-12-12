#include "ShortReal.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


ShortReal ShortReal::getAbsolute() const throw() {
	return ShortReal( math_computeAbsolute( _shortReal ) );
}

Boolean ShortReal::isAboutZero() const throw() {
	return math_isAboutZero( _shortReal );
}

// math
ShortReal ShortReal::operator +( const ShortReal &other ) const throw() {
	return ShortReal( _shortReal + other._shortReal );
}

ShortReal &ShortReal::operator +=( const ShortReal &other ) throw() {
	_shortReal += other._shortReal;
	return *this;
}

ShortReal ShortReal::operator -( const ShortReal &other ) const throw() {
	return ShortReal( _shortReal - other._shortReal );
}

ShortReal ShortReal::operator -=( const ShortReal &other ) throw() {
	_shortReal -= other._shortReal;
	return *this;
}

ShortReal ShortReal::operator -() const throw() {
	return -_shortReal;
}

ShortReal ShortReal::operator *( const ShortReal &other ) const throw() {
	return ShortReal( _shortReal * other._shortReal );
}

ShortReal &ShortReal::operator *=( const ShortReal &other ) throw() {
	_shortReal *= other._shortReal;
	return *this;
}

ShortReal ShortReal::operator /( const ShortReal &other ) const throw( Exception ) {
	if ( other.isAboutZero() ) {
		// throw division by zero
	}

	return ShortReal( _shortReal / other._shortReal );
}

ShortReal &ShortReal::operator /=( const ShortReal &other ) throw( Exception ) {
	if ( other.isAboutZero() ) {
		// throw division by zero
	}

	_shortReal /= other._shortReal;
	return *this;
}

// ShortReal ShortReal::operator %( const ShortReal &other ) const throw( Exception ) {
// 	if ( other._shortReal == internals::platform_short_real( 0 ) ) {
// 		// throw division by zero
// 	}
// 
// 	return ShortReal( _shortReal % other._shortReal );
// }

// ShortReal &ShortReal::operator %=( const ShortReal &other ) throw( Exception ) {
// 	if ( other._shortReal == internals::platform_short_real( 0 ) ) {
// 		// throw division by zero
// 	}
// 
// 	_shortReal %= other._shortReal;
// 	return *this;
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
// ShortReal ShortReal::operator ^( const ShortReal &other ) const throw() {
// 	return ShortReal( _shortReal ^ other._shortReal );
// }
// 
// ShortReal &ShortReal::operator ^=( const ShortReal &other ) throw() {
// 	_shortReal ^= other._shortReal;
// 	return *this;
// }
// 
// ShortReal ShortReal::operator &( const ShortReal &other ) const throw() {
// 	return ShortReal( _shortReal & other._shortReal );
// }
// 
// ShortReal &ShortReal::operator &=( const ShortReal &other ) throw() {
// 	_shortReal &= other._shortReal;
// 	return *this;
// }
// 
// ShortReal ShortReal::operator |( const ShortReal &other ) const throw() {
// 	return ShortReal( _shortReal | other._shortReal );
// }
// 
// ShortReal &ShortReal::operator |=( const ShortReal &other ) throw() {
// 	_shortReal |= other._shortReal;
// 	return *this;
// }
// 
// ShortReal ShortReal::operator ~() const throw() {
// 	return ShortReal( ~_shortReal );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// ShortReal ShortReal::operator !() const throw() {
// 	return ShortReal( !_smallestInteger );
// }
// 
// ShortReal ShortReal::operator &&( const ShortReal &other ) const throw() {
// 	return ShortReal( _smallestInteger && other._smallestInteger );
// }
// 
// ShortReal ShortReal::operator ||( const ShortReal &other ) const throw() {
// 	return ShortReal( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean ShortReal::operator ==( const ShortReal &other ) const throw() {
	return math_areAlmostEqual( _shortReal, other._shortReal );
}

Boolean ShortReal::operator !=( const ShortReal &other ) const throw() {
	return operator ==( other._shortReal ).not();
}

Boolean ShortReal::operator <( const ShortReal &other ) const throw() {
	return math_areAlmostEqual( _shortReal, other._shortReal ) ? False : Boolean::create( _shortReal < other._shortReal );
}

Boolean ShortReal::operator <=( const ShortReal &other ) const throw() {
	return math_areAlmostEqual( _shortReal, other._shortReal ) ? True : Boolean::create( _shortReal < other._shortReal );
}

Boolean ShortReal::operator >( const ShortReal &other ) const throw() {
	return math_areAlmostEqual( _shortReal, other._shortReal ) ? False : Boolean::create( _shortReal > other._shortReal );
}

Boolean ShortReal::operator >=( const ShortReal &other ) const throw() {
	return math_areAlmostEqual( _shortReal, other._shortReal ) ? True : Boolean::create( _shortReal > other._shortReal );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
// ShortReal ShortReal::operator <<( const ShortestNatural &other ) const throw() {
// 	return ShortReal( _shortReal << other.getPlatformValue() );
// }
// 
// ShortReal &ShortReal::operator <<=( const ShortestNatural &other ) throw() {
// 	_shortReal <<= other.getPlatformValue();
// 	return *this;
// }
// 
// ShortReal ShortReal::operator >>( const ShortestNatural &other ) const throw() {
// 	return ShortReal( _shortReal >> other.getPlatformValue() );
// }
// 
// ShortReal &ShortReal::operator >>=( const ShortestNatural &other ) throw() {
// 	_shortReal >>= other.getPlatformValue();
// 	return *this;
// }


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
// ShortReal &ShortReal::operator ++() throw() {
// 	_shortReal += 1;
// 	return *this;
// }
// 
// ShortReal ShortReal::operator ++( int ) throw() {
// 	const internals::platform_short_real shortReal = _shortReal;
// 	_shortReal += 1;
// 	return ShortReal( shortReal );
// }
// 
// ShortReal &ShortReal::operator --() throw() {
// 	_shortReal -= 1;
// 	return *this;
// }
// 
// ShortReal ShortReal::operator --( int ) throw() {
// 	const internals::platform_short_real shortReal = _shortReal;
// 	_shortReal -= 1;
// 	return ShortReal( shortReal );
// }

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
Boolean ShortReal::isNull() const throw() {
	const Boolean isThisRealNull = math_isAboutZero( _shortReal );

	if ( isThisRealNull ) {
		ShortReal &nonConstantThis = const_cast< ShortReal & >( *this );
		nonConstantThis._shortReal = internals::platform_short_real( 0.0f );
	}

	return isThisRealNull;
}

Boolean ShortReal::isNotNull() const throw() {
	return isNull().not();
}

Boolean ShortReal::isPositive() const throw() {
	return isNegative().not();
}

Boolean ShortReal::isNegative() const throw() {
	if ( isNull() ) return False;

	return Boolean::create( _shortReal < internals::platform_short_real( 0.0f ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ShortReal::operator internals::platform_short_real() const throw() {
// 	return _boolValue;
// }

internals::platform_short_real ShortReal::getPlatformValue() const throw() {
	return _shortReal;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ShortReal::~ShortReal() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortReal::ShortReal() throw() {
	_shortReal = internals::platform_short_real( 0.0f );
}

// static
ShortReal ShortReal::create( const internals::platform_short_real shortReal /*= default*/ ) {
	return ShortReal( shortReal );
}


ShortReal::ShortReal( const internals::platform_short_real shortReal ) throw() {
	_shortReal = shortReal;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ShortReal::ShortReal( const ShortReal &other ) throw() {
	_shortReal = other._shortReal;
}

const ShortReal &ShortReal::operator =( const ShortReal &other ) throw() {
	if ( &other != this ) {
		_shortReal = other._shortReal;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
internals::platform_short_real ShortReal::math_computeAbsolute( const internals::platform_short_real theReal ) throw() {
	return theReal < internals::platform_short_real( 0.0f ) ? -theReal : theReal;
}

// static
Boolean ShortReal::math_isAboutZero( const internals::platform_short_real theReal ) throw() {
	return Boolean::create( math_computeAbsolute( theReal ) > SHORT_REAL_DEFAULT_ACCURACY ).not();
}

// static
Boolean ShortReal::math_areAlmostEqual( const internals::platform_short_real firstReal, const internals::platform_short_real secondReal ) throw() {
	return math_isAboutZero( firstReal - secondReal );
}


extern const ShortReal ShortRealZero = ShortReal::create( internals::platform_short_real( 0.0f ) );
extern const ShortReal ShortRealOne = ShortReal::create( internals::platform_short_real( 1.0f ) );
extern const ShortReal ShortRealTwo = ShortReal::create( internals::platform_short_real( 2.0f ) );


} // namespace types
} // namespace jmsf
