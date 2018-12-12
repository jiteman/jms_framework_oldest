#pragma once


#include "Omp.hpp"

#include "Allocator.h"
#include "jmsf/typing/Boolean.h"

#include "Womp.inl"
#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace memorying {


template< class A_type >
typing::Boolean Omp< A_type >::is_empty() const noexept {
	return _the_memory_pointer.is_empty();
}

template< class A_type >
typing::Boolean Omp< A_type >::is_not_empty() const noexept {
	return _the_memory_pointer.is_not_empty();
}

template< class A_type >
const A_type *Omp< A_type >::get() const noexept {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

template< class A_type >
const A_type &Omp< A_type >::operator *() const {
	return reinterpret_cast< const A_type & >( *_the_memory_pointer.get() );
}

template< class A_type >
const A_type *Omp< A_type >::operator ->() const {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type *Omp< A_type >::take() noexept {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

template< class A_type >
A_type &Omp< A_type >::operator *() {
	return reinterpret_cast< A_type & >( *_the_memory_pointer.take() );
}

template< class A_type >
A_type *Omp< A_type >::operator ->() {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Memory_pointer Omp< A_type >::get_memory() const noexept {
	return _the_memory_pointer;
}

template< class A_type >
Womp< Allocator > Omp< A_type >::get_allocator() const noexept {
	return _the_allocator;
}

template< class A_type >
typing::Memory_size Omp< A_type >::get_alignment() const noexept {
	return _the_alignment;
}

template< class A_type >
Womp< A_type > Omp< A_type >::get_as_weak() const noexept {
	return Womp< A_type >::create_from_memory_pointer( _the_memory_pointer );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Omp< A_type >::~Omp() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Omp< A_type >::Omp() noexept
{}

// static
template< class A_type >
Omp< A_type > Omp< A_type >::create(
	const Memory_pointer &a_memory_pointer,
	const Womp< Allocator > &an_allocator,
	const typing::Memory_size an_alignment ) noexept
{
	return Omp< A_type >( a_memory_pointer, an_allocator, an_alignment );
}

// static
template< class A_type >
Omp< A_type> Omp< A_type >::create_from_weak( const Womp< A_type > &weak_omp ) noexept {
	return Omp< A_type >( weak_omp.get_memory(), Womp< Allocator >(), typing::Memory_size_nill );
}

template< class A_type >
Omp< A_type >::Omp( const Memory_pointer &a_memory_pointer, const Womp< Allocator > &an_allocator, const typing::Memory_size an_alignment ) noexept
	:
		_the_memory_pointer( a_memory_pointer ),
		_the_allocator( an_allocator ),
		_the_alignment( an_alignment )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Omp< A_type >::Omp( const Omp< A_type > &another ) noexept
	:
		_the_memory_pointer( another._the_memory_pointer ),
		_the_allocator( another._the_allocator ),
		_the_alignment( another._the_alignment )
{}

template< class A_type >
const Omp< A_type > &Omp< A_type >::operator =( const Omp< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_the_memory_pointer = another._the_memory_pointer;
	_the_allocator = another._the_allocator;
	_the_alignment = another._the_alignment;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
