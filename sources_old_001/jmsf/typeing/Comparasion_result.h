#pragma once

#include "Integers.hpp"
#include "Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace typeing {


class Comparasion_result {

public:
	Boolean is_lower() const noexcept;
	Boolean is_equal() const noexcept;
	Boolean is_greater() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_not_lower() const noexcept; // equal or greater
	Boolean is_not_equal() const noexcept; // lower or greater
	Boolean is_not_greater() const noexcept; // equal or lower

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean operator ==( const Comparasion_result &another ) const noexcept;
	Boolean operator !=( const Comparasion_result &another ) const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Comparasion_result() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparasion_result() noexcept;

	template< class A_type >
	static Comparasion_result create( const A_type &first, const A_type &second ) noexcept;

	static Comparasion_result create_lower() noexcept;
	static Comparasion_result create_equal() noexcept;
	static Comparasion_result create_greater() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Comparasion_result( Integer a_value ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparasion_result( const Comparasion_result &another ) noexcept;
	const Comparasion_result &operator =( const Comparasion_result &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Integer _the_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


// static
template< class A_type >
Comparasion_result Comparasion_result::create( const A_type &first, const A_type &second ) noexcept {
	if ( first < second ) return create_lower();

	if ( first > second ) return create_greater();

	return create_equal();
}


} // namespace typeing
} // namespace jmsf
