#pragma once


#include "Reals.hxx"


#include "Boolean.hxx"

#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"
#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace typeing {


template< class A_type >
class Reals {

public:
	Reals get_absolute() const noexcept;
	Boolean is_about_zero() const noexcept;

public: // math
	Reals operator +( const Reals &another ) const noexcept;
	Reals &operator +=( const Reals &another ) noexcept;

	Reals operator -( const Reals &another ) const noexcept;
	Reals operator -=( const Reals &another ) noexcept;

	Reals operator -() const noexcept;

	Reals operator *( const Reals &another ) const noexcept;
	Reals &operator *=( const Reals &another ) noexcept;

	Reals operator /( const Reals &another ) const;
	Reals &operator /=( const Reals &another );

	Reals operator %( const Reals &another ) const;
	Reals &operator %=( const Reals &another );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
// 	Real operator ^( const Real &another ) const noexcept;
// 	Real &operator ^=( const Real &another ) noexcept;
//
// 	Real operator &( const Real &another ) const noexcept;
// 	Real &operator &=( const Real &another ) noexcept;
//
// 	Real operator |( const Real &another ) const noexcept;
// 	Real &operator |=( const Real &another ) noexcept;
//
//	Real operator ~() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Real operator !() const noexcept;
// 	Real operator &&( const Real &another ) const noexcept;
// 	Real operator ||( const Real &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Reals &another ) const noexcept;
	Boolean operator !=( const Reals &another ) const noexcept;
	Boolean operator <( const Reals &another ) const noexcept;
	Boolean operator <=( const Reals &another ) const noexcept;
	Boolean operator >( const Reals &another ) const noexcept;
	Boolean operator >=( const Reals &another ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
// 	Real operator <<( const ShortestNatural &another ) const noexcept;
// 	Real &operator <<=( const ShortestNatural &another ) noexcept;
//
// 	Real operator >>( const ShortestNatural &another ) const noexcept;
// 	Real &operator >>=( const ShortestNatural &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
// 	Real &operator ++() noexcept;
// 	Real operator ++( int ) noexcept;
// 	Real &operator --() noexcept;
// 	Real operator --( int ) noexcept;

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type get_native_value() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Reals() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reals() noexcept;

public:
	static Reals create( A_type real_value = A_type( 0 ) ) noexcept;

private:
	Reals( A_type real_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Reals( const Reals &another ) noexcept;
	const Reals &operator =( const Reals &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _real_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static A_type math_compute_absolute( A_type real_value ) noexcept;
	static Boolean math_is_about_zero( A_type real_value ) noexcept;
	static Boolean math_are_almost_equal( A_type real_value, A_type secondReal ) noexcept;

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


template<>
JMSF_SHARED_INTERFACE Boolean Reals< internals::platform_short_real >::math_is_about_zero( const internals::platform_short_real real_value ) noexcept;

template<>
JMSF_SHARED_INTERFACE Boolean Reals< internals::platform_real >::math_is_about_zero( const internals::platform_real real_value ) noexcept;


} // namespace typeing
} // namespace jmsf
