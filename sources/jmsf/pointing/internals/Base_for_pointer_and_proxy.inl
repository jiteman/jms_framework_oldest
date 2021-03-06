#pragma once


#include "Base_for_pointer_and_proxy.hpp"

#include "Base_for_both_constant_and_nonconstant.inl"


namespace jmsf {
namespace pointing {
namespace internals {


// template< class A_type, template< class > class A__deleter >
// A_type *Base_for_pointer_and_proxy< A_type, A__deleter >::get() throw( validating::Exception ) {
// 	return getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// const A_type *Base_for_pointer_and_proxy< A_type, A__deleter >::get() const throw( validating::Exception ) {
// 	return const_cast< Base_for_pointer_and_proxy< A_type, A__deleter > * >( this )->getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// A_type *Base_for_pointer_and_proxy< A_type, A__deleter >::release() throw( validating::Exception ) {
// 	return releaseFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// void Base_for_pointer_and_proxy< A_type, A__deleter >::empty() throw( validating::Exception ) {
// 	emptyFromBase();
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// Base_for_pointer_and_proxy< A_type, A__deleter >::Base_for_pointer_and_proxy() throw()
// 	: Base_for_both_constant_and_nonconstant()
// {}

template< class A_type >
Base_for_pointer_and_proxy< A_type >::Base_for_pointer_and_proxy( const typing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		Base_for_both_constant_and_nonconstant( type, pointerToObject )
{}

template< class A_type >
Base_for_pointer_and_proxy< A_type >::Base_for_pointer_and_proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		Base_for_both_constant_and_nonconstant( reference_counters_allocator, pointerToObject )
{}



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// Base_for_pointer_and_proxy< A_type, A__deleter >::Base_for_pointer_and_proxy( const Base_for_pointer_and_proxy< A_type, A__deleter > &other ) throw( validating::Exception )
// 	: Base_for_both_constant_and_nonconstant( other )
// {}
// 
// template< class A_type, template< class > class A__deleter >
// Base_for_pointer_and_proxy< A_type, A__deleter > &Base_for_pointer_and_proxy< A_type, A__deleter >::operator =( const Base_for_pointer_and_proxy< A_type, A__deleter > &other ) throw( validating::Exception ) {
// 	if ( this == &other ) return *this;
// 
// 	Base_for_both_constant_and_nonconstant::operator =( other );
// 	return *this;
// }

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace internals
} // namespace pointing
} // namespace jmsf
