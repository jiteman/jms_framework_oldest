#pragma once


#include "Triple.hpp"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type, class A_third_type >
const A_first_type &Triple< A_first_type, A_second_type, A_third_type >::getFirst() const throw() {
	return _first;
}

template< class A_first_type, class A_second_type, class A_third_type >
const A_second_type &Triple< A_first_type, A_second_type, A_third_type >::getSecond() const throw() {
	return _second;
}

template< class A_first_type, class A_second_type, class A_third_type >
const A_third_type &Triple< A_first_type, A_second_type, A_third_type >::getThird() const throw() {
	return _third;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type >
A_first_type &Triple< A_first_type, A_second_type, A_third_type >::takeFirst() throw() {
	return _first;
}

template< class A_first_type, class A_second_type, class A_third_type >
A_second_type &Triple< A_first_type, A_second_type, A_third_type >::takeSecond() throw() {
	return _second;
}

template< class A_first_type, class A_second_type, class A_third_type >
A_third_type &Triple< A_first_type, A_second_type, A_third_type >::takeThird() throw() {
	return _third;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type, class A_third_type >
Triple< A_first_type, A_second_type, A_third_type >::~Triple() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type >
Triple< A_first_type, A_second_type, A_third_type >::Triple() throw()
{}

template< class A_first_type, class A_second_type, class A_third_type >
Triple< A_first_type, A_second_type, A_third_type >::Triple( const A_first_type &first, const A_second_type &second, const A_third_type &third ) throw()
	:
		_first( first ),
		_second( second ),
		_third( third )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type >
Triple< A_first_type, A_second_type, A_third_type >::Triple( const Triple< A_first_type, A_second_type, A_third_type > &other ) throw()
	:
		_first( other._first ),
		_second( other._second ),
		_third( other._third )
{}

template< class A_first_type, class A_second_type, class A_third_type >
const Triple< A_first_type, A_second_type, A_third_type > &Triple< A_first_type, A_second_type, A_third_type >::operator =( const Triple< A_first_type, A_second_type, A_third_type > &other ) throw() {
	if ( &other != this ) {
		_first = other._first;
		_second = other._second;
		_third = other._third;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace coupling
} // namespace sructing
} // namespace jmsf
