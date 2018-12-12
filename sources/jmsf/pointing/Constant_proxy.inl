#pragma once


#include "Constant_proxy.hpp"

#include "internals/Base_for_constant_pointer_and_constant_proxy.inl"
#include "internals/Type_data.inl"
#include "internals/Proxy_deleter.inl"


namespace jmsf {
namespace pointing {


template< class A_type >
const Constant_proxy< A_type > Constant_proxy< A_type >::get_nonlinked() const {
	return create_nonlinked_for( get() );
}

// template< class A_type >
// const Constant_proxy< A_type > Constant_proxy< A_type >::getWeakConstant() const {
// 	return Constant_proxy< A_type >::create_nonlinked_for( get() );
// }

template< class A_type >
const Constant_proxy< A_type > Constant_proxy< A_type >::get_as_shared( const memorying::Womp< memorying::Allocator > reference_counters_allocator ) const {
	Constant_proxy< A_type > sharedProxy = Constant_proxy< A_type >::create_none();
	static_cast< const internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedProxy ) = createSharedFromThis( reference_counters_allocator );
	return sharedProxy;
}

// static
template< class A_type >
Constant_proxy< A_type > Constant_proxy< A_type >::create_none() {
	return Constant_proxy< A_type >( type_None, nullptr );
}

// static
template< class A_type >
Constant_proxy< A_type > Constant_proxy< A_type >::create_empty() {
	return Constant_proxy< A_type >( type_Empty, A_type::get_null() );
}

// static
template< class A_type >
Constant_proxy< A_type > Constant_proxy< A_type >::create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject ) {
	if ( pointerToObject.is_empty() ) {
		return Constant_proxy< A_type >( type_None, pointerToObject );
	} else if ( pointerToObject.get_memory()->is_null() ) {
		return Constant_proxy< A_type >( type_Empty, pointerToObject );
	} else {
		return Constant_proxy< A_type >( type_Nonlinked, pointerToObject );
	}
}

// static
template< class A_type >
Constant_proxy< A_type > Constant_proxy< A_type >::create_unique( const memorying::Omp< A_type > &pointerToObject ) {
	return Constant_proxy< A_type >( type_Unique, pointerToObject );
}

// static
template< class A_type >
Constant_proxy< A_type > Constant_proxy< A_type >::create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) {
	return Constant_proxy< A_type >( reference_counters_allocator, pointerToObject );
}

template< class A_type >
Constant_proxy< A_type >::Constant_proxy() noexept
	:
		Base_for_constant_pointer_and_constant_proxy( type_Empty, A_type::getNull().get() )
{}

template< class A_type >
Constant_proxy< A_type >::Constant_proxy( const typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject )
	:
		Base_for_constant_pointer_and_constant_proxy( type, pointerToObject )
{}

template< class A_type >
Constant_proxy< A_type >::Constant_proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject )
	:
		Base_for_constant_pointer_and_constant_proxy( reference_counters_allocator, pointerToObject )
{}


} // namespace internals
} // namespace jmsf
