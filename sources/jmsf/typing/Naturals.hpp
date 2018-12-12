#pragma once


#include "Naturals.hxx"

#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"


#include "jmsf/jmsf.h"

namespace jmsf {
namespace typing {


template< class A_type >
class Naturals {

public: // math
	Naturals operator +( const Naturals &another ) const noexept;
	Naturals &operator +=( const Naturals &another ) noexept;

	Naturals operator -( const Naturals &another ) const noexept;
	Naturals operator -=( const Naturals &another ) noexept;

//	Naturals operator -() const noexept;

	Naturals operator *( const Naturals &another ) const noexept;
	Naturals &operator *=( const Naturals &another ) noexept;

	Naturals operator /( const Naturals &another ) const ;
	Naturals &operator /=( const Naturals &another ) ;

	Naturals operator %( const Naturals &another ) const ;
	Naturals &operator %=( const Naturals &another ) ;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
	Naturals operator ^( const Naturals &another ) const noexept;
	Naturals &operator ^=( const Naturals &another ) noexept;

	Naturals operator &( const Naturals &another ) const noexept;
	Naturals &operator &=( const Naturals &another ) noexept;

	Naturals operator |( const Naturals &another ) const noexept;
	Naturals &operator |=( const Naturals &another ) noexept;

	Naturals operator ~() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Naturals operator !() const noexept;
// 	Naturals operator &&( const Naturals &another ) const noexept;
// 	Naturals operator ||( const Naturals &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Naturals &another ) const noexept;
	Boolean operator !=( const Naturals &another ) const noexept;
	Boolean operator <( const Naturals &another ) const noexept;
	Boolean operator <=( const Naturals &another ) const noexept;
	Boolean operator >( const Naturals &another ) const noexept;
	Boolean operator >=( const Naturals &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
	Naturals get_shifted_left() const noexept;
	Naturals &shift_left() noexept;
	Naturals operator <<( Memory_size shift_value ) const noexept;
	Naturals &operator <<=( Memory_size shift_value ) noexept;

	Naturals get_shifted_right() const noexept;
	Naturals &shift_right() noexept;
	Naturals operator >>( Memory_size shift_value ) const noexept;
	Naturals &operator >>=( Memory_size shift_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
	Naturals &operator ++() noexept;
	Naturals operator ++( int ) noexept;
	Naturals &operator --() noexept;
	Naturals operator --( int ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) ;
//	void *operator new[]( Unsigned quantityToAllocate ) ;
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_nill() const noexept;
	Boolean is_not_nill() const noexept;
	Boolean is_max() const noexept;
	Boolean is_not_max() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_unsigned_char() const noexept;
	A_type get_value() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Naturals() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Naturals() noexept;

public:
	static Naturals create( A_type natural_value = A_type( 0 ) ) noexept;

private:
	Naturals( A_type natural_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Naturals( const Naturals &another ) noexept;
	const Naturals &operator =( const Naturals &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _natural_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


JMSF_DLL_INTERFACE extern const Shortest_natural Shortest_natural_badmax;
JMSF_DLL_INTERFACE extern const Shortest_natural Shortest_natural_nill;
JMSF_DLL_INTERFACE extern const Shortest_natural Shortest_natural_one;

JMSF_DLL_INTERFACE extern const Short_natural Short_natural_badmax;
JMSF_DLL_INTERFACE extern const Short_natural Short_natural_nill;
JMSF_DLL_INTERFACE extern const Short_natural Short_natural_one;

JMSF_DLL_INTERFACE extern const Natural Natural_badmax;
JMSF_DLL_INTERFACE extern const Natural Natural_nill;
JMSF_DLL_INTERFACE extern const Natural Natural_one;

JMSF_DLL_INTERFACE extern const Long_natural Long_natural_badmax;
JMSF_DLL_INTERFACE extern const Long_natural Long_natural_nill;
JMSF_DLL_INTERFACE extern const Long_natural Long_natural_one;

JMSF_DLL_INTERFACE extern const Memory_size Memory_size_badmax;
JMSF_DLL_INTERFACE extern const Memory_size Memory_size_nill;
JMSF_DLL_INTERFACE extern const Memory_size Memory_size_one;

JMSF_DLL_INTERFACE extern const File_size File_size_badmax;
JMSF_DLL_INTERFACE extern const File_size File_size_nill;
JMSF_DLL_INTERFACE extern const File_size File_size_one;


} // namespace typing
} // namespace jmsf