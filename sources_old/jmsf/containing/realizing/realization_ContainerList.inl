#pragma once


#include "realization_ContainerList.hpp"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace containing {
namespace realizing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// common getters
// virtual Container
template< class A_type >
typing::Boolean realization_ContainerList< A_type >::isEmpty() const throw() {
	
}

// virtual Container
template< class A_type >
typing::Boolean realization_ContainerList< A_type >::isNotEmpty() const throw() {
	
}

// virtual Container
template< class A_type >
typing::Natural realization_ContainerList< A_type >::getQuantityOfElements() const throw() {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
// virtual Container
template< class A_type >
void realization_ContainerList< A_type >::appendToBegin( const A_type &object ) throw() {
	
}

// virtual Container
template< class A_type >
void realization_ContainerList< A_type >::appendToEnd( const A_type &object ) throw() {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// factories
// virtual Container
template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerList< A_type >::createIteratorAtBegin() throw() {
	
}

// virtual Container
template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerList< A_type >::createIteratorAtEnd() throw() {
	
}

// virtual Container
template< class A_type >
pointing::Proxy< Iterator< A_type > > realization_ContainerList< A_type >::createIteratorAt( const typing::Natural index ) throw( validating::Exception ) {
	
}

// virtual Container
template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerList< A_type >::createConstantIteratorAtBegin() throw() {
	
}

// virtual Container
template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerList< A_type >::createConstantIteratorAtEnd() throw() {
	
}

// virtual Container
template< class A_type >
pointing::Proxy< ConstantIterator< A_type > > realization_ContainerList< A_type >::createConstantIteratorAt( const typing::Natural index ) throw( validating::Exception ) {
	
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerList< A_type >::~realization_ContainerList() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerList< A_type >::realization_ContainerList() throw( jmsf::validating::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::pointing::Proxy< Container< A_type > > realization_ContainerList< A_type >::createClone() const throw() {
	return ::jmsf::pointing::Proxy< Container< A_type > >::createUnique( new realization_ContainerList< A_type >( *this ) );
}

template< class A_type >
realization_ContainerList< A_type >::realization_ContainerList( const realization_ContainerList< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerList< A_type > &realization_ContainerList< A_type >::operator =( const realization_ContainerList< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace containing
} // namespace jmsf
