#pragma once


#include "realization_ContainerArrayAgent.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxies.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerArrayAgent< A_type >::~realization_ContainerArrayAgent() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerArrayAgent< A_type >::realization_ContainerArrayAgent() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< ContainerAgent< A_type > > realization_ContainerArrayAgent< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< ContainerAgent< A_type > >::createUnique( new realization_ContainerArrayAgent< A_type >( *this ) );
}

template< class A_type >
realization_ContainerArrayAgent< A_type >::realization_ContainerArrayAgent( const realization_ContainerArrayAgent< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerArrayAgent< A_type > &realization_ContainerArrayAgent< A_type >::operator =( const realization_ContainerArrayAgent< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
