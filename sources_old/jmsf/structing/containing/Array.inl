#pragma once


#include "Array.hpp"

#include "../traversing/ArrayTraverser.inl"


namespace jmsf {
namespace sructing {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// common getters
template< class A_type >
typing::Boolean Array< A_type >::isEmpty() const throw() {
	
}

template< class A_type >
typing::Boolean Array< A_type >::isNotEmpty() const throw() {
	
}

template< class A_type >
typing::Natural Array< A_type >::getQuantityOfElements() const throw() {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
template< class A_type >
void Array< A_type >::appendToBegin( const A_type &object ) throw() {
	
}

template< class A_type >
void Array< A_type >::appendToEnd( const A_type &object ) throw() {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// factories
template< class A_type >
pointing::Pointer< traversing::ArrayTraverser< A_type > > Array< A_type >::createTraverserAtBegin() throw() {
	
}

template< class A_type >
pointing::Pointer< traversing::ArrayTraverser< A_type > > Array< A_type >::createIteratorAtEnd() throw() {
	
}

template< class A_type >
pointing::Pointer< traversing::ArrayTraverser< A_type > > Array< A_type >::createIteratorAt( const typing::Natural index ) throw( validating::Exception ) {
	
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Array< A_type >::~Array() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Array< A_type >::Array() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Array< A_type >::Array( const Array< A_type > & ) throw() { // other
}

template< class A_type >
const Array< A_type > &Array< A_type >::operator =( const Array< A_type > &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace sructing
} // namespace jmsf
