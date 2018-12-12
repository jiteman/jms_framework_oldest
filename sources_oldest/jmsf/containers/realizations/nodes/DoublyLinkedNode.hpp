#pragma once


#include "jmsf/Pointers.hpp"


namespace jmsf {
namespace containers {
namespace realizations {
namespace nodes {


template< class A_type >
class DoublyLinkedNode {

public:
	A_type &takeObject() throw();
	const A_type &getObject() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointer< DoublyLinkedNode > &takePreviousNode() throw();
	const ConstantPointer< DoublyLinkedNode > &getPreviousNode() const throw();

	Pointer< DoublyLinkedNode > &takeNextNode() throw();
	const ConstantPointer< DoublyLinkedNode > &getNextNode() const throw();

	void setPreviousNode( const Pointer< DoublyLinkedNode > &previousNode ) throw();
	void setNextNode( const Pointer< DoublyLinkedNode > &nextNode ) throw();	

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~DoublyLinkedNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	DoublyLinkedNode() throw();
	DoublyLinkedNode( const A_type &object ) throw();
	DoublyLinkedNode( const A_type &object, const Pointer< DoublyLinkedNode > &previousNode, const Pointer< DoublyLinkedNode > &nextNode ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	DoublyLinkedNode( const DoublyLinkedNode &other ) throw();
	const DoublyLinkedNode &operator =( const DoublyLinkedNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Pointer< DoublyLinkedNode > _previousNode;
	Pointer< DoublyLinkedNode > _nextNode;	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _object;

public:
	static Pointer< DoublyLinkedNode > EMPTY_NODE;

};


} // namespace nodes
} // namespace realizations
} // namespace containers
} // namespace jmsf


namespace jmsf {
namespace containers {
namespace realizations {
namespace nodes {


template< class A_type >
A_type &DoublyLinkedNode< A_type >::takeObject() throw() {
	return _object;
}

template< class A_type >
const A_type &DoublyLinkedNode< A_type >::getObject() const throw() {
	return _object;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Pointer< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::takePreviousNode() throw() {
	return _previousNode;
}

template< class A_type >
const Pointer< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::getPreviousNode() const throw() {
	return _previousNode;
}

template< class A_type >
Pointer< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::takeNextNode() throw() {
	return _nextNode;
}

template< class A_type >
const Pointer< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::getNextNode() const throw() {
	return _nextNode;
}

template< class A_type >
void DoublyLinkedNode< A_type >::setPreviousNode( const Pointer< DoublyLinkedNode< A_type > > &previousNode ) throw() {
	_previousNode = previousNode;
}

template< class A_type >
void DoublyLinkedNode< A_type >::setNextNode( const Pointer< DoublyLinkedNode< A_type > > &nextNode ) throw() {
	_nextNode = nextNode;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
DoublyLinkedNode< A_type >::~DoublyLinkedNode() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode() throw()
	:
		_object( A_type() )
{}

template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const A_type &object ) throw()
	:
		_object( object )
{}

template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const A_type &object, const Pointer< DoublyLinkedNode< A_type > > &previousNode, const Pointer< DoublyLinkedNode< A_type > > &nextNode ) throw()
	:
		_object( object ),
		_previousNode( previousNode ),
		_nextNode( nextNode )		
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const DoublyLinkedNode< A_type > & ) throw() // other
{}

template< class A_type >
const DoublyLinkedNode< A_type > &DoublyLinkedNode< A_type >::operator =( const DoublyLinkedNode< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Pointer< DoublyLinkedNode > EMPTY_NODE;


} // namespace nodes
} // namespace realizations
} // namespace containers
} // namespace jmsf
