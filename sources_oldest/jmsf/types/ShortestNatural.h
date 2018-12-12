#pragma once


#include "internals/internal_types.h"

#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class ShortestNatural {

public: // math
	ShortestNatural operator +( const ShortestNatural &other ) const throw();
	ShortestNatural &operator +=( const ShortestNatural &other ) throw();

	ShortestNatural operator -( const ShortestNatural &other ) const throw( Exception );
	ShortestNatural operator -=( const ShortestNatural &other ) throw( Exception );

//	ShortestNatural operator -() const throw();

	ShortestNatural operator *( const ShortestNatural &other ) const throw();
	ShortestNatural &operator *=( const ShortestNatural &other ) throw();

	ShortestNatural operator /( const ShortestNatural &other ) const throw( Exception );
	ShortestNatural &operator /=( const ShortestNatural &other ) throw( Exception );

	ShortestNatural operator %( const ShortestNatural &other ) const throw( Exception );
	ShortestNatural &operator %=( const ShortestNatural &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	ShortestNatural operator ^( const ShortestNatural &other ) const throw();
	ShortestNatural &operator ^=( const ShortestNatural &other ) throw();

	ShortestNatural operator &( const ShortestNatural &other ) const throw();
	ShortestNatural &operator &=( const ShortestNatural &other ) throw();

	ShortestNatural operator |( const ShortestNatural &other ) const throw();
	ShortestNatural &operator |=( const ShortestNatural &other ) throw();

	ShortestNatural operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	ShortestNatural operator !() const throw();
// 	ShortestNatural operator &&( const ShortestNatural &other ) const throw();
// 	ShortestNatural operator ||( const ShortestNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const ShortestNatural &other ) const throw();
	Boolean operator !=( const ShortestNatural &other ) const throw();
	Boolean operator <( const ShortestNatural &other ) const throw();
	Boolean operator <=( const ShortestNatural &other ) const throw();
	Boolean operator >( const ShortestNatural &other ) const throw();
	Boolean operator >=( const ShortestNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	ShortestNatural operator <<( const ShortestNatural &other ) const throw();
	ShortestNatural &operator <<=( const ShortestNatural &other ) throw();

	ShortestNatural operator >>( const ShortestNatural &other ) const throw();
	ShortestNatural &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	ShortestNatural &operator ++() throw();
	ShortestNatural operator ++( int ) throw();
	ShortestNatural &operator --() throw( Exception );
	ShortestNatural operator --( int ) throw( Exception );

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
	internals::platform_unsigned_char getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ShortestNatural() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortestNatural() throw();

public:
	static ShortestNatural create( internals::platform_unsigned_char shortestNatural = internals::platform_unsigned_char( 0 ) );

private:
	ShortestNatural( internals::platform_unsigned_char shortestNatural ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortestNatural( const ShortestNatural &other ) throw();
	const ShortestNatural &operator =( const ShortestNatural &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_unsigned_char _shortestNatural;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
