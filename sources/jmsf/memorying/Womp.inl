#pragma once


#include "Womp.hpp"

#include "Omp.inl"

#include "Memory_pointer.h"

#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace memorying {


template< class A_type >
typing::Boolean Womp< A_type >::is_empty() const noexept {
	return _the_memory_pointer.is_empty();
}

template< class A_type >
typing::Boolean Womp< A_type >::is_not_empty() const noexept {
	return _the_memory_pointer.is_not_empty();
}

template< class A_type >
const A_type *Womp< A_type >::get() const noexept {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

template< class A_type >
const A_type &Womp< A_type >::operator *() const {
	return reinterpret_cast< const A_type & >( *_the_memory_pointer.get() );
}

template< class A_type >
const A_type *Womp< A_type >::operator ->() const {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type *Womp< A_type >::take() noexept {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

template< class A_type >
A_type &Womp< A_type >::operator *() {
	return reinterpret_cast< A_type & >( *_the_memory_pointer.take() );
}

template< class A_type >
A_type *Womp< A_type >::operator ->() {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Memory_pointer Womp< A_type >::get_memory() const noexept {
	return _the_memory_pointer;
}

template< class A_type >
typing::Memory_size Womp< A_type >::get_address() const noexept {
	return _the_memory_pointer.get_address();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Womp< A_type >::~Womp() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Womp< A_type >::Womp() noexept
{}

// static
template< class A_type >
Womp< A_type > Womp< A_type >::create_from_memory_pointer( const Memory_pointer &a_memory_pointer ) noexept {
	return Womp< A_type >( a_memory_pointer );
}

// static
template< class A_type >
Womp< A_type > Womp< A_type >::create_from_pointer( const A_type *const an_object ) noexept {
	return Womp< A_type >( Memory_pointer::create_from_pointer( an_object ) );
}

// static
template< class A_type >
Womp< A_type > Womp< A_type >::create_from_address( const typing::Memory_size an_address ) noexept {	
	return Womp< A_type >( Memory_pointer::create_from_address( an_address ) );
}

// static
// template< class A_type >
// Womp< A_type > Womp< A_type >::create( const Omp< A_type > &object_memory_pointer ) noexept {
// 	return Womp< A_type >( object_memory_pointer.get_memory() );
// }

template< class A_type >
Womp< A_type >::Womp( const Memory_pointer &a_memory_pointer ) noexept
	:
		_the_memory_pointer( a_memory_pointer )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Womp< A_type >::Womp( const Womp< A_type > &another ) noexept
	:
		_the_memory_pointer( another._the_memory_pointer )
{}

template< class A_type >
const Womp< A_type > &Womp< A_type >::operator =( const Womp< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_the_memory_pointer = another._the_memory_pointer;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
