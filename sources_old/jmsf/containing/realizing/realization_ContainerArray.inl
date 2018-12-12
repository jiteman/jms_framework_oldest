#pragma once


#include "realization_ContainerArray.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// common getters
template< class A_type >
typing::Boolean realization_ContainerArray< A_type >::isEmpty() const throw() {
	
}

template< class A_type >
typing::Boolean realization_ContainerArray< A_type >::isNotEmpty() const throw() {
	
}

template< class A_type >
typing::Natural realization_ContainerArray< A_type >::getQuantityOfElements() const throw() {
	
}
//~common getters

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
template< class A_type >
void realization_ContainerArray< A_type >::appendToBegin( const A_type &object ) throw() {
	
}

template< class A_type >
void realization_ContainerArray< A_type >::appendToEnd( const A_type &object ) throw() {
	
}
//~appending modifiers

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// factories
template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::createIteratorAtBegin() throw() {
	
}

template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::createIteratorAtEnd() throw() {
	
}

template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::createIteratorAt( const typing::Natural index ) throw( validating::Exception ) {
	
}

template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerArray< A_type >::createConstantIteratorAtBegin() throw() {
	
}

template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerArray< A_type >::createConstantIteratorAtEnd() throw() {
	
}

template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerArray< A_type >::createConstantIteratorAt( const typing::Natural index ) throw( validating::Exception ) {
	
}
//~factories

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerArray< A_type >::~realization_ContainerArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerArray< A_type >::realization_ContainerArray() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_ContainerArray< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerArray< A_type >( *this ) );
}

template< class A_type >
realization_ContainerArray< A_type >::realization_ContainerArray( const realization_ContainerArray< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerArray< A_type > &realization_ContainerArray< A_type >::operator =( const realization_ContainerArray< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
