#pragma once

#include "jmsf/Pointers.hpp"

namespace jmsf {
namespace data_structures {
namespace nodes {

template< class A_type >
class SinglyLinkedNode {

public:
	A_type &takeObject() throw();
	const A_type &getObject() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointer< SinglyLinkedNode > &takeNextNode() throw();
	const ConstantPointer< SinglyLinkedNode > &getNextNode() const throw();

	void setNextNode( const SinglyLinkedNode *nextNode ) throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~SinglyLinkedNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	SinglyLinkedNode() throw();
	SinglyLinkedNode( const A_type &object, const SinglyLinkedNode &nextNode ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	SinglyLinkedNode( const SinglyLinkedNode &other ) throw();
	const SinglyLinkedNode &operator =( const SinglyLinkedNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< SinglyLinkedNode > _nextNode;
	ConstantPointer< SinglyLinkedNode > _constantNextNode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _object;

};

} // namespace nodes
} // namespace data_structures
} // namespace jmsf


namespace jmsf {
namespace data_structures {
namespace nodes {

template< class A_type >
A_type &SinglyLinkedNode< A_type >::takeObject() throw() {
	return _object;
}

template< class A_type >
const A_type &SinglyLinkedNode< A_type >::getObject() const throw() {
	return _object;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
SinglyLinkedNode *SinglyLinkedNode< A_type >::takeNextNode() throw() {
	return _nextNode;
}

template< class A_type >
const SinglyLinkedNode *const SinglyLinkedNode< A_type >::getNextNode() const throw() {
	return _nextNode;
}

template< class A_type >
void SinglyLinkedNode< A_type >::setNextNode( const Pointer< SinglyLinkedNode > &nextNode ) throw() {
	_nextNode = nextNode;
	_constantNextNode = _nextNode.takeConstant();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
SinglyLinkedNode< A_type >::~SinglyLinkedNode() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
SinglyLinkedNode< A_type >::SinglyLinkedNode() throw()
	:
		_object( A_type() )
{}

template< class A_type >
SinglyLinkedNode< A_type >::SinglyLinkedNode( const A_type &object, const SinglyLinkedNode &nextNode ) throw()
	:
		_object( object ),
		_nextNode( nextNode )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
SinglyLinkedNode< A_type >::SinglyLinkedNode( const SinglyLinkedNode< A_type > & ) throw() // other
{}

template< class A_type >
const SinglyLinkedNode< A_type > &SinglyLinkedNode< A_type >::operator =( const SinglyLinkedNode< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace nodes
} // namespace data_structures
} // namespace jmsf
