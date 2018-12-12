#pragma once


#include "ArrayTraverser.hpp"


namespace jmsf {
namespace sructing {
namespace traversing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
ArrayTraverser< A_type >::~ArrayTraverser() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
ArrayTraverser< A_type >::ArrayTraverser() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
ArrayTraverser< A_type >::ArrayTraverser( const ArrayTraverser< A_type > & ) throw() { // other
}

template< class A_type >
const ArrayTraverser< A_type > &ArrayTraverser< A_type >::operator =( const ArrayTraverser< A_type > &other ) throw() {
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
