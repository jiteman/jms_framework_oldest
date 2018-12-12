#pragma once


#include "Amp.hpp"

#include "Allocator.h"
#include "jmsf/typing/Boolean.h"

#include "Womp.inl"
#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace memorying {


template< class A_type >
typing::Boolean Amp< A_type >::is_empty() const noexept {
	return _the_memory_pointer.is_empty();
}

template< class A_type >
typing::Boolean Amp< A_type >::is_not_empty() const noexept {
	return _the_memory_pointer.is_not_empty();
}

template< class A_type >
const A_type *Amp< A_type >::get() const noexept {
	return reinterpret_cast< const A_type * >( _the_memory_pointer.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type *Amp< A_type >::take() noexept {
	return reinterpret_cast< A_type * >( _the_memory_pointer.take() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Memory_pointer Amp< A_type >::get_memory() const noexept {
	return _the_memory_pointer;
}

template< class A_type >
typing::Memory_size Amp< A_type >::get_quantity() const noexept {
	return _the_quantity;
}

template< class A_type >
Womp< Allocator > Amp< A_type >::get_allocator() const noexept {
	return _the_allocator;
}

template< class A_type >
typing::Memory_size Amp< A_type >::get_alignment() const noexept {
	return _the_alignment;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Amp< A_type >::~Amp() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Amp< A_type >::Amp() noexept
{}

// static
template< class A_type >
Amp< A_type > Amp< A_type >::create(
	const Memory_pointer &a_memory_pointer,
	const typing::Memory_size a_quantity,
	const Womp< Allocator > &an_allocator,
	const typing::Memory_size an_alignment ) noexept
{
	return Amp< A_type >( a_memory_pointer, a_quantity, an_allocator, an_alignment );
}

template< class A_type >
Amp< A_type >::Amp(
	const Memory_pointer &a_memory_pointer,
	const typing::Memory_size a_quantity,
	const Womp< Allocator > &an_allocator,
	const typing::Memory_size an_alignment ) noexept
	:
		_the_memory_pointer( a_memory_pointer ),
		_the_quantity( a_quantity ),
		_the_allocator( an_allocator ),
		_the_alignment( an_alignment )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Amp< A_type >::Amp( const Amp< A_type > &another ) noexept
	:
		_the_memory_pointer( another._the_memory_pointer ),
		_the_quantity( another._the_quantity ),
		_the_allocator( another._the_allocator ),
		_the_alignment( another._the_alignment )
{}

template< class A_type >
const Amp< A_type > &Amp< A_type >::operator =( const Amp< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	_the_memory_pointer = another._the_memory_pointer;
	_the_quantity = another._the_quantity;
	_the_allocator = another._the_allocator;
	_the_alignment = another._the_alignment;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
