#pragma once


#include "Destructor.hpp"

#include "Omp.inl"
#include "Amp.inl"
#include "Allocator.h"
#include "jmsf/typing/Aso.inl"
#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace memorying {


template< class A_type >
void Destructor< A_type >::destruct( const Omp< A_type > &an_object_memory_pointer ) {
	if ( an_object_memory_pointer.is_empty() ) return;
	if ( an_object_memory_pointer.get_allocator().is_empty() ) return;

	an_object_memory_pointer.get()->~A_type();

	an_object_memory_pointer.get_allocator()->deallocate_memory(
		an_object_memory_pointer.get_memory(),
		an_object_memory_pointer.get_alignment() );
}

template< class A_type >
void Destructor< A_type >::destruct( const Amp< A_type > &an_array_memory_pointer ) {
	if ( an_array_memory_pointer.is_empty() ) return;
	if ( an_array_memory_pointer.get_allocator().is_empty() ) return;

	const A_type *pointer_to_object = an_array_memory_pointer.get();

	for ( typing::Memory_size counter = an_array_memory_pointer.get_quantity(); counter.is_not_nill(); --counter ) {
		pointer_to_object++->~A_type();
	}

	an_array_memory_pointer.get_allocator()->deallocate_memory(
		an_array_memory_pointer.get_memory(),
		an_array_memory_pointer.get_alignment() );
}

// template< typename A_type >
// void Destruct( const Omp< A_type > &an_object_memory_pointer ) {
// 	Destructor< A_type >::destruct( object );
// }
// 
// template< typename A_type >
// void Destruct( const Amp< A_type > &an_array_memory_pointer ) {
// 	Destructor< A_type >::destruct( object );
// }


} // namespace memorying
} // namespace jmsf
