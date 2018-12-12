#pragma once


#include "realization_Iterator.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxies.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< A_type >
realization_Iterator< A_type >::~realization_Iterator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
realization_Iterator< A_type >::realization_Iterator() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
::jmsf::pointing::Proxy< Iterator< A_type > > realization_Iterator< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< Iterator< A_type > >::createUnique( new realization_Iterator< A_type >( *this ) );
}

template< A_type >
realization_Iterator< A_type >::realization_Iterator( const realization_Iterator< A_type > & ) throw() // other
{}

template< A_type >
const realization_Iterator< A_type > &realization_Iterator< A_type >::operator =( const realization_Iterator< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
