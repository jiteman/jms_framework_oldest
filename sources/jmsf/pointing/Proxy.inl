#pragma once


#include "Proxy.hpp"

#include "internals/Base_for_pointer_and_proxy.inl"
#include "internals/Type_data.inl"
#include "internals/Proxy_deleter.inl"

#include "Constant_proxy.inl"


namespace jmsf {
namespace pointing {


template< class A_type >
Proxy< A_type > Proxy< A_type >::get_nonlinked() const {
	return create_nonlinked_for( get() );
}

template< class A_type >
const Constant_proxy< A_type > Proxy< A_type >::get_nonlinked_constant() const {
	return Constant_proxy< A_type >::create_nonlinked_for( get() );
}

template< class A_type >
const Constant_proxy< A_type > Proxy< A_type >::take_constant() const {
	Constant_proxy< A_type > constantProxy = Constant_proxy< A_type >::create_none();
	static_cast< internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( constantProxy ) = 
		static_cast< const internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( *this );
	return constantProxy;
}

template< class A_type >
const Proxy< A_type > Proxy< A_type >::get_as_shared( const memorying::Womp< memorying::Allocator > reference_counters_allocator ) const {
	Proxy< A_type > sharedProxy = Proxy< A_type >::create_none();
	static_cast< internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedProxy ) = createSharedFromThis( reference_counters_allocator );
	return sharedProxy;
}

template< class A_type >
Proxy< A_type > Proxy< A_type >::take_as_shared( const memorying::Womp< memorying::Allocator > reference_counters_allocator ) {
	Proxy< A_type > sharedProxy = Proxy< A_type >::create_none();
	static_cast< internals::Base_for_both_constant_and_nonconstant< Proxy_deleter< A_type > > & >( sharedProxy ) = createSharedFromThis( reference_counters_allocator );
	return sharedProxy;
}

// static
template< class A_type >
Proxy< A_type > Proxy< A_type >::create_none() {
	return Proxy< A_type >( type_None, nullptr );
}

template< class A_type >
Proxy< A_type > Proxy< A_type >::create_empty() {
	return Proxy< A_type >( type_Empty, A_type::get_null() );
}

// static
template< class A_type >
Proxy< A_type > Proxy< A_type >::create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject ) {
	if ( pointerToObject.is_empty() ) {
		return Proxy< A_type >( type_None, pointerToObject );
	} else if ( pointerToObject.get_memory()->is_null() ) {
		return Proxy< A_type >( type_Empty, pointerToObject );
	} else {
		return Proxy< A_type >( type_Nonlinked, pointerToObject );
	}
}

// static
template< class A_type >
Proxy< A_type > Proxy< A_type >::create_unique( const memorying::Omp< A_type > &pointerToObject ) {
	return Proxy< A_type >( type_Unique, pointerToObject );
}

// static
template< class A_type >
Proxy< A_type > Proxy< A_type >::create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) {
	return Proxy< A_type >( reference_counters_allocator, pointerToObject );
}

template< class A_type >
Proxy< A_type >::Proxy() throw()
	:
		Base_for_pointer_and_proxy( type_Empty, A_type::get_null() )
{}

// template< class A_type >
// Proxy< A_type >::Proxy< A_type >( const Proxy< A_type > &other ) {
// 
// }
// 
// template< class A_type >
// const Proxy< A_type > &Proxy< A_type >::operator =( const Proxy< A_type > &other ) {
// }

template< class A_type >
Proxy< A_type >::Proxy( const typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject ) throw( validating::Exception )
	:
		Base_for_pointer_and_proxy( type, pointerToObject )
{}

template< class A_type >
Proxy< A_type >::Proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject ) throw( validating::Exception )
	:
		Base_for_pointer_and_proxy( reference_counters_allocator, pointerToObject )
{}

} // namespace pointing
} // namespace jmsf
