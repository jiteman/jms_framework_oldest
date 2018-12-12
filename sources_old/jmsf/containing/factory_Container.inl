#pragma once


#include "factory_Container.hpp"

#include "realizing/realization_factory_Container.inl"

#include "jmsf/patterning/Singleton.inl"


namespace jmsf {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
factory_Container< A_type >::~factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
factory_Container< A_type > *factory_Container< A_type >::createInstance() throw() {
	return new realizing::realization_factory_Container< A_type >;
}

template< class A_type >
factory_Container< A_type >::factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
factory_Container< A_type >::factory_Container( const factory_Container< A_type > & ) throw() // other
{}

template< class A_type >
const factory_Container< A_type > &factory_Container< A_type >::operator =( const factory_Container< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace containing
} // namespace jmsf

