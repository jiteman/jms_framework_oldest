#pragma once


#include "factory_AssociativeContainer.hpp"

#include "realizing/realization_factory_AssociativeContainer.inl"

#include "jmsf/patterning/Singleton.inl"


namespace jmsf {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_key, class A_type >
factory_AssociativeContainer< A_key, A_type >::~factory_AssociativeContainer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_key, class A_type >
factory_AssociativeContainer< A_key, A_type > *factory_AssociativeContainer< A_key, A_type >::createInstance() throw() {
	return new realizing::realization_factory_AssociativeContainer< A_key, A_type >;
}

template< class A_key, class A_type >
factory_AssociativeContainer< A_key, A_type >::factory_AssociativeContainer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_key, class A_type >
factory_AssociativeContainer< A_key, A_type >::factory_AssociativeContainer( const factory_AssociativeContainer< A_key, A_type > & ) throw() // other
{}

template< class A_key, class A_type >
const factory_AssociativeContainer< A_key, A_type > &factory_AssociativeContainer< A_key, A_type >::operator =( const factory_AssociativeContainer< A_key, A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace containing
} // namespace jmsf

