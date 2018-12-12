#pragma once


#include "DoublyLinkedNode.hpp"
#include "jmsf/pointing/Pointers.inl"

#include "jmsf/memorying/Allocator.h"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
A_type &DoublyLinkedNode< A_type >::takeObject() throw() {
	return _theObject;
}

template< class A_type >
const A_type &DoublyLinkedNode< A_type >::getObject() const throw() {
	return _theObject;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
pointing::Reference< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::takePreviousNode() throw() {
	return _previousNode;
}

template< class A_type >
const pointing::Reference< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::getPreviousNode() const throw() {
	return _previousNode;
}

template< class A_type >
Reference< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::takeNextNode() throw() {
	return _nextNode;
}

template< class A_type >
const Reference< DoublyLinkedNode< A_type > > &DoublyLinkedNode< A_type >::getNextNode() const throw() {
	return _nextNode;
}

template< class A_type >
void DoublyLinkedNode< A_type >::setPreviousNode( const pointing::Reference< DoublyLinkedNode< A_type > > &previousNode ) throw() {
	_previousNode = previousNode;
}

template< class A_type >
void DoublyLinkedNode< A_type >::setNextNode( const pointing::Reference< DoublyLinkedNode< A_type > > &nextNode ) throw() {
	_nextNode = nextNode;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
DoublyLinkedNode< A_type >::~DoublyLinkedNode() throw()
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// statics
template< class A_type >
pointing::Reference< DoublyLinkedNode< A_type > > DoublyLinkedNode< A_type >::create( memorying::Allocator &allocator ) throw( validating::Exception ) {
	return pointing::Reference< DoublyLinkedNode< A_type > >( memorying::Construct< A_type >( allocator ) );
}

template< class A_type >
pointing::Reference< DoublyLinkedNode< A_type > > DoublyLinkedNode< A_type >::create( const A_type &anObject, memorying::Allocator &allocator ) throw( validating::Exception ) {
	return pointing::Reference< DoublyLinkedNode< A_type > >( memorying::Construct< A_type >( allocator, anObject ) );
}

template< class A_type >
pointing::Reference< DoublyLinkedNode< A_type > > DoublyLinkedNode< A_type >::create( const A_type &object, const pointing::Reference< DoublyLinkedNode > &previousNode, const pointing::Reference< DoublyLinkedNode > &nextNode, memorying::Allocator &allocator ) throw( validating::Exception ) {
	return pointing::Reference< DoublyLinkedNode< A_type > >( memorying::Construct< A_type >( allocator, anObject, previousNode, nextNode ) );
}
//~statics

template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode() throw()
	:
		_theObject( A_type() )
{}

template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const A_type &object ) throw()
	:
		_theObject( object )
{}

template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const A_type &object, const pointing::Reference< DoublyLinkedNode< A_type > > &previousNode, const pointing::Reference< DoublyLinkedNode< A_type > > &nextNode ) throw()
	:
		_theObject( object ),
		_previousNode( previousNode ),
		_nextNode( nextNode )		
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
DoublyLinkedNode< A_type >::DoublyLinkedNode( const DoublyLinkedNode< A_type > &another ) throw()
	:
		_theObject( another._theObject ),
		_previousNode( another._previousNode ),
		_nextNode( another._nextNode )
{}

template< class A_type >
const DoublyLinkedNode< A_type > &DoublyLinkedNode< A_type >::operator =( const DoublyLinkedNode< A_type > &another ) throw() {
	if ( this == &other ) return *this;

	_theObject = another._theObject;
	_previousNode = another._previousNode;
	_nextNode = another._nextNode;	
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace noding
} // namespace structing
} // namespace jmsf
