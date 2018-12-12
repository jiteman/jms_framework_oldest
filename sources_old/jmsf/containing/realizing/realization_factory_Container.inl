#pragma once


#include "realization_factory_Container.hpp"

#include "../factory_Container.inl"

#include "realization_ContainerArray.inl"
#include "realization_ContainerDeque.inl"
#include "realization_ContainerList.inl"

#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_factory_Container< A_type >::createArray() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerArray< A_type > );
}

template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_factory_Container< A_type >::createDeque() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerDeque< A_type > );
}

template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_factory_Container< A_type >::createList() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerList< A_type > );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_factory_Container< A_type >::~realization_factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_Container< A_type >::realization_factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_Container< A_type >::realization_factory_Container( const realization_factory_Container< A_type > & ) throw() // other
{}

template< class A_type >
const realization_factory_Container< A_type > &realization_factory_Container< A_type >::operator =( const realization_factory_Container< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf

