#pragma once


#include "Base_for_both_constant_and_nonconstant.hpp"

#include "jmsf/typing/Naturals.hxx"

#include "Base_for_constant_pointer_and_constant_proxy.hxx"


namespace jmsf {
namespace pointing {
namespace internals {


template< class A_type >
class Base_for_pointer_and_proxy :
	public Base_for_both_constant_and_nonconstant< A_type >
{

public:
// 	A_type *get() throw( validating::Exception );
// 	const A_type *get() const throw( validating::Exception );
// 	A_type *release() throw( validating::Exception );
// 	void empty() throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// protected:
// 	Base_for_pointer_and_proxy() throw();

protected:
	Base_for_pointer_and_proxy( const typing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject );
	Base_for_pointer_and_proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &pointerToObject );	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// protected:
// 	Base_for_pointer_and_proxy( const Base_for_pointer_and_proxy &other ) throw( validating::Exception );
// 	Base_for_pointer_and_proxy &operator =( const Base_for_pointer_and_proxy &other ) throw( validating::Exception );


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internals
} // namespace pointing
} // namespace jmsf
