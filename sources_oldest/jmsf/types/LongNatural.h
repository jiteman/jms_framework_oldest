#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class LongNatural {

public: // math
	LongNatural operator +( const LongNatural &other ) const throw();
	LongNatural &operator +=( const LongNatural &other ) throw();

	LongNatural operator -( const LongNatural &other ) const throw( Exception );
	LongNatural operator -=( const LongNatural &other ) throw( Exception );

//	LongNatural operator -() const throw();

	LongNatural operator *( const LongNatural &other ) const throw();
	LongNatural &operator *=( const LongNatural &other ) throw();

	LongNatural operator /( const LongNatural &other ) const throw( Exception );
	LongNatural &operator /=( const LongNatural &other ) throw( Exception );

	LongNatural operator %( const LongNatural &other ) const throw( Exception );
	LongNatural &operator %=( const LongNatural &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	LongNatural operator ^( const LongNatural &other ) const throw();
	LongNatural &operator ^=( const LongNatural &other ) throw();

	LongNatural operator &( const LongNatural &other ) const throw();
	LongNatural &operator &=( const LongNatural &other ) throw();

	LongNatural operator |( const LongNatural &other ) const throw();
	LongNatural &operator |=( const LongNatural &other ) throw();

	LongNatural operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	LongNatural operator !() const throw();
// 	LongNatural operator &&( const LongNatural &other ) const throw();
// 	LongNatural operator ||( const LongNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const LongNatural &other ) const throw();
	Boolean operator !=( const LongNatural &other ) const throw();
	Boolean operator <( const LongNatural &other ) const throw();
	Boolean operator <=( const LongNatural &other ) const throw();
	Boolean operator >( const LongNatural &other ) const throw();
	Boolean operator >=( const LongNatural &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	LongNatural operator <<( const ShortestNatural &other ) const throw();
	LongNatural &operator <<=( const ShortestNatural &other ) throw();

	LongNatural operator >>( const ShortestNatural &other ) const throw();
	LongNatural &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	LongNatural &operator ++() throw();
	LongNatural operator ++( int ) throw();
	LongNatural &operator --() throw( Exception );
	LongNatural operator --( int ) throw( Exception );

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
	internals::platform_unsigned_long_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~LongNatural() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	LongNatural() throw();

public:
	static LongNatural create( internals::platform_unsigned_long_int longNatural = internals::platform_unsigned_long_int( 0 ) );

private:
	LongNatural( internals::platform_unsigned_long_int longNatural ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	LongNatural( const LongNatural &other ) throw();
	const LongNatural &operator =( const LongNatural &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_unsigned_long_int _longNatural;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
