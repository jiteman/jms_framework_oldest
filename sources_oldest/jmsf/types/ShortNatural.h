#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class ShortNatural {

public: // math
	ShortNatural operator +( const ShortNatural &other ) const throw();
	ShortNatural &operator +=( const ShortNatural &other ) throw();

	ShortNatural operator -( const ShortNatural &other ) const throw( Exception );
	ShortNatural operator -=( const ShortNatural &other ) throw( Exception );

//	ShortNatural operator -() const throw();

	ShortNatural operator *( const ShortNatural &other ) const throw();
	ShortNatural &operator *=( const ShortNatural &other ) throw();

	ShortNatural operator /( const ShortNatural &other ) const throw( Exception );
	ShortNatural &operator /=( const ShortNatural &other ) throw( Exception );

	ShortNatural operator %( const ShortNatural &other ) const throw( Exception );
	ShortNatural &operator %=( const ShortNatural &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	ShortNatural operator ^( const ShortNatural &other ) const throw();
	ShortNatural &operator ^=( const ShortNatural &other ) throw();

	ShortNatural operator &( const ShortNatural &other ) const throw();
	ShortNatural &operator &=( const ShortNatural &other ) throw();

	ShortNatural operator |( const ShortNatural &other ) const throw();
	ShortNatural &operator |=( const ShortNatural &other ) throw();

	ShortNatural operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	ShortNatural operator !() const throw();
// 	ShortNatural operator &&( const ShortNatural &other ) const throw();
// 	ShortNatural operator ||( const ShortNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const ShortNatural &other ) const throw();
	Boolean operator !=( const ShortNatural &other ) const throw();
	Boolean operator <( const ShortNatural &other ) const throw();
	Boolean operator <=( const ShortNatural &other ) const throw();
	Boolean operator >( const ShortNatural &other ) const throw();
	Boolean operator >=( const ShortNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	ShortNatural operator <<( const ShortestNatural &other ) const throw();
	ShortNatural &operator <<=( const ShortestNatural &other ) throw();

	ShortNatural operator >>( const ShortestNatural &other ) const throw();
	ShortNatural &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	ShortNatural &operator ++() throw();
	ShortNatural operator ++( int ) throw();
	ShortNatural &operator --() throw( Exception );
	ShortNatural operator --( int ) throw( Exception );

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
	internals::platform_unsigned_short_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ShortNatural() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortNatural() throw();

public:
	static ShortNatural create( internals::platform_unsigned_short_int shortNatural = internals::platform_unsigned_short_int( 0 ) );

private:
	ShortNatural( internals::platform_unsigned_short_int shortNatural ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortNatural( const ShortNatural &other ) throw();
	const ShortNatural &operator =( const ShortNatural &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_unsigned_short_int _shortNatural;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
