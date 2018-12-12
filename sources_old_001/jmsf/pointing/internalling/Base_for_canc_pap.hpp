#pragma once

#include "Base_for_canc_pap.hxx"


#include "Reference_counters.hxx"
#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typeing/Naturals.hpp"
#include "jmsf/typeing/Boolean.hxx"


namespace jmsf {
namespace pointing {
namespace internalling {


template< class A_type >
class Base_for_canc_pap {

public:
	typename A_type::the_type &operator *();
	const typename A_type::the_type &operator *() const;
	typename A_type::the_type *operator ->();
	const typename A_type::the_type *operator ->() const;

	typeing::Boolean is_empty() const;
	typeing::Boolean is_not_empty() const;

	typeing::Boolean is_expired() const;
	typeing::Boolean is_not_expired() const;

	typeing::Boolean operator ==( const Base_for_canc_pap &another ) const;
	typeing::Boolean operator !=( const Base_for_canc_pap &another ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	template< class A_return_type >
	A_return_type get_as_weak() noexcept;

	template< class A_return_type >
	A_return_type get_as_weak() const noexcept;

	template< class A_return_type >
	A_return_type get_as_shared() noexcept;

	template< class A_return_type >
	A_return_type get_as_shared() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	memorying::Omp< typename A_type::the_type > release();
	const memorying::Omp< typename A_type::the_type > release() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	memorying::Omp< typename A_type::the_type > &get();
	const memorying::Omp< typename A_type::the_type > &get() const;
	void empty();
	void empty() const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~Base_for_canc_pap() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_canc_pap() noexcept;
	Base_for_canc_pap( const memorying::Omp< typename A_type::the_type > &object_memory_pointer ) noexcept;
	Base_for_canc_pap( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &object_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_canc_pap( const Base_for_canc_pap &another ) noexcept;
	const Base_for_canc_pap &operator =( const Base_for_canc_pap &another ) noexcept;

protected:
	Base_for_canc_pap( Base_for_canc_pap &&another ) noexcept;
	Base_for_canc_pap &operator =( Base_for_canc_pap &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
protected:
	void validate() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	memorying::Omp< typename A_type::the_type > _object_memory_pointer;
	mutable memorying::Omp< Reference_counters > _reference_counters;
	typeing::Shortest_natural _type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const typeing::Shortest_natural type_Empty;
	static const typeing::Shortest_natural type_Nonlinked;
	static const typeing::Shortest_natural type_Weak;
	static const typeing::Shortest_natural type_Shared;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const typeing::internals::platform_character *const BASE_FOR_CANC_PAP_WRONG_TYPE;
	static const typeing::internals::platform_character *const BASE_FOR_CANC_PAP_INITIALIZATION_ORDER_IS_VIOLATED;

};


} // namespace internalling
} // namespace pointing
} // namespace jmsf
