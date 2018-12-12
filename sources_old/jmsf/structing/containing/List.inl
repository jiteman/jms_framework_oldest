#pragma once


#include "List.hpp"

#include "ListAgent.inl"
#include "jmsf/pointing/Reference.inl"
#include "jmsf/structing/noding/DoublyLinkedNode.inl"
#include "jmsf/typing/Asd.inl"


namespace jmsf {
namespace sructing {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// common getters
template< class A_type >
typing::Boolean List< A_type >::isEmpty() const throw() {
	return _quantityOfElements.isNull();
}

template< class A_type >
typing::Boolean List< A_type >::isNotEmpty() const throw() {
	return _quantityOfElements.isNotNull();
}

template< class A_type >
const typing::Asd &List< A_type >::getQuantityOfElements() const throw() {
	return _quantityOfElements;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
template< class A_type >
void List< A_type >::appendToBegin( const A_type &anObject, const memorying::Allocator &nodeAllocator ) throw() {
	pointing::Reference< noding::DoublyLinkedNode< A_type > > newBeginNode =
		noding::DoublyLinkedNode< A_type >::create(
			anObject,
			pointing::Reference< noding::DoublyLinkedNode< A_type > >(),
			_begin,
			nodeAllocator );

	if ( _begin.isNotEmpty() ) {
		_begin->setPreviousNode( newBeginNode );
	}

	_begin = newBeginNode;

	if ( _end.isEmpty() ) {
		_end = _begin;
	}
}

template< class A_type >
void List< A_type >::appendToEnd( const A_type &anObject, const memorying::Allocator &nodeAllocator ) throw() {
	pointing::Reference< noding::DoublyLinkedNode< A_type > > newEndNode =
		noding::DoublyLinkedNode< A_type >::create(
			anObject,			
			_end,
			pointing::Reference< noding::DoublyLinkedNode< A_type > >(),
			nodeAllocator );

	if ( _end.isNotEmpty() ) {
		_end->setNextNode( newEndNode );
	}

	_end = newEndNode;

	if ( _begin.isEmpty() ) {
		_begin = _end;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// factories
template< class A_type >
pointing::Reference< traversing::ListTraverser< A_type > > List< A_type >::createTraverserAtBegin( const memorying::Allocator &traverserAllocator ) throw( validating::Exception ) {
	// if isEmpty() throw exception;
	return memorying::Construct< traversing::ListTraverser< A_type > >( traverserAllocator, pointing::WeakReference< List< A_type > >( this ), 	_begin );
}

template< class A_type >
pointing::Reference< traversing::ListTraverser< A_type > > List< A_type >::createTraverserAtEnd( const memorying::Allocator &traverserAllocator ) throw( validating::Exception ) {
	// if isEmpty() throw exception;
	return memorying::Construct< traversing::ListTraverser< A_type > >( traverserAllocator, pointing::WeakReference< List< A_type > >( this ), 	_end );
}

template< class A_type >
pointing::Reference< traversing::ListTraverser< A_type > > List< A_type >::createTraverserAtFromBegin( const typing::Asd &anIndex, const memorying::Allocator &traverserAllocator ) throw( validating::Exception ) {
	// if isEmpty() throw exception;
	// if index is negative throw exception
	// if index is out of range throw exception
	pointing::Reference< noding::DoublyLinkedNode< A_type > > indexedNode = _begin;

	for ( typing::Asd nodeCounter = index; nodeCounter != typing::AsdZero; nodeCounter -= typing::AsdOne ) {
		indexedNode = indexedNode->takeNextNode();
	}

	return memorying::Construct< traversing::ListTraverser< A_type > >( traverserAllocator, pointing::WeakReference< List< A_type > >( this ), 	indexedNode );
}

template< class A_type >
pointing::Reference< traversing::ListTraverser< A_type > > List< A_type >::createTraverserAtFromEnd( const typing::Asd &anIndex, const memorying::Allocator &traverserAllocator ) throw( validating::Exception ) {
	// if isEmpty() throw exception;
	// if index is negative throw exception
	// if index is out of range throw exception
	pointing::Reference< noding::DoublyLinkedNode< A_type > > indexedNode = _end;

	for ( typing::Asd nodeCounter = index; nodeCounter != typing::AsdZero; nodeCounter -= typing::AsdOne ) {
		indexedNode = indexedNode->takePreviousNode();
	}

	return memorying::Construct< traversing::ListTraverser< A_type > >( traverserAllocator, pointing::WeakReference< List< A_type > >( this ), 	indexedNode );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// virtuals ListAgent< A_type >
template< class A_type >
pointing::Reference< noding::DoublyLinkedNode< A_type > > &List< A_type >::takeBegin() throw() {
	return _begin;
}

template< class A_type >
pointing::Reference< noding::DoublyLinkedNode< A_type > > &List< A_type >::takeEnd() throw() {
	return _end;
}

template< class A_type >
typing::Asd &List< A_type >::takeQuantity() throw() {
	return _quantityOfElements;
}

//~virtuals ListAgent< A_type >
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
List< A_type >::~List() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
List< A_type >::List() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
List< A_type >::List( const List< A_type > &another ) throw()
{}

template< class A_type >
const List< A_type > &List< A_type >::operator =( const List< A_type > &another ) throw() {
	if ( &another == this ) return *this;
	
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace sructing
} // namespace jmsf
