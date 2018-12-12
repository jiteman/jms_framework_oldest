#pragma once


#include "Base_for_constant_pointer_and_constant_proxy.hpp"

#include "Base_for_pointer_and_proxy.inl"

#include "jmsf/validating/File_and_line.h"


namespace jmsf {
namespace pointing {
namespace internals {


// template< class A_type, template< class > class A__deleter >
// const A_type *Base_for_constant_pointer_and_constant_proxy< Indirector_type >::get() const {
// 	return const_cast< Base_for_both_constant_and_nonconstant< Indirector_type > * >( this )->getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// const A_type *Base_for_constant_pointer_and_constant_proxy< Indirector_type >::release() const {
// 	return const_cast< Base_for_both_constant_and_nonconstant< Indirector_type > * >( this )->releaseFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// void Base_for_constant_pointer_and_constant_proxy< Indirector_type >::empty() const {
// 	const_cast< Base_for_both_constant_and_nonconstant< Indirector_type > * >( this )->emptyFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// A_type *Base_for_constant_pointer_and_constant_proxy< Indirector_type >::get() {
// 	Should::neverReachHere();
// 	return A__deleter::getNull();
// }

template< class A_type >
const typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::get() const {
	return Base_for_both_constant_and_nonconstant< A_type >::get();
}

template< class A_type >
const typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::release() const {
	return Base_for_both_constant_and_nonconstant< A_type >::release();
}

template< class A_type >
void Base_for_constant_pointer_and_constant_proxy< A_type >::empty() const {
	Base_for_both_constant_and_nonconstant< A_type >::empty();
}

template< class A_type >
typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::get() {
	validate();
	Should::_never_reach_here( "Base_for_constant_pointer_and_constant_proxy< A_type >::get()", FILE_AND_LINE );
	return nullptr;
}

template< class A_type >
typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::release() {
	validate();
	Should::_never_reach_here( "Base_for_constant_pointer_and_constant_proxy< A_type >::release()", FILE_AND_LINE );
	return nullptr;
}

template< class A_type >
void Base_for_constant_pointer_and_constant_proxy< A_type >::empty() {
	validate();
	Should::_never_reach_here( "Base_for_constant_pointer_and_constant_proxy< A_type >::empty()", FILE_AND_LINE );
}

template< class A_type >
const typename A_type::the_type &Base_for_constant_pointer_and_constant_proxy< A_type >::operator *() const {
	return Base_for_both_constant_and_nonconstant< A_type >::operator *();
}

template< class A_type >
const typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::operator ->() const {
	return Base_for_both_constant_and_nonconstant< A_type >::operator ->();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typename A_type::the_type &Base_for_constant_pointer_and_constant_proxy< A_type >::operator *() {
	validate();
	Should::_never_reach_here( "Base_for_constant_pointer_and_constant_proxy< A_type >::operator *()", FILE_AND_LINE );
	return nullptr;
}

template< class A_type >
typename A_type::the_type *Base_for_constant_pointer_and_constant_proxy< A_type >::operator ->() {
	validate();
	Should::_never_reach_here( "Base_for_constant_pointer_and_constant_proxy< A_type >::operator ->()", FILE_AND_LINE );
	return nullptr;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// Base_for_constant_pointer_and_constant_proxy< Indirector_type >::Base_for_constant_pointer_and_constant_proxy() throw()
// 	: Base_for_both_constant_and_nonconstant()
// {}

template< class A_type >
Base_for_constant_pointer_and_constant_proxy< A_type >::Base_for_constant_pointer_and_constant_proxy( const typing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		Base_for_both_constant_and_nonconstant( type, pointerToObject )
{}

template< class A_type >
Base_for_constant_pointer_and_constant_proxy< A_type >::Base_for_constant_pointer_and_constant_proxy(
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		Base_for_both_constant_and_nonconstant( reference_counters_allocator, pointerToObject )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// Base_for_constant_pointer_and_constant_proxy< Indirector_type >::Base_for_constant_pointer_and_constant_proxy( const Base_for_constant_pointer_and_constant_proxy< Indirector_type > &other ) throw( validating::Exception )
// 	: Base_for_both_constant_and_nonconstant( other )
// {}
// 
// template< class A_type, template< class > class A__deleter >
// const Base_for_constant_pointer_and_constant_proxy< Indirector_type > &Base_for_constant_pointer_and_constant_proxy< Indirector_type >::operator =( const Base_for_constant_pointer_and_constant_proxy< Indirector_type > &other ) {
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
