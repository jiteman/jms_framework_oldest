#pragma once


#include "Constructor.hpp"

#include "jmsf/memorying/Allocator.h"
#include "Omp.inl"
#include "Amp.inl"
#include "Womp.inl"

#include "jmsf/typing/Aso.inl"
#include "jmsf/typing/Naturals.inl"

#include <new>


namespace jmsf {
namespace memorying {


template< class A_type, class A_creating_type >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();

	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type;
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_creating_type &original ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( original );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();

	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third, fourth );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();

	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third, fourth, fifth );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third, fourth, fifth, sixth );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third, fourth, fifth, sixth, seventh );
	return object_memory_pointer;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
Omp< A_type > Constructor< A_type, A_creating_type >::construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw() {
	if ( an_allocator.is_empty() ) return Omp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Omp< A_type > object_memory_pointer = Omp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >(),
			typing::alignment_of< A_creating_type >() ),
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( object_memory_pointer.is_empty() ) return Omp< A_type >();
	
	::new ( reinterpret_cast< void * >( object_memory_pointer.get_memory().take() ) ) A_creating_type( first, second, third, fourth, fifth, sixth, seventh, eighth );
	return object_memory_pointer;
}


template< class A_type, class A_creating_type >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_default_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type;
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_copy_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_creating_type &original ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( original );
	}

	return array_memory_object;
}


template< class A_type, class A_creating_type >
template< class A_first >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third, fourth );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third, fourth, fifth );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third, fourth, fifth, sixth );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third, fourth, fifth, sixth, seventh );
	}

	return array_memory_object;
}

template< class A_type, class A_creating_type >
template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
Amp< A_type > Constructor< A_type, A_creating_type >::construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw() {
	if ( an_allocator.is_empty() ) return Amp< A_type >();
	if ( quantity_of_objects.is_nill() ) return Amp< A_type >();

	Womp< Allocator > &non_const_allocator = const_cast< Womp< Allocator > & >( an_allocator );

	Amp< A_type > array_memory_object = Amp< A_type >::create(
		non_const_allocator->allocate_memory(
			typing::size_of< A_creating_type >() * quantity_of_objects,
			typing::alignment_of< A_creating_type >() ),
		quantity_of_objects,
		an_allocator,
		typing::alignment_of< A_creating_type >() );

	if ( array_memory_object.is_empty() ) return Amp< A_type >();

	A_type *pointer_to_object = array_memory_object.get_memory().take();

	for ( typing::Memory_size counter = quantity_of_objects; counter.is_not_nill(); --counter ) {
		::new ( reinterpret_cast< void * >( pointer_to_object++ ) ) A_type( first, second, third, fourth, fifth, sixth, seventh, eighth );
	}

	return array_memory_object;
}


// template< class A_type, class A_creating_type >
// Omp< A_type > ConstructDefault( const Womp< Allocator > &an_allocator ) {
// 	return Constructor< A_type, A_creating_type >::construct( anAllocator );
// }
// 
// template< class A_type, class A_creating_type >
// Omp< A_type > ConstructCopy( const Womp< Allocator > &an_allocator, const A_creating_type &original ) {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, original );
// }
// 
// template< class A_type, class A_creating_type >
// template< class A_first >
// Omp< A_type > Construct( const Womp< Allocator > &an_allocator, const A_first &first ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first );
// }
// 
// template< class A_type, class A_first, class A_second >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third, fourth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third, fourth, fifth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third, fourth, fifth, sixth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third, fourth, fifth, sixth, seventh );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
// Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct( an_allocator, first, second, third, fourth, fifth, sixth, seventh, eighth );
// }
// 
// 
// template< class A_type, class A_creating_type >
// Omp< A_type > construct_default_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects ) {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects );
// }
// 
// template< class A_type, class A_creating_type >
// Omp< A_type > construct_copy_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_creating_type &original ) {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, original );
// }
// 
// template< class A_type, class A_first >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first );
// }
// 
// template< class A_type, class A_first, class A_second >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third, fourth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third, fourth, fifth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third, fourth, fifth, sixth );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third, fourth, fifth, sixth, seventh );
// }
// 
// template< class A_type, class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
// Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, const typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &thrid, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw() {
// 	return Constructor< A_type, A_creating_type >::construct_as_array( an_allocator, quantityOfObjects, first, second, third, fourth, fifth, sixth, seventh, eighth );
// }


} // namespace memorying
} // namespace jmsf
