#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class ShortInteger {

public: // math
	ShortInteger operator +( const ShortInteger &other ) const throw();
	ShortInteger &operator +=( const ShortInteger &other ) throw();

	ShortInteger operator -( const ShortInteger &other ) const throw();
	ShortInteger operator -=( const ShortInteger &other ) throw();

	ShortInteger operator -() const throw();

	ShortInteger operator *( const ShortInteger &other ) const throw();
	ShortInteger &operator *=( const ShortInteger &other ) throw();

	ShortInteger operator /( const ShortInteger &other ) const throw( Exception );
	ShortInteger &operator /=( const ShortInteger &other ) throw( Exception );

	ShortInteger operator %( const ShortInteger &other ) const throw( Exception );
	ShortInteger &operator %=( const ShortInteger &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	ShortInteger operator ^( const ShortInteger &other ) const throw();
	ShortInteger &operator ^=( const ShortInteger &other ) throw();

	ShortInteger operator &( const ShortInteger &other ) const throw();
	ShortInteger &operator &=( const ShortInteger &other ) throw();

	ShortInteger operator |( const ShortInteger &other ) const throw();
	ShortInteger &operator |=( const ShortInteger &other ) throw();

	ShortInteger operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	ShortInteger operator !() const throw();
// 	ShortInteger operator &&( const ShortInteger &other ) const throw();
// 	ShortInteger operator ||( const ShortInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const ShortInteger &other ) const throw();
	Boolean operator !=( const ShortInteger &other ) const throw();
	Boolean operator <( const ShortInteger &other ) const throw();
	Boolean operator <=( const ShortInteger &other ) const throw();
	Boolean operator >( const ShortInteger &other ) const throw();
	Boolean operator >=( const ShortInteger &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	ShortInteger operator <<( const ShortestNatural &other ) const throw();
	ShortInteger &operator <<=( const ShortestNatural &other ) throw();

	ShortInteger operator >>( const ShortestNatural &other ) const throw();
	ShortInteger &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	ShortInteger &operator ++() throw();
	ShortInteger operator ++( int ) throw();
	ShortInteger &operator --() throw();
	ShortInteger operator --( int ) throw();

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
	internals::platform_signed_short_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ShortInteger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortInteger() throw();

public:
	static ShortInteger create( internals::platform_signed_short_int shortInteger = internals::platform_signed_short_int( 0 ) );

private:
	ShortInteger( internals::platform_signed_short_int shortInteger ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortInteger( const ShortInteger &other ) throw();
	const ShortInteger &operator =( const ShortInteger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_signed_short_int _shortInteger;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
