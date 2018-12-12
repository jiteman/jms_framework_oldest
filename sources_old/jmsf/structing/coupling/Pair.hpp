#pragma once


#include "Pair.hxx"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type >
class Pair {

public:
	const A_first_type &getFirst() const throw();
	const A_second_type &getSecond() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_first_type &takeFirst() throw();
	A_second_type &takeSecond() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pair() throw();
	Pair( const A_first_type &first, const A_second_type &second ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pair( const Pair &other ) throw();
	const Pair &operator =( const Pair &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _first;
	A_second_type _second;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace coupling
} // namespace sructing
} // namespace jmsf
