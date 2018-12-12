#pragma once


#include "DequeTraverser.hpp"


namespace jmsf {
namespace sructing {
namespace traversing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
DequeTraverser< A_type >::~DequeTraverser() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
DequeTraverser< A_type >::DequeTraverser() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
DequeTraverser< A_type >::DequeTraverser( const DequeTraverser< A_type > & ) throw() { // other
}

template< class A_type >
const DequeTraverser< A_type > &DequeTraverser< A_type >::operator =( const DequeTraverser< A_type > &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace traversing
} // namespace sructing
} // namespace jmsf
