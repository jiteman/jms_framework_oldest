#pragma once


namespace jmsf {


template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
class Triple {

public:
	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Triple() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Triple() throw();
	Triple( const A_placeholder< A_first_type > &first, const A_placeholder< A_second_type > &second, const A_placehodler< A_third_type > &third ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Triple( const Triple &other ) throw();
	const Triple &operator =( const Triple &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_placeholder< A_first_type > _first;
	A_placeholder< A_second_type > _second;
	A_placeholder< A_third_type > _third;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
Triple< A_placeholder, A_first_type, A_second_type, A_third_type >::~Triple() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
Triple< A_placeholder, A_first_type, A_second_type, A_third_type >::Triple() throw()
	:
		_first( A_placeholder< A_first_type >::createEmpty() ),
		_second( A_placeholder< A_second_type >::createEmpty() ),
		_third( A_placeholder< A_third_type >::createEmpty() )
{}

template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
Triple< A_placeholder, A_first_type, A_second_type, A_third_type >::Triple( const A_placeholder< A_first_type > &first, const A_placeholder< A_second_type > &second, const A_placeholder< A_third_type > &third ) throw()
	:
		_first( first ),
		_second( second ),
		_third( third )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
Triple< A_placeholder, A_first_type, A_second_type, A_third_type >::Triple( const Triple< A_placeholder, A_first_type, A_second_type, A_third_type > &other ) throw()
	:
		_first( other._first ),
		_second( other._second ),
		_third( other._third )
{}

template< template< class > class A_placeholder, class A_first_type, class A_second_type, class A_third_type >
const Triple< A_placeholder, A_first_type, A_second_type, A_third_type > &Triple< A_placeholder, A_first_type, A_second_type, A_third_type >::operator =( const Triple< A_placeholder, A_first_type, A_second_type, A_third_type > &other ) throw() {
	if ( this == &other ) return *this;

	_first = other._first;
	_second = other._second;
	_third = other._third;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
