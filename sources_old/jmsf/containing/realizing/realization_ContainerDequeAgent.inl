#pragma once


#include "realization_ContainerDequeAgent.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxies.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerDequeAgent< A_type >::~realization_ContainerDequeAgent() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerDequeAgent< A_type >::realization_ContainerDequeAgent() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< ContainerAgent< A_type > > realization_ContainerDequeAgent< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< ContainerAgent< A_type > >::createUnique( new realization_ContainerDequeAgent< A_type >( *this ) );
}

template< class A_type >
realization_ContainerDequeAgent< A_type >::realization_ContainerDequeAgent( const realization_ContainerDequeAgent< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerDequeAgent< A_type > &realization_ContainerDequeAgent< A_type >::operator =( const realization_ContainerDequeAgent< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
