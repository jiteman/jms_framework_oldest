#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class Natural {

public: // math
	Natural operator +( const Natural &other ) const throw();
	Natural &operator +=( const Natural &other ) throw();

	Natural operator -( const Natural &other ) const throw( Exception );
	Natural operator -=( const Natural &other ) throw( Exception );

//	Natural operator -() const throw();

	Natural operator *( const Natural &other ) const throw();
	Natural &operator *=( const Natural &other ) throw();

	Natural operator /( const Natural &other ) const throw( Exception );
	Natural &operator /=( const Natural &other ) throw( Exception );

	Natural operator %( const Natural &other ) const throw( Exception );
	Natural &operator %=( const Natural &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Natural operator ^( const Natural &other ) const throw();
	Natural &operator ^=( const Natural &other ) throw();

	Natural operator &( const Natural &other ) const throw();
	Natural &operator &=( const Natural &other ) throw();

	Natural operator |( const Natural &other ) const throw();
	Natural &operator |=( const Natural &other ) throw();

	Natural operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Natural operator !() const throw();
// 	Natural operator &&( const Natural &other ) const throw();
// 	Natural operator ||( const Natural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Natural &other ) const throw();
	Boolean operator !=( const Natural &other ) const throw();
	Boolean operator <( const Natural &other ) const throw();
	Boolean operator <=( const Natural &other ) const throw();
	Boolean operator >( const Natural &other ) const throw();
	Boolean operator >=( const Natural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Natural operator <<( const ShortestNatural &other ) const throw();
	Natural &operator <<=( const ShortestNatural &other ) throw();

	Natural operator >>( const ShortestNatural &other ) const throw();
	Natural &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Natural &operator ++() throw();
	Natural operator ++( int ) throw();
	Natural &operator --() throw( Exception );
	Natural operator --( int ) throw( Exception );

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_unsigned_char() const throw();
	internals::platform_unsigned_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Natural() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Natural() throw();

public:
	static Natural create( internals::platform_unsigned_int natural = internals::platform_unsigned_int( 0 ) );

private:
	Natural( internals::platform_unsigned_int natural ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Natural( const Natural &other ) throw();
	const Natural &operator =( const Natural &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_unsigned_int _natural;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
