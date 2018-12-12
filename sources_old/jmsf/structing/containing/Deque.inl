#pragma once


#include "Deque.hpp"


namespace jmsf {
namespace sructing {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Deque< A_type >::~Deque() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Deque< A_type >::Deque() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Deque< A_type >::Deque( const Deque< A_type > & ) throw() { // other
}

template< class A_type >
const Deque< A_type > &Deque< A_type >::operator =( const Deque< A_type > &other ) throw() {
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
