#pragma once


#include "Wamp.hpp"

#include "Memory_pointer.h"

#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace memorying {


template< class A_type >
typing::Boolean Wamp< A_type >::is_empty() const noexept {
	return _the_memory_pointer.is_empty();
}

template< class A_type >
typing::Boolean Wamp< A_type >::is_not_empty() const noexept {
	return _the_memory_pointer.is_not_empty();
}

template< class A_type >
const A_type *Wamp< A_type >::get() const noexept {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type *Wamp< A_type >::take() noexept {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Memory_pointer Wamp< A_type >::get_memory() const noexept {
	return _the_memory_pointer;
}

template< class A_type >
typing::Memory_size Wamp< A_type >::get_quantity() const noexept {
	return _the_quantity;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Wamp< A_type >::~Wamp() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Wamp< A_type >::Wamp() noexept
{}

// static
template< class A_type >
Wamp< A_type > Wamp< A_type >::create( const Memory_pointer &a_memory_pointer, typing::Memory_size a_quantity ) noexept {
	return Wamp< A_type >( a_memory_pointer, a_quantity );
}

template< class A_type >
Wamp< A_type >::Wamp( const Memory_pointer &a_memory_pointer, typing::Memory_size a_quantity ) noexept
	:
		_the_memory_pointer( a_memory_pointer ),
		_the_quantity( a_quantity )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Wamp< A_type >::Wamp( const Wamp< A_type > &another ) noexept
	:
		_the_memory_pointer( another._the_memory_pointer ),
		_the_quantity( another._the_quantity )
{}

template< class A_type >
const Wamp< A_type > &Wamp< A_type >::operator =( const Wamp< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_the_memory_pointer = another._the_memory_pointer;
	_the_quantity = another._the_quantity;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
