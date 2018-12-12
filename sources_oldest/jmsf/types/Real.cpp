#include "Real.h"


#include "ShortestNatural.h"
#include "Boolean.h"


namespace jmsf {
namespace types {


Real Real::getAbsolute() const throw() {
	return Real( math_computeAbsolute( _real ) );
}

Boolean Real::isAboutZero() const throw() {
	return math_isAboutZero( _real );
}

// math
Real Real::operator +( const Real &other ) const throw() {
	return Real( _real + other._real );
}

Real &Real::operator +=( const Real &other ) throw() {
	_real += other._real;
	return *this;
}

Real Real::operator -( const Real &other ) const throw() {
	return Real( _real - other._real );
}

Real Real::operator -=( const Real &other ) throw() {
	_real -= other._real;
	return *this;
}

Real Real::operator -() const throw() {
	return -_real;
}

Real Real::operator *( const Real &other ) const throw() {
	return Real( _real * other._real );
}

Real &Real::operator *=( const Real &other ) throw() {
	_real *= other._real;
	return *this;
}

Real Real::operator /( const Real &other ) const throw( Exception ) {
	if ( other.isAboutZero() ) {
		// throw division by zero
	}

	return Real( _real / other._real );
}

Real &Real::operator /=( const Real &other ) throw( Exception ) {
	if ( other.isAboutZero() ) {
		// throw division by zero
	}

	_real /= other._real;
	return *this;
}

// Real Real::operator %( const Real &other ) const throw( Exception ) {
// 	if ( other._real == internals::platform_real( 0 ) ) {
// 		// throw division by zero
// 	}
// 
// 	return Real( _real % other._real );
// }

// Real &Real::operator %=( const Real &other ) throw( Exception ) {
// 	if ( other._real == internals::platform_real( 0 ) ) {
// 		// throw division by zero
// 	}
// 
// 	_real %= other._real;
// 	return *this;
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
// Real Real::operator ^( const Real &other ) const throw() {
// 	return Real( _real ^ other._real );
// }
// 
// Real &Real::operator ^=( const Real &other ) throw() {
// 	_real ^= other._real;
// 	return *this;
// }
// 
// Real Real::operator &( const Real &other ) const throw() {
// 	return Real( _real & other._real );
// }
// 
// Real &Real::operator &=( const Real &other ) throw() {
// 	_real &= other._real;
// 	return *this;
// }
// 
// Real Real::operator |( const Real &other ) const throw() {
// 	return Real( _real | other._real );
// }
// 
// Real &Real::operator |=( const Real &other ) throw() {
// 	_real |= other._real;
// 	return *this;
// }
// 
// Real Real::operator ~() const throw() {
// 	return Real( ~_real );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
// Real Real::operator !() const throw() {
// 	return Real( !_smallestInteger );
// }
// 
// Real Real::operator &&( const Real &other ) const throw() {
// 	return Real( _smallestInteger && other._smallestInteger );
// }
// 
// Real Real::operator ||( const Real &other ) const throw() {
// 	return Real( _smallestInteger || other._smallestInteger );
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean Real::operator ==( const Real &other ) const throw() {
	return math_areAlmostEqual( _real, other._real );
}

Boolean Real::operator !=( const Real &other ) const throw() {
	return operator ==( other._real ).not();
}

Boolean Real::operator <( const Real &other ) const throw() {
	return math_areAlmostEqual( _real, other._real ) ? False : Boolean::create( _real < other._real );
}

Boolean Real::operator <=( const Real &other ) const throw() {
	return math_areAlmostEqual( _real, other._real ) ? True : Boolean::create( _real < other._real );
}

Boolean Real::operator >( const Real &other ) const throw() {
	return math_areAlmostEqual( _real, other._real ) ? False : Boolean::create( _real > other._real );
}

Boolean Real::operator >=( const Real &other ) const throw() {
	return math_areAlmostEqual( _real, other._real ) ? True : Boolean::create( _real > other._real );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
// Real Real::operator <<( const ShortestNatural &other ) const throw() {
// 	return Real( _real << other.getPlatformValue() );
// }
// 
// Real &Real::operator <<=( const ShortestNatural &other ) throw() {
// 	_real <<= other.getPlatformValue();
// 	return *this;
// }
// 
// Real Real::operator >>( const ShortestNatural &other ) const throw() {
// 	return Real( _real >> other.getPlatformValue() );
// }
// 
// Real &Real::operator >>=( const ShortestNatural &other ) throw() {
// 	_real >>= other.getPlatformValue();
// 	return *this;
// }


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
// Real &Real::operator ++() throw() {
// 	_real += 1;
// 	return *this;
// }
// 
// Real Real::operator ++( int ) throw() {
// 	const internals::platform_real shortReal = _real;
// 	_real += 1;
// 	return Real( shortReal );
// }
// 
// Real &Real::operator --() throw() {
// 	_real -= 1;
// 	return *this;
// }
// 
// Real Real::operator --( int ) throw() {
// 	const internals::platform_real shortReal = _real;
// 	_real -= 1;
// 	return Real( shortReal );
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
Boolean Real::isNull() const throw() {
	const Boolean isThisRealNull = math_isAboutZero( _real );

	if ( isThisRealNull ) {
		Real &nonConstantThis = const_cast< Real & >( *this );
		nonConstantThis._real = internals::platform_short_real( 0.0 );
	}

	return isThisRealNull;
}

Boolean Real::isNotNull() const throw() {
	return isNull().not();
}

Boolean Real::isPositive() const throw() {
	return isNegative().not();
}

Boolean Real::isNegative() const throw() {
	if ( isNull() ) return False;

	return Boolean::create( _real < internals::platform_short_real( 0.0 ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Real::operator internals::platform_real() const throw() {
// 	return _boolValue;
// }

internals::platform_real Real::getPlatformValue() const throw() {
	return _real;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Real::~Real() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Real::Real() throw() {
	_real = internals::platform_real( 0 );
}

// static
Real Real::create( const internals::platform_real real /*= default*/ ) {
	return Real( real );
}


Real::Real( const internals::platform_real real ) throw() {
	_real = real;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Real::Real( const Real &other ) throw() {
	_real = other._real;
}

const Real &Real::operator =( const Real &other ) throw() {
	if ( &other != this ) {
		_real = other._real;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	static
internals::platform_real Real::math_computeAbsolute( const internals::platform_real theReal ) {
	return theReal < internals::platform_real( 0.0 ) ? -theReal : theReal;
}

//	static
Boolean Real::math_isAboutZero( const internals::platform_real theReal ) {
	return Boolean::create( math_computeAbsolute( theReal ) > SHORT_REAL_DEFAULT_ACCURACY ).not();
}

//	static
Boolean Real::math_areAlmostEqual( const internals::platform_real firstReal, const internals::platform_real secondReal ) {
	return math_isAboutZero( firstReal - secondReal );
}


extern const Real RealZero = Real::create( internals::platform_real( 0.0 ) );
extern const Real RealOne = Real::create( internals::platform_real( 1.0 ) );
extern const Real RealTwo = Real::create( internals::platform_real( 2.0 ) );


} // namespace types
} // namespace jmsf
