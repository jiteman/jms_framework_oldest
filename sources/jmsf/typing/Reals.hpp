#pragma once


#include "Reals.hxx"


#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace typing {


template< class A_type >
class Reals {

public:
	Reals get_absolute() const noexept;
	Boolean is_about_zero() const noexept;

public: // math
	Reals operator +( const Reals &another ) const noexept;
	Reals &operator +=( const Reals &another ) noexept;

	Reals operator -( const Reals &another ) const noexept;
	Reals operator -=( const Reals &another ) noexept;

	Reals operator -() const noexept;

	Reals operator *( const Reals &another ) const noexept;
	Reals &operator *=( const Reals &another ) noexept;

	Reals operator /( const Reals &another ) const;
	Reals &operator /=( const Reals &another );

 	Reals operator %( const Reals &another ) const;
 	Reals &operator %=( const Reals &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
// 	Real operator ^( const Real &another ) const noexept;
// 	Real &operator ^=( const Real &another ) noexept;
// 
// 	Real operator &( const Real &another ) const noexept;
// 	Real &operator &=( const Real &another ) noexept;
// 
// 	Real operator |( const Real &another ) const noexept;
// 	Real &operator |=( const Real &another ) noexept;
//
//	Real operator ~() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Real operator !() const noexept;
// 	Real operator &&( const Real &another ) const noexept;
// 	Real operator ||( const Real &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Reals &another ) const noexept;
	Boolean operator !=( const Reals &another ) const noexept;
	Boolean operator <( const Reals &another ) const noexept;
	Boolean operator <=( const Reals &another ) const noexept;
	Boolean operator >( const Reals &another ) const noexept;
	Boolean operator >=( const Reals &another ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
// 	Real operator <<( const ShortestNatural &another ) const noexept;
// 	Real &operator <<=( const ShortestNatural &another ) noexept;
// 
// 	Real operator >>( const ShortestNatural &another ) const noexept;
// 	Real &operator >>=( const ShortestNatural &another ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
// 	Real &operator ++() noexept;
// 	Real operator ++( int ) noexept;
// 	Real &operator --() noexept;
// 	Real operator --( int ) noexept;

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type get_value() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Reals() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reals() noexept;

public:
	static Reals create( A_type real_value = A_type( 0 ) ) noexept;

private:
	Reals( A_type real_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reals( const Reals &another ) noexept;
	const Reals &operator =( const Reals &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _real_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static A_type math_compute_absolute( A_type real_value ) noexept;
	static Boolean math_is_about_zero( A_type real_value ) noexept;
	static Boolean math_are_almost_equal( A_type real_value, A_type secondReal ) noexept;

};



template<>
JMSF_DLL_INTERFACE Boolean Reals< internals::platform_short_real >::math_is_about_zero( const internals::platform_short_real real_value ) noexept;

template<>
JMSF_DLL_INTERFACE Boolean Reals< internals::platform_real >::math_is_about_zero( const internals::platform_real real_value ) noexept;

} // namespace typing
} // namespace jmsf
