#pragma once


#include "internals/Base_for_pointer_and_proxy.inl"
#include "internals/Type_data.inl"
#include "internals/Pointer_deleter.inl"

#include "Pointer.hpp"
#include "Constant_pointer.inl"

#include "../memorying/Omp.inl"


//#include "DeleterForPointer.hpp"


namespace jmsf {
namespace pointing {


template< class A_type >
Pointer< A_type > Pointer< A_type >::get_nonlinked() const {
	return create_nonlinked_for( get() );
}

template< class A_type >
const Constant_pointer< A_type > Pointer< A_type >::get_nonlinked_constant() const {
	return Constant_pointer< A_type >::create_nonlinked_for( get() );
}

template< class A_type >
const Constant_pointer< A_type > Pointer< A_type >::take_constant() const {
	Constant_pointer< A_type > constantPointer;
	static_cast< internals::Base_for_both_constant_and_nonconstant< Pointer_deleter< A_type > > & >( constantPointer ) = 
		static_cast< const internals::Base_for_both_constant_and_nonconstant< Pointer_deleter< A_type > > & >( *this );
	return constantPointer;
}

template< class A_type >
const Pointer< A_type > Pointer< A_type >::get_as_shared( const memorying::Womp< memorying::Allocator > reference_counters_allocator ) const {
	Pointer< A_type > sharedPointer = Pointer< A_type >::create_none();
	static_cast< internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedPointer ) = createSharedFromThis( reference_counters_allocator );
	return sharedPointer;
}

template< class A_type >
Pointer< A_type > Pointer< A_type >::take_as_shared( const memorying::Womp< memorying::Allocator > reference_counters_allocator ) {
	Pointer< A_type > sharedPointer = Pointer< A_type >::create_none();
	static_cast< internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedPointer ) = createSharedFromThis( reference_counters_allocator );
	return sharedPointer;
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::create_none() {
	return Pointer< A_type >( type_None, nullptr );
}

template< class A_type >
Pointer< A_type > Pointer< A_type >::create_empty() {
	return Pointer< A_type >( type_Empty, nullptr );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject ) {
	return pointerToObject.is_empty() ? Pointer< A_type >( type_Empty, pointerToObject ) : Pointer< A_type >( type_Nonlinked, pointerToObject );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::create_unique( const memorying::Omp< A_type > &pointerToObject ) {
	return Pointer< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) {
	return Pointer< A_type >( reference_counters_allocator, pointerToObject );
}

template< class A_type >
Pointer< A_type >::Pointer() throw()
	:
		Base_for_pointer_and_proxy( type_Empty, memorying::Omp< A_type >() )
{}

template< class A_type >
Pointer< A_type >::Pointer( const typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject )
	:
		Base_for_pointer_and_proxy( type, pointerToObject )
{}

template< class A_type >
Pointer< A_type >::Pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject )
	:
		Base_for_pointer_and_proxy( reference_counters_allocator, type_Shared, pointerToObject )
{}


} // namespace pointing
} // namespace jmsf
