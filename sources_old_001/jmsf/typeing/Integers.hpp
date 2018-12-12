#pragma once


#include "Integers.hxx"

#include "Naturals.hxx"
#include "Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace typeing {


template< class, int > class Naturals;


template< class A_type, int dummy >
class Integers {

public: // math
	Integers operator +( const Integers &another ) const noexcept;
	Integers &operator +=( const Integers &another ) noexcept;

	Integers operator -( const Integers &another ) const noexcept;
	Integers operator -=( const Integers &another ) noexcept;

	Integers operator -() const noexcept;

	Integers operator *( const Integers &another ) const noexcept;
	Integers &operator *=( const Integers &another ) noexcept;

	Integers operator /( const Integers &another ) const;
	Integers &operator /=( const Integers &another );

	Integers operator %( const Integers &another ) const;
	Integers &operator %=( const Integers &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Integers operator ^( const Integers &another ) const noexcept;
	Integers &operator ^=( const Integers &another ) noexcept;

	Integers operator &( const Integers &another ) const noexcept;
	Integers &operator &=( const Integers &another ) noexcept;

	Integers operator |( const Integers &another ) const noexcept;
	Integers &operator |=( const Integers &another ) noexcept;

	Integers operator ~() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Integers operator !() const noexcept;
// 	Integers operator &&( const Integers &another ) const noexcept;
// 	Integers operator ||( const Integers &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Integers &another ) const noexcept;
	Boolean operator !=( const Integers &another ) const noexcept;
	Boolean operator <( const Integers &another ) const noexcept;
	Boolean operator <=( const Integers &another ) const noexcept;
	Boolean operator >( const Integers &another ) const noexcept;
	Boolean operator >=( const Integers &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Integers get_shifted_left() const noexcept;
	Integers &shift_left() noexcept;
	Integers operator <<( Memory_natural shift_value ) const noexcept;
	Integers &operator <<=( Memory_natural shift_value ) noexcept;

	Integers get_shifted_right() const noexcept;
	Integers &shift_right() noexcept;
	Integers operator >>( Memory_natural shift_value ) const noexcept;
	Integers &operator >>=( Memory_natural shift_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Integers &operator ++() noexcept;
	Integers operator ++( int ) noexcept;
	Integers &operator --() noexcept;
	Integers operator --( int ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // access
// 	ret_type &operator *() noexcept;
// 	const ret_type &operator *() const noexcept;
// 	ret_type *operator ->() noexcept;
// 	const ret_type *operator ->() const noexcept;

// 	ret_type &operator []( Unsigned index ) noexcept;
// 	const ret_type &operator []( Unsigned index ) const noexcept;

// 	ret_type operator()( parameters ) const noexcept;
// 	ret_type operator()( parameters ) noexcept;

//	operator ->*(); // pointer-to-member selection

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate );
//	void *operator new[]( Unsigned quantityToAllocate );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_nill() const noexcept;
	Boolean is_not_nill() const noexcept;
	Boolean is_positive() const noexcept;
	Boolean is_negative() const noexcept;
	Boolean is_max() const noexcept;
	Boolean is_not_max() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_template_type() const noexcept;
	A_type get_native_value() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Integers() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integers() noexcept;

public:
	static Integers create( A_type integer_value = A_type( 0 ) ) noexcept;

private:
	Integers( A_type integer_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integers( const Integers &another ) noexcept;
	const Integers &operator =( const Integers &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _integer_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


extern const Memory_integer Memory_integer_badmax;
extern const Memory_integer Memory_integer_nill;
extern const Memory_integer Memory_integer_one;
extern const Memory_integer Memory_integer_minus;

extern const File_integer File_integer_badmax;
extern const File_integer File_integer_nill;
extern const File_integer File_integer_one;
extern const File_integer File_integer_minus;

extern const Shortest_integer Shortest_integer_badmax;
extern const Shortest_integer Shortest_integer_nill;
extern const Shortest_integer Shortest_integer_one;
extern const Shortest_integer Shortest_integer_minus;

extern const Shortest_integer_small Shortest_integer_small_badmax;
extern const Shortest_integer_small Shortest_integer_small_nill;
extern const Shortest_integer_small Shortest_integer_small_one;
extern const Shortest_integer_small Shortest_integer_small_minus;

extern const Short_integer Short_integer_badmax;
extern const Short_integer Short_integer_nill;
extern const Short_integer Short_integer_one;
extern const Short_integer Short_integer_minus;

extern const Short_integer_small Short_integer_small_badmax;
extern const Short_integer_small Short_integer_small_nill;
extern const Short_integer_small Short_integer_small_one;
extern const Short_integer_small Short_integer_small_minus;

extern const Integer Integer_badmax;
extern const Integer Integer_nill;
extern const Integer Integer_one;
extern const Integer Integer_minus;

extern const Integer_small Integer_small_badmax;
extern const Integer_small Integer_small_nill;
extern const Integer_small Integer_small_one;
extern const Integer_small Integer_small_minus;

extern const Long_integer Long_integer_badmax;
extern const Long_integer Long_integer_nill;
extern const Long_integer Long_integer_one;
extern const Long_integer Long_integer_minus;

extern const Long_integer_small Long_integer_small_badmax;
extern const Long_integer_small Long_integer_small_nill;
extern const Long_integer_small Long_integer_small_one;
extern const Long_integer_small Long_integer_small_minus;


} // namespace typeing
} // namespace jmsf
