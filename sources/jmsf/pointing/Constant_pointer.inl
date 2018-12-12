#pragma once

#include "Constant_pointer.hpp"


#include "internals/Base_for_constant_pointer_and_constant_proxy.inl"
#include "internals/Type_data.inl"
#include "internals/Pointer_deleter.inl"


#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace pointing {


template< class A_type >
const Constant_pointer< A_type > Constant_pointer< A_type >::get_nonlinked() const {
	return create_nonlinked_for( get() );
}

// template< class A_type >
// const Constant_pointer< A_type > Constant_pointer< A_type >::getWeakConstant() const throw( validating::Exception ) {
// 	return Constant_pointer< A_type >( getWeak() );
// }

template< class A_type >
const Constant_pointer< A_type > Constant_pointer< A_type >::get_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator ) const  {
	Constant_pointer< A_type > sharedPointer = Constant_pointer< A_type >::create_none();
	static_cast< const internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedPointer ) = createSharedFromThis( reference_counters_allocator );
	return sharedPointer;
}

template< class A_type >
// static
const Constant_pointer< A_type > Constant_pointer< A_type >::create_none()  {
	return Constant_pointer< A_type >( type_None, nullptr );
}

template< class A_type >
const Constant_pointer< A_type > Constant_pointer< A_type >::create_empty()  {
	return Constant_pointer< A_type >( type_Empty, nullptr );
}

template< class A_type >
// static
const Constant_pointer< A_type > Constant_pointer< A_type >::create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject )  {
	return pointerToObject.is_empty() ? Constant_pointer< A_type >( type_Empty, pointerToObject ) : Constant_pointer< A_type >( type_Nonlinked, pointerToObject );
}

template< class A_type >
// static
const Constant_pointer< A_type > Constant_pointer< A_type >::create_unique( const memorying::Omp< A_type > &pointerToObject )  {
	return Constant_pointer< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
const Constant_pointer< A_type > Constant_pointer< A_type >::create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) {
	return Constant_pointer< A_type >( reference_counters_allocator, pointerToObject );
}

template< class A_type >
Constant_pointer< A_type >::Constant_pointer() noexept
	:
		Base_for_constant_pointer_and_constant_proxy( type_Empty, memorying::Omp< A_type >() )
{}

template< class A_type >
Constant_pointer< A_type >::Constant_pointer( const typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject ) 
	:
		Base_for_constant_pointer_and_constant_proxy( type, pointerToObject )
{}

template< class A_type >
Constant_pointer< A_type >::Constant_pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) 
	:
		Base_for_constant_pointer_and_constant_proxy( reference_counters_allocator, type_Shared, pointerToObject )
{}

} // namespace pointing
} // namespace jmsf
