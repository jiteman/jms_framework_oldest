#pragma once

#include "../Container.hpp"

#include "nodes/DoublyLinkedNode.hxx"


namespace jmsf {
namespace containers {
namespace realizations {


template< class A_type >
class realization_ContainerList :
	public Container< A_type >
{

public:
	A_type &takeContainie( natural_size index ) throw( Exception );
	const A_type &getContainie( natural_size index ) throw( Exception );

	A_type &takeFirstContainie() throw( Exception );
	const A_type &getFirstContainie() const throw( Exception );

	A_type &takeLastContainie() throw( Exception );
	const A_type &getLastContainie() const throw( Exception );

	const Boolean isEmpty() const throw();
	const Boolean isNotEmpty() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void appendFrontContainie( const A_type &object ) throw();
	void appendBackContainie( const A_type &object ) throw();

	A_type withdrawContainie( natural_size index ) throw( Exception );
	A_type withdrawFirstContainie() throw( Exception );
	A_type withdrawLastContainie() throw( Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~realization_ContainerList() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_ContainerList() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_ContainerList( const realization_ContainerList &other ) throw();
	const realization_ContainerList &operator =( const realization_ContainerList &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< DoublyLinkedNode< A_type > > _firstNode;
	Pointer< DoublyLinkedNode< A_type > > _lastNode;
	natural_size _quantityOfNodes;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizations
} // namespace containers
} // namespace jmsf


#include "nodes/DoublyLinkedNode.hpp"
#include "jmsf/debugging/static_ObjectCreationLogger.hpp"


namespace jmsf {
namespace containers {
namespace realizations {


template< class A_type >
A_type &realization_ContainerList< A_type >::takeFirst() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::takeFirst()" ) );
	}

	return _firstNode->takeObject();
}

template< class A_type >
const A_type &realization_ContainerList< A_type >::getFirst() const throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::getFirst()" ) );
	}

	return _firstNode->getObject();
}

template< class A_type >
A_type &realization_ContainerList< A_type >::takeLast() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::takeLast()" ) );
	}

	return _lastNode->takeObject();
}

template< class A_type >
const A_type &realization_ContainerList< A_type >::getLast() const throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::getLast()" ) );
	}

	return _lastNode->getObject();
}

template< class A_type >
const Boolean realization_ContainerList< A_type >::isEmpty() const throw() {
	return _quantityOfNodes == 0;
}

template< class A_type >
const Boolean realization_ContainerList< A_type >::isNotEmpty() const throw() {
	return _quantityOfNodes != 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
void realization_ContainerList< A_type >::appendFront( const A_type &object ) throw() {
	if ( _quantityOfNodes == 0 ) {
		_firstNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				debugging::static_ObjectCreationLogger< DoublyLinkedNode< A_type > >::registerCreation(
					new DoublyLinkedNode< A_type >( object ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "List< A_type >::appendFront()" ) );

		_lastNode = _firstNode;
	} else {
		Pointer< DoublyLinkedNode< A_type > > oldFirstNode = _firstNode;

		_firstNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				debugging::static_ObjectCreationLogger< DoublyLinkedNode< A_type > >::registerCreation(
					new DoublyLinkedNode< A_type >( object, Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE, oldFirstNode ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "List< A_type >::appendFront()" ) );

		oldFirstNode->setPreviousNode( _firstNode );
	}

	_quantityOfNodes += 1;
}

template< class A_type >
void realization_ContainerList< A_type >::appendBack( const A_type &object ) throw() {
	if ( _quantityOfNodes == 0 ) {
		_firstNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				debugging::static_ObjectCreationLogger< DoublyLinkedNode< A_type > >::registerCreation(
					new DoublyLinkedNode< A_type >( object ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "List< A_type >::appendBack()" ) );

		_lastNode = _firstNode;
	} else {
		Pointer< DoublyLinkedNode< A_type > > oldLastNode = _lastNode;

		_lastNode =
			Pointer< DoublyLinkedNode< A_type > >::createShared(
				new DoublyLinkedNode< A_type >( object, oldLastNode, Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE ), sizeof( DoublyLinkedNode< A_type > ), "DoublyLinkedNode( A_type )", "List< A_type >::appendBack()" ) );

		oldLastNode->setNextNode( _lastNode );
	}

	_quantityOfNodes += 1;
}

template< class A_type >
A_type realization_ContainerList< A_type >::withdrawFirst() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::withdrawFirst()" ) );
	}

	Pointer< DoublyLinkedNode< A_type > > oldFirstObjectNode = _firstNode;

	if ( _quantityOfNodes == 1 ) {
		_lastNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
		_firstNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
	} else {
		_firstNode = _firstNode->getNextNode();
		_firstNode->setPreviousNode( Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE );
	}

	_quantityOfNodes -= 1;

	return oldFirstNode->getObject();
}

template< class A_type >
A_type realization_ContainerList< A_type >::withdrawLast() throw( Exception ) {
	if ( _quantityOfNodes == 0 ) {
		return exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "List< A_type >::withdrawLast()" ) );
	}

	Pointer< DoublyLinkedNode< A_type > > oldLastNode = _lastNode->getObject();

	if ( _quantityOfNodes == 1 ) {
		_lastNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
		_firstNode = Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE;
	} else {
		_lastNode = _lastNode->getPreviousNode();
		_lastNode->setNextNode( Pointer< DoublyLinkedNode< A_type > >::EMPTY_NODE );
	}

	_quantityOfNodes -= 1;

	return oldLastNode->getObject();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerList< A_type >::~realization_ContainerList() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerList< A_type >::realization_ContainerList() throw() {
	_quantityOfNodes = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerList< A_type >::realization_ContainerList( const realization_ContainerList< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerList< A_type > &realization_ContainerList< A_type >::operator =( const realization_ContainerList< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizations
} // namespace containers
} // namespace jmsf
