#pragma once


#include "Quad.hxx"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type, class A_third_type, class A_fourth_type >
class Quad {

public:
	const A_first_type &getFirst() const throw();
	const A_second_type &getSecond() const throw();
	const A_third_type &getThird() const throw();
	const A_fourth_type &getFourth() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_first_type &takeFirst() throw();
	A_second_type &takeSecond() throw();
	A_third_type &takeThird() throw();
	A_fourth_type &takeFourth() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Quad() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Quad() throw();
	Quad( const A_first_type &first, const A_second_type &second, const A_third_type &third, const A_fourth_type &fourth ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Quad( const Quad &other ) throw();
	const Quad &operator =( const Quad &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _first;
	A_second_type _second;
	A_third_type _third;
	A_fourth_type _fourth;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace coupling
} // namespace sructing
} // namespace jmsf
