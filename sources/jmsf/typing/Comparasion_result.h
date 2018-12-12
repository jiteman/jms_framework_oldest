#pragma once

#include "Integers.hpp"
#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


class Comparasion_result {

public:
	Boolean is_lower() const noexept;
	Boolean is_equal() const noexept;
	Boolean is_greater() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_not_lower() const noexept; // equal or greater
	Boolean is_not_equal() const noexept; // lower or greater
	Boolean is_not_greater() const noexept; // equal or lower

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean operator ==( const Comparasion_result &another ) const noexept;
	Boolean operator !=( const Comparasion_result &another ) const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Comparasion_result() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparasion_result() noexept;

	template< class A_type >
	static Comparasion_result create( const A_type &first, const A_type &second ) noexept;

	static Comparasion_result create_lower() noexept;
	static Comparasion_result create_equal() noexept;
	static Comparasion_result create_greater() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Comparasion_result( Integer a_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Comparasion_result( const Comparasion_result &another ) noexept;
	const Comparasion_result &operator =( const Comparasion_result &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Integer _the_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


// static
template< class A_type >
Comparasion_result Comparasion_result::create( const A_type &first, const A_type &second ) noexept {
	if ( first < second ) return create_lower();
	
	if ( first > second ) return create_greater();

	return create_equal();
}


} // namespace typing
} // namespace jmsf
