#pragma once


#include "SinglyLinkedNode.hpp"


namespace jmsf {
namespace structing {
namespace noding {


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
pointing::Pointer< SinglyLinkedNode > &SinglyLinkedNode< A_type >::takeNextNode() throw() {
	return _nextNode;
}

template< class A_type >
const pointing::ConstantPointer< SinglyLinkedNode > &SinglyLinkedNode< A_type >::getNextNode() const throw() {
	return _constantNextNode;
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
SinglyLinkedNode< A_type >::SinglyLinkedNode( const A_type &object, const pointing::Pointer< SinglyLinkedNode > &nextNode ) throw()
	:
		_object( object ),
		_nextNode( nextNode )
{
	_constantNextNode = _nextNode.takeConstant();
}

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


} // namespace noding
} // namespace structing
} // namespace jmsf
