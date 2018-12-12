#pragma once


#include "internals/internal_types.h"
#include "Boolean.h"

#include "ShortestNatural.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


// memory address, memory size and memory address difference
class Asd {

public: // math
	Asd operator +( const Asd &other ) const throw();
	Asd &operator +=( const Asd &other ) throw();

	Asd operator -( const Asd &other ) const throw( Exception );
	Asd operator -=( const Asd &other ) throw( Exception );

	Asd operator -() const throw();

	Asd operator *( const Asd &other ) const throw();
	Asd &operator *=( const Asd &other ) throw();

	Asd operator /( const Asd &other ) const throw( Exception );
	Asd &operator /=( const Asd &other ) throw( Exception );

	Asd operator %( const Asd &other ) const throw( Exception );
	Asd &operator %=( const Asd &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Asd operator ^( const Asd &other ) const throw();
	Asd &operator ^=( const Asd &other ) throw();

	Asd operator &( const Asd &other ) const throw();
	Asd &operator &=( const Asd &other ) throw();

	Asd operator |( const Asd &other ) const throw();
	Asd &operator |=( const Asd &other ) throw();

	Asd operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Asd operator !() const throw();
// 	Asd operator &&( const Asd &other ) const throw();
// 	Asd operator ||( const Asd &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Asd &other ) const throw();
	Boolean operator !=( const Asd &other ) const throw();
	Boolean operator <( const Asd &other ) const throw();
	Boolean operator <=( const Asd &other ) const throw();
	Boolean operator >( const Asd &other ) const throw();
	Boolean operator >=( const Asd &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Asd operator <<( const ShortestNatural &other ) const throw();
	Asd &operator <<=( const ShortestNatural &other ) throw();

	Asd operator >>( const ShortestNatural &other ) const throw();
	Asd &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Asd &operator ++() throw();
	Asd operator ++( int ) throw();
	Asd &operator --() throw( Exception );
	Asd operator --( int ) throw( Exception );

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
//	operator internals::platform_unsigned_char() const throw();
	internals::platform_memory_size getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Asd() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Asd() throw();

public:
	static Asd create( internals::platform_memory_size address = internals::platform_memory_size( 0 ), Boolean isItNegative = False );

private:
	Asd( internals::platform_memory_size address, Boolean isItNegative ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Asd( const Asd &other ) throw();
	const Asd &operator =( const Asd &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

	internals::platform_memory_size _address;
	Boolean _isNegative;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace types
} // namespace jmsf
