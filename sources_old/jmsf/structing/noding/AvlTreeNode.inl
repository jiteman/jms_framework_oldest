#pragma once


#include "AvlTreeNode.hpp"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
A_type &AvlTreeNode< A_type >::takeObject() throw() {
	return _object;
}

template< class A_type >
const A_type &AvlTreeNode< A_type >::getObject() const throw() {
	return _object;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
pointing::Pointer< AvlTreeNode > &AvlTreeNode< A_type >::takeLeftChild() throw() {
	return _leftChild;
}

template< class A_type >
pointing::ConstantPointer< AvlTreeNode > &AvlTreeNode< A_type >::getLeftChild() const throw() {
	return _constantLeftChild;
}

template< class A_type >
pointing::Pointer< AvlTreeNode > &AvlTreeNode< A_type >::takeRightChild() throw() {
	return _rightChild;
}

template< class A_type >
pointing::ConstantPointer< AvlTreeNode > &AvlTreeNode< A_type >::getRightChild() const throw() {
	return _constantRightChild;
}

template< class A_type >
void AvlTreeNode< A_type >::setLeftChild( const pointing::Pointer< AvlTreeNode > &leftChild ) throw() {
	_leftChild = leftChild;
	_constantLeftChild = _leftChild.takeConstant();
}

template< class A_type >
void AvlTreeNode< A_type >::setRightChild( const pointing::Pointer< AvlTreeNode > &rightChild ) throw() {
	_rightChild = rightChild;
	_constantRightChild = _rightChild.takeConstant()
}

template< class A_type >
typing::Natural AvlTreeNode< A_type >::getKey() const throw() {
	return _key;
}

template< class A_type >
typing::ShortestNatural AvlTreeNode< A_type >::getHeight() const throw() {
	return _height;
}

template< class A_type >
void AvlTreeNode< A_type >::setHeight( const typing::ShortestNatural height ) throw() {
	_height = height;
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
AvlTreeNode< A_type >::~AvlTreeNode() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
AvlTreeNode< A_type >::AvlTreeNode() throw()
{}

template< class A_type >
AvlTreeNode< A_type >::AvlTreeNode( const types::Natural key, const A_type &object ) throw()
	:
		_key( key ),
		_height( types::ShortestNaturalOne ),
		_object( object )
{}

template< class A_type >
AvlTreeNode< A_type >::AvlTreeNode( const pointing::Pointer< AvlTreeNode > &leftChild, const pointing::Pointer< AvlTreeNode > &rightChild, const A_type &object ) throw()
	:
		_leftChild( leftChild ),
		_rightChild( rightChild ),
		_height( 
		_object( object )
{
	_constantLeftChild = _leftChild.takeConstant();
	_constantRightChild = _rightChild.takeConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
AvlTreeNode< A_type >::AvlTreeNode( const AvlTreeNode< A_type > & ) throw() { // other
}

template< class A_type >
const AvlTreeNode< A_type > &AvlTreeNode< A_type >::operator =( const AvlTreeNode< A_type > &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace noding
} // namespace structing
} // namespace jmsf
