#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class LongInteger {

public: // math
	LongInteger operator +( const LongInteger &other ) const throw();
	LongInteger &operator +=( const LongInteger &other ) throw();

	LongInteger operator -( const LongInteger &other ) const throw();
	LongInteger operator -=( const LongInteger &other ) throw();

	LongInteger operator -() const throw();

	LongInteger operator *( const LongInteger &other ) const throw();
	LongInteger &operator *=( const LongInteger &other ) throw();

	LongInteger operator /( const LongInteger &other ) const throw( Exception );
	LongInteger &operator /=( const LongInteger &other ) throw( Exception );

	LongInteger operator %( const LongInteger &other ) const throw( Exception );
	LongInteger &operator %=( const LongInteger &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	LongInteger operator ^( const LongInteger &other ) const throw();
	LongInteger &operator ^=( const LongInteger &other ) throw();

	LongInteger operator &( const LongInteger &other ) const throw();
	LongInteger &operator &=( const LongInteger &other ) throw();

	LongInteger operator |( const LongInteger &other ) const throw();
	LongInteger &operator |=( const LongInteger &other ) throw();

	LongInteger operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	LongInteger operator !() const throw();
// 	LongInteger operator &&( const LongInteger &other ) const throw();
// 	LongInteger operator ||( const LongInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const LongInteger &other ) const throw();
	Boolean operator !=( const LongInteger &other ) const throw();
	Boolean operator <( const LongInteger &other ) const throw();
	Boolean operator <=( const LongInteger &other ) const throw();
	Boolean operator >( const LongInteger &other ) const throw();
	Boolean operator >=( const LongInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	LongInteger operator <<( const ShortestNatural &other ) const throw();
	LongInteger &operator <<=( const ShortestNatural &other ) throw();

	LongInteger operator >>( const ShortestNatural &other ) const throw();
	LongInteger &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	LongInteger &operator ++() throw();
	LongInteger operator ++( int ) throw();
	LongInteger &operator --() throw();
	LongInteger operator --( int ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // access
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
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean isNull() const throw();
	Boolean isNotNull() const throw();
	Boolean isPositive() const throw();
	Boolean isNegative() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_template_type() const throw();
	internals::platform_signed_long_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~LongInteger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	LongInteger() throw();

public:
	static LongInteger create( internals::platform_signed_long_int longInteger = internals::platform_signed_long_int( 0 ) );

private:
	LongInteger( internals::platform_signed_long_int longInteger ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	LongInteger( const LongInteger &other ) throw();
	const LongInteger &operator =( const LongInteger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_signed_long_int _longInteger;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
