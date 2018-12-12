#pragma once


#include "Quad.hpp"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
const A_first_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::getFirst() const throw() {
	return _first;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
const A_second_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::getSecond() const throw() {
	return _second;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
const A_third_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::getThird() const throw() {
	return _third;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
const A_fourth_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::getFourth() const throw() {
	return _fourth;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
A_first_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::takeFirst() throw() {
	return _first;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
A_second_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::takeSecond() throw() {
	return _second;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
A_third_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::takeThird() throw() {
	return _third;
}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
A_fourth_type &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::takeFourth() throw() {
	return _fourth;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::~Quad() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::Quad() throw()
{}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::Quad( const A_first_type &first, const A_second_type &second, const A_third_type &third, const A_fourth_type &fourth ) throw()
	:
		_first( first ),
		_second( second ),
		_third( third ),
		_fourth( fourth )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::Quad( const Quad< A_first_type, A_second_type, A_third_type, A_fourth_type > &other ) throw()
	:
		_first( other._first ),
		_second( other._second ),
		_third( other._third ),
		_fourth( other._fourth )
{}

template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
const Quad< A_first_type, A_second_type, A_third_type, A_fourth_type > &Quad< A_first_type, A_second_type, A_third_type, A_fourth_type >::operator =( const Quad< A_first_type, A_second_type, A_third_type, A_fourth_type > &other ) throw() {
	if ( &other != this ) {
		_first = other._first;
		_second = other._second;
		_third = other._third;
		_fourth = other._fourth;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace coupling
} // namespace sructing
} // namespace jmsf
