#pragma once


#include "Pair.hpp"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type >
const A_first_type &Pair< A_first_type, A_second_type >::getFirst() const throw() {
	return _first;
}

template< class A_first_type, class A_second_type >
const A_second_type &Pair< A_first_type, A_second_type >::getSecond() const throw() {
	return _second;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
A_first_type &Pair< A_first_type, A_second_type >::takeFirst() throw() {
	return _first;
}

template< class A_first_type, class A_second_type >
A_second_type &Pair< A_first_type, A_second_type >::takeSecond() throw() {
	return _second;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type >::~Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type >::Pair() throw()
{}

template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type >::Pair( const A_first_type &first, const A_second_type &second ) throw()
	:
		_first( first ),
		_second( second )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type >::Pair( const Pair< A_first_type, A_second_type > &other ) throw()
	:
		_first( other._first ),
		_second( other._second )
{}

template< class A_first_type, class A_second_type >
const Pair< A_first_type, A_second_type > &Pair< A_first_type, A_second_type >::operator =( const Pair< A_first_type, A_second_type > &other ) throw() {
	if ( &other != this ) {
		_first = other._first;
		_second = other._second;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace coupling
} // namespace sructing
} // namespace jmsf
