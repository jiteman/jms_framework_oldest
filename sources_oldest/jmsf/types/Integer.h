#pragma once


#include "internals/internal_types.h"

#include "ShortestNatural.hxx"
#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class Integer {

public: // math
	Integer operator +( const Integer &other ) const throw();
	Integer &operator +=( const Integer &other ) throw();

	Integer operator -( const Integer &other ) const throw();
	Integer operator -=( const Integer &other ) throw();

	Integer operator -() const throw();

	Integer operator *( const Integer &other ) const throw();
	Integer &operator *=( const Integer &other ) throw();

	Integer operator /( const Integer &other ) const throw( Exception );
	Integer &operator /=( const Integer &other ) throw( Exception );

	Integer operator %( const Integer &other ) const throw( Exception );
	Integer &operator %=( const Integer &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Integer operator ^( const Integer &other ) const throw();
	Integer &operator ^=( const Integer &other ) throw();

	Integer operator &( const Integer &other ) const throw();
	Integer &operator &=( const Integer &other ) throw();

	Integer operator |( const Integer &other ) const throw();
	Integer &operator |=( const Integer &other ) throw();

	Integer operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Integer operator !() const throw();
// 	Integer operator &&( const Integer &other ) const throw();
// 	Integer operator ||( const Integer &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Integer &other ) const throw();
	Boolean operator !=( const Integer &other ) const throw();
	Boolean operator <( const Integer &other ) const throw();
	Boolean operator <=( const Integer &other ) const throw();
	Boolean operator >( const Integer &other ) const throw();
	Boolean operator >=( const Integer &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Integer operator <<( const ShortestNatural &other ) const throw();
	Integer &operator <<=( const ShortestNatural &other ) throw();

	Integer operator >>( const ShortestNatural &other ) const throw();
	Integer &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Integer &operator ++() throw();
	Integer operator ++( int ) throw();
	Integer &operator --() throw();
	Integer operator --( int ) throw();

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
	internals::platform_signed_int getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Integer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integer() throw();

public:
	static Integer create( internals::platform_signed_int integer = internals::platform_signed_int( 0 ) );

private:
	Integer( internals::platform_signed_int integer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integer( const Integer &other ) throw();
	const Integer &operator =( const Integer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_signed_int _integer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
