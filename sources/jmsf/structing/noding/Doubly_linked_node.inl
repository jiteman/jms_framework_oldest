#pragma once


#include "Doubly_linked_node.hpp"

//#include "jmsf/pointing/Pointers.inl"
#include "jmsf/memorying/Omp.inl"
#include "jmsf/memorying/Allocator.h"
#include "jmsf/memorying/Constructor.inl"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
A_type &Doubly_linked_node< A_type >::take_object() noexept {
	return _the_object;
}

template< class A_type >
const A_type &Doubly_linked_node< A_type >::get_object() const noexept {
	return _the_object;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
memorying::Omp< Doubly_linked_node< A_type > > &Doubly_linked_node< A_type >::take_previous_node() noexept {
	return _previous_node;
}

template< class A_type >
const memorying::Omp< Doubly_linked_node< A_type > > &Doubly_linked_node< A_type >::get_previous_node() const noexept {
	return _previous_node;
}

template< class A_type >
memorying::Omp< Doubly_linked_node< A_type > > &Doubly_linked_node< A_type >::take_next_node() noexept {
	return _next_node;
}

template< class A_type >
const memorying::Omp< Doubly_linked_node< A_type > > &Doubly_linked_node< A_type >::get_next_node() const noexept {
	return _next_node;
}

template< class A_type >
void Doubly_linked_node< A_type >::set_previous_node( const memorying::Omp< Doubly_linked_node< A_type > > &previousNode ) noexept {
	_previous_node = previousNode;
}

template< class A_type >
void Doubly_linked_node< A_type >::set_next_node( const memorying::Omp< Doubly_linked_node< A_type > > &nextNode ) noexept {
	_next_node = nextNode;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Doubly_linked_node< A_type >::~Doubly_linked_node() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// statics
template< class A_type >
memorying::Omp< Doubly_linked_node< A_type > > Doubly_linked_node< A_type >::create( const memorying::Womp< memorying::Allocator > &an_allocator ) {
	return memorying::Constructor< Doubly_linked_node< A_type >, Doubly_linked_node< A_type > >::construct( an_allocator );
}

template< class A_type >
memorying::Omp< Doubly_linked_node< A_type > > Doubly_linked_node< A_type >::create( const A_type &an_object, const memorying::Womp< memorying::Allocator > &an_allocator ) {
	return memorying::Construct< Doubly_linked_node< A_type >, Doubly_linked_node< A_type > >::construct( an_allocator, an_object );
}

template< class A_type >
memorying::Omp< Doubly_linked_node< A_type > > Doubly_linked_node< A_type >::create(
	const A_type &an_object,
	const memorying::Omp< Doubly_linked_node > &previous_node,
	const memorying::Omp< Doubly_linked_node > &next_node,
	const memorying::Womp< memorying::Allocator > &an_allocator )
{
	return memorying::Constructor< Doubly_linked_node< A_type >, Doubly_linked_node< A_type > >::construct( an_allocator, an_object, previous_node, next_node );
}
//~statics

template< class A_type >
Doubly_linked_node< A_type >::Doubly_linked_node() noexept
	:
		_the_object( A_type() )
{}

template< class A_type >
Doubly_linked_node< A_type >::Doubly_linked_node( const A_type &object ) noexept
	:
		_the_object( object )
{}

template< class A_type >
Doubly_linked_node< A_type >::Doubly_linked_node(
	const A_type &object,
	const memorying::Omp< Doubly_linked_node< A_type > > &previousNode,
	const memorying::Omp< Doubly_linked_node< A_type > > &nextNode ) noexept
	:
		_the_object( object ),
		_previous_node( previousNode ),
		_next_node( nextNode )		
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Doubly_linked_node< A_type >::Doubly_linked_node( const Doubly_linked_node< A_type > &another ) noexept
	:
		_the_object( another._the_object ),
		_previous_node( another._previous_node ),
		_next_node( another._next_node )
{}

template< class A_type >
const Doubly_linked_node< A_type > &Doubly_linked_node< A_type >::operator =( const Doubly_linked_node< A_type > &another ) noexept {
	if ( this == &other ) return *this;

	_the_object = another._the_object;
	_previous_node = another._previous_node;
	_next_node = another._next_node;	
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace noding
} // namespace structing
} // namespace jmsf
