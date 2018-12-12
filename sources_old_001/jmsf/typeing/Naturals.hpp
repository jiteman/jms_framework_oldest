#pragma once


#include "Naturals.hxx"

#include "Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace typeing {


template< class A_type, int dummy >
class Naturals {

public: // math
	Naturals operator +( const Naturals &another ) const noexcept;
	Naturals &operator +=( const Naturals &another ) noexcept;

	Naturals operator -( const Naturals &another ) const noexcept;
	Naturals operator -=( const Naturals &another ) noexcept;

//	Naturals operator -() const noexcept;

	Naturals operator *( const Naturals &another ) const noexcept;
	Naturals &operator *=( const Naturals &another ) noexcept;

	Naturals operator /( const Naturals &another ) const;
	Naturals &operator /=( const Naturals &another );

	Naturals operator %( const Naturals &another ) const;
	Naturals &operator %=( const Naturals &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Naturals operator ^( const Naturals &another ) const noexcept;
	Naturals &operator ^=( const Naturals &another ) noexcept;

	Naturals operator &( const Naturals &another ) const noexcept;
	Naturals &operator &=( const Naturals &another ) noexcept;

	Naturals operator |( const Naturals &another ) const noexcept;
	Naturals &operator |=( const Naturals &another ) noexcept;

	Naturals operator ~() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Naturals operator !() const noexcept;
// 	Naturals operator &&( const Naturals &another ) const noexcept;
// 	Naturals operator ||( const Naturals &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Naturals &another ) const noexcept;
	Boolean operator !=( const Naturals &another ) const noexcept;
	Boolean operator <( const Naturals &another ) const noexcept;
	Boolean operator <=( const Naturals &another ) const noexcept;
	Boolean operator >( const Naturals &another ) const noexcept;
	Boolean operator >=( const Naturals &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Naturals get_shifted_left() const noexcept;
	Naturals &shift_left() noexcept;
	Naturals operator <<( Memory_natural shift_value ) const noexcept;
	Naturals &operator <<=( Memory_natural shift_value ) noexcept;

	Naturals get_shifted_right() const noexcept;
	Naturals &shift_right() noexcept;
	Naturals operator >>( Memory_natural shift_value ) const noexcept;
	Naturals &operator >>=( Memory_natural shift_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Naturals &operator ++() noexcept;
	Naturals operator ++( int ) noexcept;
	Naturals &operator --() noexcept;
	Naturals operator --( int ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) ;
//	void *operator new[]( Unsigned quantityToAllocate ) ;
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_nill() const noexcept;
	Boolean is_not_nill() const noexcept;
	Boolean is_max() const noexcept;
	Boolean is_not_max() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_unsigned_char() const noexcept;
	A_type get_native_value() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Naturals() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Naturals() noexcept;

public:
	static Naturals create( A_type natural_value = A_type( 0 ) ) noexcept;

private:
	Naturals( A_type natural_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Naturals( const Naturals &another ) noexcept;
	const Naturals &operator =( const Naturals &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _natural_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


JMSF_SHARED_INTERFACE extern const Memory_natural Memory_natural_badmax;
JMSF_SHARED_INTERFACE extern const Memory_natural Memory_natural_nill;
JMSF_SHARED_INTERFACE extern const Memory_natural Memory_natural_one;

JMSF_SHARED_INTERFACE extern const File_natural File_natural_badmax;
JMSF_SHARED_INTERFACE extern const File_natural File_natural_nill;
JMSF_SHARED_INTERFACE extern const File_natural File_natural_one;

JMSF_SHARED_INTERFACE extern const Shortest_natural Shortest_natural_badmax;
JMSF_SHARED_INTERFACE extern const Shortest_natural Shortest_natural_nill;
JMSF_SHARED_INTERFACE extern const Shortest_natural Shortest_natural_one;

JMSF_SHARED_INTERFACE extern const Shortest_natural_small Shortest_natural_small_badmax;
JMSF_SHARED_INTERFACE extern const Shortest_natural_small Shortest_natural_small_nill;
JMSF_SHARED_INTERFACE extern const Shortest_natural_small Shortest_natural_small_one;

JMSF_SHARED_INTERFACE extern const Short_natural Short_natural_badmax;
JMSF_SHARED_INTERFACE extern const Short_natural Short_natural_nill;
JMSF_SHARED_INTERFACE extern const Short_natural Short_natural_one;

JMSF_SHARED_INTERFACE extern const Short_natural_small Short_natural_small_badmax;
JMSF_SHARED_INTERFACE extern const Short_natural_small Short_natural_small_nill;
JMSF_SHARED_INTERFACE extern const Short_natural_small Short_natural_small_one;

JMSF_SHARED_INTERFACE extern const Natural Natural_badmax;
JMSF_SHARED_INTERFACE extern const Natural Natural_nill;
JMSF_SHARED_INTERFACE extern const Natural Natural_one;

JMSF_SHARED_INTERFACE extern const Natural_small Natural_small_badmax;
JMSF_SHARED_INTERFACE extern const Natural_small Natural_small_nill;
JMSF_SHARED_INTERFACE extern const Natural_small Natural_small_one;

JMSF_SHARED_INTERFACE extern const Long_natural Long_natural_badmax;
JMSF_SHARED_INTERFACE extern const Long_natural Long_natural_nill;
JMSF_SHARED_INTERFACE extern const Long_natural Long_natural_one;

JMSF_SHARED_INTERFACE extern const Long_natural_small Long_natural_small_badmax;
JMSF_SHARED_INTERFACE extern const Long_natural_small Long_natural_small_nill;
JMSF_SHARED_INTERFACE extern const Long_natural_small Long_natural_small_one;


} // namespace typeing
} // namespace jmsf
