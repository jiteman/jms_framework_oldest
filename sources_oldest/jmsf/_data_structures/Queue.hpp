#pragma once

#include "jmsf/Pointers.hpp"

#include "jmsf/Exception.hxx"
#include "nodes/DoublyLinkedNode.hxx"

namespace jmsf {
namespace data_structures {

template< class A_type >
class Queue {

public:
	A_type &takeFirst() throw( Exception );
	const A_type &getFirst() const throw( Exception );

	A_type &takeLast() throw( Exception );
	const A_type &getLast() const throw( Exception );

	const Boolean isEmpty() const throw();
	const Boolean isNotEmpty() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void enqueue( const A_type &object ) throw();
	A_type dequeue() throw( Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Queue() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Queue() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Queue( const Queue &other ) throw();
	const Queue &operator =( const Queue &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< DoublyLinkedNode< A_type > > _firstNode;
	Pointer< DoublyLinkedNode< A_type > > _lastNode;
	natural_size _quantityOfNodes;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace data_structures
} // namespace jmsf


#include "nodes/DoublyLinkedNode.hpp"
#include "jmsf/debugging/static_ObjectCreationLogger.hpp"

namespace jmsf {
namespace data_structures {

template< class A_type >
A_type &Queue< A_type >::takeFirst() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "Queue< A_type >::takeFirst()" ) );
	}

	return _firstNode->takeObject();
}

template< class A_type >
const A_type &Queue< A_type >::getFirst() const throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "Queue< A_type >::getFirst()" ) );
	}

	return _firstNode->getObject();
}

template< class A_type >
A_type &Queue< A_type >::takeLast() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "Queue< A_type >::takeLast()" ) );
	}

	return _lastNode->takeObject();
}

template< class A_type >
const A_type &Queue< A_type >::getLast() const throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "Queue< A_type >::getLast()" ) );
	}

	return _lastNode->getObject();
}

template< class A_type >
const Boolean Queue< A_type >::isEmpty() const throw() {
	return _quantityOfNodes == 0;
}

template< class A_type >
const Boolean Queue< A_type >::isNotEmpty() const throw() {
	return _quantityOfNodes != 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
void Queue< A_type >::enqueue( const A_type &object ) throw() {
	if ( _quantityOfNodes == 0 ) {
		_lastNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				debugging::static_ObjectCreationLogger< DoublyLinkedNode< A_type > >::registerCreation(
					new DoublyLinkedNode< A_type >( object ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "Queue< A_type >::enqueue()" ) );

		_firstNode  = _lastNode;
	} else {
		Pointer< DoublyLinkedNode< A_type > > oldLastNode = _lastNode;

		_lastNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				debugging::static_ObjectCreationLogger< DoublyLinkedNode< A_type > >::registerCreation(
					new DoublyLinkedNode< A_type >( object, Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE, _lastNode ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "Queue< A_type >::enqueue()" ) );
		oldLastNode->setPreviousNode( _lastNode );
	}

	_quantityOfNodes += 1;
}

template< class A_type >
A_type Queue< A_type >::dequeue() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "Queue< A_type >::dequeue()" ) );
	}

	_quantityOfNodes -= 1;
	A_type firstObject = _firstNode->getObject();

	if ( _quantityOfNodes == 0 ) {
		_lastNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
		_firstNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
	} else {
		Pointer< DoublyLinkedNode< A_type > > oldPreviousNode = _firstNode->takePreviousNode();
		_firstNode->takePreviousNode()->setNextNode( Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE );
		_firstNode = oldPreviousNode;		
	}

	return firstObject;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Queue< A_type >::~Queue() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Queue< A_type >::Queue() throw() {
	_quantityOfNodes = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Queue< A_type >::Queue( const Queue< A_type > & ) throw() // other
{}

template< class A_type >
const Queue< A_type > &Queue< A_type >::operator =( const Queue< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace data_structures
} // namespace jmsf
