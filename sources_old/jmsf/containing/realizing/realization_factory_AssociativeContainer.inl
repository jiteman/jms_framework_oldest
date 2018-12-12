#pragma once


#include "realization_factory_AssociativeContainer.hpp"

#include "../factory_AssociativeContainer.inl"

// #include "realization_ContainerArray.inl"
// #include "realization_ContainerDeque.inl"
// #include "realization_ContainerList.inl"
#include "../AssociativeContainer.inl"

#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_key, class A_type >
::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > realization_factory_AssociativeContainer< A_key, A_type >::createSet() const throw() {
}

template< class A_key, class A_type >
::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > realization_factory_AssociativeContainer< A_key, A_type >::createMultiSet() const throw() {
}

template< class A_key, class A_type >
::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > realization_factory_AssociativeContainer< A_key, A_type >::createMap() const throw() {
}

template< class A_key, class A_type >
::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > realization_factory_AssociativeContainer< A_key, A_type >::createMultiMap() const throw() {
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_key, class A_type >
realization_factory_AssociativeContainer< A_key, A_type >::~realization_factory_AssociativeContainer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_key, class A_type >
realization_factory_AssociativeContainer< A_key, A_type >::realization_factory_AssociativeContainer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_key, class A_type >
realization_factory_AssociativeContainer< A_key, A_type >::realization_factory_AssociativeContainer( const realization_factory_AssociativeContainer< A_key, A_type > & ) throw() // other
{}

template< class A_key, class A_type >
const realization_factory_AssociativeContainer< A_key, A_type > &realization_factory_AssociativeContainer< A_key, A_type >::operator =( const realization_factory_AssociativeContainer< A_key, A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf

