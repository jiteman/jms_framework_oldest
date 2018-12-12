#pragma once


#include "realization_ConstantIterator.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxies.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ConstantIterator< A_type >::~realization_ConstantIterator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ConstantIterator< A_type >::realization_ConstantIterator() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< ConstantIterator< A_type > > realization_ConstantIterator< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< ConstantIterator< A_type > >::createUnique( new realization_ConstantIterator< A_type >( *this ) );
}

template< class A_type >
realization_ConstantIterator< A_type >::realization_ConstantIterator( const realization_ConstantIterator< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ConstantIterator< A_type > &realization_ConstantIterator< A_type >::operator =( const realization_ConstantIterator< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
