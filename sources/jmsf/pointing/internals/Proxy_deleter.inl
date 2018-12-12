#pragma once


#include "Proxy_deleter.hpp"
#include "jmsf/memorying/Omp.inl"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/memorying/Destructor.inl"


namespace jmsf {
namespace pointing {
namespace internals {

// static
template< class A_type >
void Proxy_deleter< A_type >::delete_object( const memorying::Omp< A_type > &object_memory_pointer ) throw() {
	const A_type *the_object = object_memory_pointer.get();

	if ( the_object != nullptr ) {
		if ( the_object->is_null().or( the_object->is_exception() ) ) return;

		memorying::Destructor< A_type >::destruct( object_memory_pointer );
	}
}

// static
template< class A_type >
memorying::Womp< A_type > Proxy_deleter< A_type >::get_null_object_via_deleter() throw() {
	return A_type::get_null_object();
}

template< class A_type >
Proxy_deleter< A_type >::Proxy_deleter() throw()
{}


} // namespace internals
} // namespace pointing
} // jmsf
