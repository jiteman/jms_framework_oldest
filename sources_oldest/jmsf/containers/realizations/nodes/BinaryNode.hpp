#pragma once


namespace jmsf {
namespace containers {
namespace realizations {
namespace nodes {


template< class A_type >
class BinaryNode {

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~BinaryNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	BinaryNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	BinaryNode( const BinaryNode &other ) throw();
	const BinaryNode &operator =( const BinaryNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace nodes
} // namespace realizations
} // namespace containers
} // namespace jmsf


namespace jmsf {
namespace containers {
namespace realizations {
namespace nodes {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
BinaryNode< A_type >::~BinaryNode() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
BinaryNode< A_type >::BinaryNode() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
BinaryNode< A_type >::BinaryNode( const BinaryNode< A_type > & ) throw() // other
{}

template< class A_type >
const BinaryNode< A_type > &BinaryNode< A_type >::operator =( const BinaryNode< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace nodes
} // namespace realizations
} // namespace containers
} // namespace jmsf
