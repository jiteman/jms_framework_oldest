#pragma once


#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/typeing/Naturals.hxx"

//#include "jmsf/Automatic.hxx"
//#include "jmsf/osie/Mutex.hxx"

#include "Reference_counters.hxx"


#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"
#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace temping {
namespace internals {


template< class A_type >
class Base_for_both_constant_and_nonconstant {

public:
	typedef A_type containing_type_data;

public:
	typeing::Boolean is_empty() const;
	typeing::Boolean is_not_empty() const;

	typeing::Memory_natural get_connectivity() const;

	memorying::Omp< typename A_type::the_type > &get();
	const memorying::Omp< typename A_type::the_type > &get() const;
	memorying::Omp< typename A_type::the_type > release();
	const memorying::Omp< typename A_type::the_type > release() const;
	void empty();
	void empty() const;

protected:
	void set_from( const Base_for_both_constant_and_nonconstant &another );
	void set_from( const Base_for_both_constant_and_nonconstant &another ) const;

protected:
	Base_for_both_constant_and_nonconstant create_shared_from_this( const memorying::Womp< memorying::Allocator > &reference_counters_allocator ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean operator ==( const Base_for_both_constant_and_nonconstant &another ) const;
	typeing::Boolean operator !=( const Base_for_both_constant_and_nonconstant &another ) const;

	typename A_type::the_type &operator *();
	const typename A_type::the_type &operator *() const;
	typename A_type::the_type *operator ->();
	const typename A_type::the_type *operator ->() const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Base_for_both_constant_and_nonconstant() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_both_constant_and_nonconstant();
	Base_for_both_constant_and_nonconstant( typeing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject );
	Base_for_both_constant_and_nonconstant( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &pointerToObject );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_both_constant_and_nonconstant( const Base_for_both_constant_and_nonconstant &another );

public:
	const Base_for_both_constant_and_nonconstant &operator =( const Base_for_both_constant_and_nonconstant &another );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
protected:
	void validate() const;
//	static Automatic< osie::Mutex > &takeStaticMutex() noexcept;

private:
	memorying::Omp< typename A_type::the_type > _object_memory_pointer;
	mutable memorying::Omp< Reference_counters > _reference_counters;
	typeing::Shortest_natural _type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const typeing::Shortest_natural type_None;
	static const typeing::Shortest_natural type_Empty;
	static const typeing::Shortest_natural type_Nonlinked;
	static const typeing::Shortest_natural type_Weak;
	static const typeing::Shortest_natural type_Unique;
	static const typeing::Shortest_natural type_Shared;


private:
//	static Automatic< osie::Mutex > static_baseForBothConstantAndNonconstant_Mutex;

private:
	static const typeing::internals::platform_character *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE;
	static const typeing::internals::platform_character *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED;

};


} // namespace internals
} // namespace temping
} // namespace jmsf
