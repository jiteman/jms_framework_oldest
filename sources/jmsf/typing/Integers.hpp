#pragma once


#include "Integers.hxx"

#include "Naturals.hxx"
#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


template< class > class Naturals;


template< class A_type >
class Integers {

public: // math
	Integers operator +( const Integers &another ) const noexept;
	Integers &operator +=( const Integers &another ) noexept;

	Integers operator -( const Integers &another ) const noexept;
	Integers operator -=( const Integers &another ) noexept;

	Integers operator -() const noexept;

	Integers operator *( const Integers &another ) const noexept;
	Integers &operator *=( const Integers &another ) noexept;

	Integers operator /( const Integers &another ) const;
	Integers &operator /=( const Integers &another );

	Integers operator %( const Integers &another ) const;
	Integers &operator %=( const Integers &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Integers operator ^( const Integers &another ) const noexept;
	Integers &operator ^=( const Integers &another ) noexept;

	Integers operator &( const Integers &another ) const noexept;
	Integers &operator &=( const Integers &another ) noexept;

	Integers operator |( const Integers &another ) const noexept;
	Integers &operator |=( const Integers &another ) noexept;

	Integers operator ~() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Integers operator !() const noexept;
// 	Integers operator &&( const Integers &another ) const noexept;
// 	Integers operator ||( const Integers &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Integers &another ) const noexept;
	Boolean operator !=( const Integers &another ) const noexept;
	Boolean operator <( const Integers &another ) const noexept;
	Boolean operator <=( const Integers &another ) const noexept;
	Boolean operator >( const Integers &another ) const noexept;
	Boolean operator >=( const Integers &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Integers get_shifted_left() const noexept;
	Integers &shift_left() noexept;
	Integers operator <<( Memory_size shift_value ) const noexept;
	Integers &operator <<=( Memory_size shift_value ) noexept;

	Integers get_shifted_right() const noexept;
	Integers &shift_right() noexept;
	Integers operator >>( Memory_size shift_value ) const noexept;
	Integers &operator >>=( Memory_size shift_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Integers &operator ++() noexept;
	Integers operator ++( int ) noexept;
	Integers &operator --() noexept;
	Integers operator --( int ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // access
// 	ret_type &operator *() noexept;
// 	const ret_type &operator *() const noexept;
// 	ret_type *operator ->() noexept;
// 	const ret_type *operator ->() const noexept;
	
// 	ret_type &operator []( Unsigned index ) noexept;
// 	const ret_type &operator []( Unsigned index ) const noexept;
		
// 	ret_type operator()( parameters ) const noexept;
// 	ret_type operator()( parameters ) noexept;

//	operator ->*(); // pointer-to-member selection

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate );
//	void *operator new[]( Unsigned quantityToAllocate );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_nill() const noexept;
	Boolean is_not_nill() const noexept;
	Boolean is_positive() const noexept;
	Boolean is_negative() const noexept;
	Boolean is_max() const noexept;
	Boolean is_not_max() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_template_type() const noexept;
	A_type get_value() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Integers() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integers() noexept;

public:
	static Integers create( A_type integer_value = A_type( 0 ) ) noexept;

private:
	Integers( A_type integer_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Integers( const Integers &another ) noexept;
	const Integers &operator =( const Integers &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _integer_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


extern const Shortest_integer Shortest_integer_badmax;
extern const Shortest_integer Shortest_integer_nill;
extern const Shortest_integer Shortest_integer_one;
extern const Shortest_integer Shortest_integer_minus;

extern const Short_integer Short_integer_badmax;
extern const Short_integer Short_integer_nill;
extern const Short_integer Short_integer_one;
extern const Short_integer Short_integer_minus;

extern const Integer Integer_badmax;
extern const Integer Integer_nill;
extern const Integer Integer_one;
extern const Integer Integer_minus;

extern const Long_integer Long_integer_badmax;
extern const Long_integer Long_integer_nill;
extern const Long_integer Long_integer_one;
extern const Long_integer Long_integer_minus;

extern const Memory_diff Memory_diff_badmax;
extern const Memory_diff Memory_diff_nill;
extern const Memory_diff Memory_diff_one;
extern const Memory_diff Memory_diff_minus;

extern const File_diff File_diff_badmax;
extern const File_diff File_diff_nill;
extern const File_diff File_diff_one;
extern const File_diff File_diff_minus;


} // namespace typing
} // namespace jmsf
