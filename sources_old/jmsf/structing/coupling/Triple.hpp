#pragma once


#include "Triple.hxx"


namespace jmsf {
namespace sructing {
namespace coupling {


template< class A_first_type, class A_second_type, class A_third_type >
class Triple {

public:
	const A_first_type &getFirst() const throw();
	const A_second_type &getSecond() const throw();
	const A_third_type &getThird() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_first_type &takeFirst() throw();
	A_second_type &takeSecond() throw();
	A_third_type &takeThird() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Triple() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Triple() throw();
	Triple( const A_first_type &first, const A_second_type &second, const A_third_type &third ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Triple( const Triple &other ) throw();
	const Triple &operator =( const Triple &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _first;
	A_second_type _second;
	A_third_type _third;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace coupling
} // namespace sructing
} // namespace jmsf
