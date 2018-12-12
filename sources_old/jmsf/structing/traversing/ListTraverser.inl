#pragma once


#include "ListTraverser.hpp"

#include "jmsf/structing/containing/ListAgent.inl"
#include "jmsf/structing/noding/DoublyLinkedNode.inl"

#include "jmsf/pointing/WeakReference.inl"
#include "jmsf/pointing/Reference.inl"


namespace jmsf {
namespace sructing {
namespace traversing {

// common getters
template< class A_type >
typing::Boolean ListTraverser< A_type >::isDone() const throw() {
	return _theNode.isEmpty();
}

template< class A_type >
typing::Boolean ListTraverser< A_type >::isNotDone() const throw() {
	return _theNode.isNotEmpty();
}
//~common getters
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// element getters
template< class A_type >
const A_type &ListTraverser< A_type >::getObject() const throw( validating::Exception ) {
	return **_theNode;
}

template< class A_type >
A_type &ListTraverser< A_type >::takeObject() throw( validating::Exception ) {
	return **_theNode;
}

//~element getters

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// iterations
template< class A_type >
void ListTraverser< A_type >::rewindToBegin() throw() {
	_theNode = _theListAgent->takeBegin();
	_isReversed = typing::False;
}

template< class A_type >
void ListTraverser< A_type >::rewindToEnd() throw() {
	_theNode = _theListAgent->takeEnd();
	_isReversed = typing::True;
}

template< class A_type >
void ListTraverser< A_type >::moveOneStepToBegin() throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	_theNode = _theNode->takePreviousNode();
}

template< class A_type >
void ListTraverser< A_type >::moveOneStepToEnd() throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	_theNode = _theNode->takeNextNode();
}

//~iterations

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
template< class A_type >
void ListTraverser< A_type >::insertAfter( const memorying::Allocator &aNodeAllocator, const A_type &anObject ) throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	pointing::Reference< noding::DoublyLinkedNode< A_type > > theNewNode =
		noding::DoublyLinkedNode< A_type >::create(
			_theNode,			
			_theNode->takeNextNode(),
			pointing::Reference< noding::DoublyLinkedNode< A_type > >(),
			aNodeAllocator );

	if ( _theNode->takeNextNode().isNotEmpty() ) {
		_theNode->takeNextNode()->setPreviousNode( theNewNode );
	}

	_theNode->setNextNode( theNewNode );
	_theNode = theNewNode;
}

template< class A_type >
void ListTraverser< A_type >::insertBefore( const memorying::Allocator &aNodeAllocator, const A_type &anObject ) throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	pointing::Reference< noding::DoublyLinkedNode< A_type > > theNewNode =
		noding::DoublyLinkedNode< A_type >::create(
			_theNode->takePreviousNode(),			
			_theNode,
			pointing::Reference< noding::DoublyLinkedNode< A_type > >(),
			aNodeAllocator );

	if ( _theNode->takePreviousNode().isNotEmpty() ) {
		_theNode->takePreviousNode()->setNextNode( theNewNode );
	}

	_theNode->setPreviousNode( theNewNode );
	_theNode = theNewNode;
}

//~appending modifiers

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// erasing modifiers
template< class A_type >
void ListTraverser< A_type >::eraseObject() throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	pointing::Reference< noding::DoublyLinkedNode< A_type > > theNodeToErase = _theNode;

	_theNode = _isReversed ? _theNode->takePreviousNode() : _theNode->takeNextNode();

	if ( theNodeToErase->takePreviousNode().isNotEmpty() ) {
		theNodeToErase->takePreviousNode()->setNextNode( theNodeToErase->takeNextNode() );
	}

	if ( theNodeToErase->takeNextNode().isNotEmpty() ) {
		theNodeToErase->takeNextNode()->setPreviousNode( theNodeToErase->takePreviousNode() );
	}

	memorying::Destruct< A_type >( theNodeToErase.take() );
}

template< class A_type >
A_type ListTraverser< A_type >::withdrawObject() throw( validating::Exception ) {
	if ( _theNode.isEmpty() ) /*throw*/;

	pointing::Reference< noding::DoublyLinkedNode< A_type > > theNodeToErase = _theNode;

	_theNode = _isReversed ? _theNode->takePreviousNode() : _theNode->takeNextNode();

	if ( theNodeToErase->takePreviousNode().isNotEmpty() ) {
		theNodeToErase->takePreviousNode()->setNextNode( theNodeToErase->takeNextNode() );
	}

	if ( theNodeToErase->takeNextNode().isNotEmpty() ) {
		theNodeToErase->takeNextNode()->setPreviousNode( theNodeToErase->takePreviousNode() );
	}

	A_type withdrawingObject = *theNodeToErase;
	memorying::Destruct< A_type >( theNodeToErase.take() );
	return withdrawingObject;
}

//~erasing modifiers

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
void ListTraverser< A_type >::inverseReversing() throw() {
	_isReversed = _isReversed.not();
}

template< class A_type >
void ListTraverser< A_type >::setRevercing( const typing::Boolean isReversed ) throw() {
	_isReversed = isReversed;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
ListTraverser< A_type >::~ListTraverser() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
ListTraverser< A_type >::ListTraverser( const pointing::WeakReference< containing::ListAgent< A_type > > &aListAgent, const pointing::Reference< noding::DoublyLinkedNode< A_type > > &aNode, const typing::Boolean isReversed ) throw()
	:
		_theListAgent( aListAgent ),
		_theNode( aNode ),
		_isReversed( isReversed )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
ListTraverser< A_type >::ListTraverser( const ListTraverser< A_type > &another ) throw()
	:
		_theListAgent( another._theListAgent ),
		_theNode( another._theNode ),
		_isReversed( another._isReversed )
{}

template< class A_type >
const ListTraverser< A_type > &ListTraverser< A_type >::operator =( const ListTraverser< A_type > &another ) throw() {
	if ( &another == this ) return *this;

	_theListAgent = another._theListAgent;
	_theNode = another._theNode;
	_isReversed = another._isReversed;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace traversing
} // namespace sructing
} // namespace jmsf
