#pragma once


#include "Base_for_both_constant_and_nonconstant.hpp"

#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace temping {
namespace internals {


template< class A_type >
class Base_for_constant_pointer_and_constant_proxy
	: public Base_for_both_constant_and_nonconstant< A_type >
{

// public:
// 	const A_type *get() const throw( validating::Exception );
// 	const A_type *release() const throw( validating::Exception );
// 	void empty() const throw( validating::Exception );
//
// private:
// 	A_type *get() throw( validating::Exception );

public:
	const typename A_type::the_type *get() const;
	const typename A_type::the_type *release() const;
	void empty() const;

private: // hiding non constant methods
	typename A_type::the_type *get();
	typename A_type::the_type *release();
	void empty();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const typename A_type::the_type &operator *() const;
	const typename A_type::the_type *operator ->() const;

private: // hiding non constant methods again
	typename A_type::the_type &operator *();
	typename A_type::the_type *operator ->();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//protected:
// 	Base_for_constant_pointer_and_constant_proxy() noexcept;

protected:
	Base_for_constant_pointer_and_constant_proxy( typeing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject );
	Base_for_constant_pointer_and_constant_proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &pointerToObject );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
// 	Base_for_constant_pointer_and_constant_proxy( const Base_for_constant_pointer_and_constant_proxy &other ) throw( validating::Exception );
// 	const Base_for_constant_pointer_and_constant_proxy &operator =( const Base_for_constant_pointer_and_constant_proxy &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internals
} // namespace temping
} // namespace jmsf
