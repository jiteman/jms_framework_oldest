#pragma once


#include "jmsf/typing/Boolean.hxx"
#include "jmsf/typing/Naturals.hxx"

//#include "jmsf/Automatic.hxx"
//#include "jmsf/osie/Mutex.hxx"

#include "Reference_counters.hxx"


#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace pointing {
namespace internals {


template< class A_type >
class Base_for_both_constant_and_nonconstant {

public:
	typedef A_type containing_type_data;

public:
	typing::Boolean is_empty() const;
	typing::Boolean is_not_empty() const;

	typing::Memory_size get_connectivity() const;

	memorying::Omp< typename A_type::the_type > &get();
	const memorying::Omp< typename A_type::the_type > &get() const;
	memorying::Omp< typename A_type::the_type > release();
	const memorying::Omp< typename A_type::the_type > release() const;
	void empty();
	void empty() const;

protected:
	void set_from( const Base_for_both_constant_and_nonconstant &other );
	void set_from( const Base_for_both_constant_and_nonconstant &other ) const;

protected:
	Base_for_both_constant_and_nonconstant create_shared_from_this( const memorying::Womp< memorying::Allocator > &reference_counters_allocator ) const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typing::Boolean operator ==( const Base_for_both_constant_and_nonconstant &other ) const;
	typing::Boolean operator !=( const Base_for_both_constant_and_nonconstant &other ) const;

	typename A_type::the_type &operator *();
	const typename A_type::the_type &operator *() const;
	typename A_type::the_type *operator ->();
	const typename A_type::the_type *operator ->() const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Base_for_both_constant_and_nonconstant() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_both_constant_and_nonconstant();
	Base_for_both_constant_and_nonconstant( typing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject );
	Base_for_both_constant_and_nonconstant( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &pointerToObject );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_both_constant_and_nonconstant( const Base_for_both_constant_and_nonconstant &other );

public:
	const Base_for_both_constant_and_nonconstant &operator =( const Base_for_both_constant_and_nonconstant &other );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void validate() const;
//	static Automatic< osie::Mutex > &takeStaticMutex() throw();

private:
	memorying::Omp< typename A_type::the_type > _object_memory_pointer;
	memorying::Omp< Reference_counters > _reference_counters;
	typing::Shortest_natural _type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const typing::Shortest_natural type_None;
	static const typing::Shortest_natural type_Empty;
	static const typing::Shortest_natural type_Nonlinked;
	static const typing::Shortest_natural type_Weak;
	static const typing::Shortest_natural type_Unique;
	static const typing::Shortest_natural type_Shared;
	

private:
//	static Automatic< osie::Mutex > static_baseForBothConstantAndNonconstant_Mutex;

private:
	static const typing::internals::platform_character_type *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE;
	static const typing::internals::platform_character_type *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED;

};


} // namespace internals
} // namespace pointing
} // namespace jmsf
