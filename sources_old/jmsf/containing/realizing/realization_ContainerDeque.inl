#pragma once


#include "realization_ContainerDeque.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerDeque< A_type >::~realization_ContainerDeque() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerDeque< A_type >::realization_ContainerDeque() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_ContainerDeque< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerDeque< A_type >( *this ) );
}

template< class A_type >
realization_ContainerDeque< A_type >::realization_ContainerDeque( const realization_ContainerDeque< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerDeque< A_type > &realization_ContainerDeque< A_type >::operator =( const realization_ContainerDeque< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
