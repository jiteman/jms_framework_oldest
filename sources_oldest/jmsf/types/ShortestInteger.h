#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class ShortestInteger {

public: // math
	ShortestInteger operator +( const ShortestInteger &other ) const throw();
	ShortestInteger &operator +=( const ShortestInteger &other ) throw();

	ShortestInteger operator -( const ShortestInteger &other ) const throw();
	ShortestInteger operator -=( const ShortestInteger &other ) throw();

	ShortestInteger operator -() const throw();

	ShortestInteger operator *( const ShortestInteger &other ) const throw();
	ShortestInteger &operator *=( const ShortestInteger &other ) throw();

	ShortestInteger operator /( const ShortestInteger &other ) const throw( Exception );
	ShortestInteger &operator /=( const ShortestInteger &other ) throw( Exception );

	ShortestInteger operator %( const ShortestInteger &other ) const throw( Exception );
	ShortestInteger &operator %=( const ShortestInteger &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	ShortestInteger operator ^( const ShortestInteger &other ) const throw();
	ShortestInteger &operator ^=( const ShortestInteger &other ) throw();

	ShortestInteger operator &( const ShortestInteger &other ) const throw();
	ShortestInteger &operator &=( const ShortestInteger &other ) throw();

	ShortestInteger operator |( const ShortestInteger &other ) const throw();
	ShortestInteger &operator |=( const ShortestInteger &other ) throw();

	ShortestInteger operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	ShortestInteger operator !() const throw();
// 	ShortestInteger operator &&( const ShortestInteger &other ) const throw();
// 	ShortestInteger operator ||( const ShortestInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const ShortestInteger &other ) const throw();
	Boolean operator !=( const ShortestInteger &other ) const throw();
	Boolean operator <( const ShortestInteger &other ) const throw();
	Boolean operator <=( const ShortestInteger &other ) const throw();
	Boolean operator >( const ShortestInteger &other ) const throw();
	Boolean operator >=( const ShortestInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	ShortestInteger operator <<( const ShortestNatural &other ) const throw();
	ShortestInteger &operator <<=( const ShortestNatural &other ) throw();

	ShortestInteger operator >>( const ShortestNatural &other ) const throw();
	ShortestInteger &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	ShortestInteger &operator ++() throw();
	ShortestInteger operator ++( int ) throw();
	ShortestInteger &operator --() throw();
	ShortestInteger operator --( int ) throw();

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
	internals::platform_signed_char getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ShortestInteger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortestInteger() throw();

public:
	static ShortestInteger create( internals::platform_signed_char shortestInteger = internals::platform_signed_char( 0 ) );

private:
	ShortestInteger( internals::platform_signed_char shortestInteger ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortestInteger( const ShortestInteger &other ) throw();
	const ShortestInteger &operator =( const ShortestInteger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_signed_char _shortestInteger;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
