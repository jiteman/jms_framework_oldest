#include "Asd.h"


#include "ShortestNatural.h"


namespace jmsf {
namespace types {


// math
Asd Asd::operator +( const Asd &other ) const throw() {
	Asd result = *this;
	result += other;
	return result;
}

Asd &Asd::operator +=( const Asd &other ) throw() {
	if ( _isNegative == other._isNegative ) {
		_address += other._address;
	} else if ( _address == other._address ) {
		_isNegative == False;
		_address = types::internals::platform_memory_size( 0 );
	} else if ( _address > other._address ) {
		_address -= other._address;
	} else { // _address < other._address
		_isNegative = other._isNegative;
		_address = other._address - _address;
	}

	return *this;
}

Asd Asd::operator -( const Asd &other ) const throw( Exception ) {
	Asd result = *this;
	result += -other ;
	return result;
}

Asd Asd::operator -=( const Asd &other ) throw( Exception ) {
	operator +=( -other );
	return *this;
}

Asd Asd::operator -() const throw() {
	Asd result = *this;
	result._isNegative = result._isNegative.not();
	return result;
}

Asd Asd::operator *( const Asd &other ) const throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative multiplication of address
	}

	return Asd::create( _address * other._address );
}

Asd &Asd::operator *=( const Asd &other ) throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative multiplication of address
	}

	_isNegative = _isNegative != other._isNegative;
	_address *= other._address;
	return *this;
}

Asd Asd::operator /( const Asd &other ) const throw( Exception ) {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative division of address
	}

	if ( other._address == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	return Asd::create( _address / other._address );
}

Asd &Asd::operator /=( const Asd &other ) throw( Exception ) {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative division of address
	}

	if ( other._address == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	_address /= other._address;
	return *this;
}

Asd Asd::operator %( const Asd &other ) const throw( Exception ) {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative division of address
	}

	if ( other._address == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	return Asd::create( _address % other._address );
}

Asd &Asd::operator %=( const Asd &other ) throw( Exception ) {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative division of address
	}

	if ( other._address == internals::platform_unsigned_int( 0 ) ) {
		// throw division by zero
	}

	_address %= other._address;
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bitwise
Asd Asd::operator ^( const Asd &other ) const throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise XOR of address
	}

	return Asd::create( _address ^ other._address );
}

Asd &Asd::operator ^=( const Asd &other ) throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise XOR of address
	}

	_address ^= other._address;
	return *this;
}

Asd Asd::operator &( const Asd &other ) const throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise AND of address
	}

	return Asd::create( _address & other._address );
}

Asd &Asd::operator &=( const Asd &other ) throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise AND of address
	}

	_address &= other._address;
	return *this;
}

Asd Asd::operator |( const Asd &other ) const throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise OR of address
	}

	return Asd::create( _address | other._address );
}

Asd &Asd::operator |=( const Asd &other ) throw() {
	if ( _isNegative.or( other._isNegative ) ) {
		// throw negative bitwise OR of address
	}

	_address |= other._address;
	return *this;
}

Asd Asd::operator ~() const throw() {
	if ( _isNegative ) {
		// throw negative bitwise COMPLEMENT of address
	}

	return Asd::create( ~_address );
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
Boolean Asd::operator ==( const Asd &other ) const throw() {
	return Boolean::create( _address == other._address ).and( _isNegative == other._isNegative );
}

Boolean Asd::operator !=( const Asd &other ) const throw() {
	return operator ==( other ).not();
}

Boolean Asd::operator <( const Asd &other ) const throw() {
	if ( _isNegative == other._isNegative ) {
		return Boolean::create( _isNegative ? _address > other._address : _address < other._address );
	}
	
	return _isNegative;	
}

Boolean Asd::operator <=( const Asd &other ) const throw() {
	if ( operator ==( other ) ) return True;

	return operator <( other );
}

Boolean Asd::operator >( const Asd &other ) const throw() {
	if ( _isNegative == other._isNegative ) {
		return Boolean::create( _isNegative ? _address < other._address : _address > other._address );
	}
	
	return other._isNegative;
}

Boolean Asd::operator >=( const Asd &other ) const throw() {
	if ( operator ==( other ) ) return True;

	return operator >( other );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// shifts
Asd Asd::operator <<( const ShortestNatural &other ) const throw() {
	if ( _isNegative ) {
		// throw negative left shift of address
	}

	return Asd::create( _address << other.getPlatformValue() );
}

Asd &Asd::operator <<=( const ShortestNatural &other ) throw() {
	if ( _isNegative ) {
		// throw negative left shift of address
	}

	_address <<= other.getPlatformValue();
	return *this;
}

Asd Asd::operator >>( const ShortestNatural &other ) const throw() {
	if ( _isNegative ) {
		// throw negative right shift of address
	}

	return Asd::create( _address >> other.getPlatformValue() );
}

Asd &Asd::operator >>=( const ShortestNatural &other ) throw() {
	if ( _isNegative ) {
		// throw negative right shift of address
	}

	_address >>= other.getPlatformValue();
	return *this;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// increment/decrement
Asd &Asd::operator ++() throw() {
	if ( _isNegative ) {
		// throw negative increment of address
	}

	_address += 1;
	return *this;
}

Asd Asd::operator ++( int ) throw() {
	if ( _isNegative ) {
		// throw negative increment of address
	}

	return Asd::create( _address + 1 );
}

Asd &Asd::operator --() throw( Exception ) {
	if ( _isNegative ) {
		// throw negative decrement of address
	}

	if ( _address == internals::platform_memory_size( 0 ) ) {
		// throw underflow
	}

	_address -= 1;
	return *this;
}

Asd Asd::operator --( int ) throw( Exception ) {
	if ( _isNegative ) {
		// throw negative decrement of address
	}

	if ( _address == internals::platform_memory_size( 0 ) ) {
		// throw underflow
	}

	return Asd::create( _address - 1 );
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
Boolean Asd::isNull() const throw() {
	return Boolean::create( _address == internals::platform_memory_size( 0 ) );
}

Boolean Asd::isNotNull() const throw() {
	return isNull().not();
}

Boolean Asd::isPositive() const throw() {
	return _isNegative.not();
}

Boolean Asd::isNegative() const throw() {
	return _isNegative;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Byte::operator internals::platform_unsigned_int() const throw() {
// 	return _boolValue;
// }

internals::platform_unsigned_int Asd::getPlatformValue() const throw() {
	return _address;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Asd::~Asd() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Asd::Asd() throw() {
	_address = internals::platform_memory_size( 0 );
}

// static
Asd Asd::create( const internals::platform_memory_size natural /*= default*/, Boolean isItNegative /*= default*/ ) {
	return Asd( natural, isItNegative );
}


Asd::Asd( const internals::platform_memory_size natural, Boolean isItNegative ) throw() {
	_isNegative = isItNegative;
	_address = natural;	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Asd::Asd( const Asd &other ) throw() {
	_isNegative = other._isNegative;
	_address = other._address;
}

const Asd &Asd::operator =( const Asd &other ) throw() {
	if ( &other != this ) {
		_isNegative = other._isNegative;
		_address = other._address;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace types
} // namespace jmsf
