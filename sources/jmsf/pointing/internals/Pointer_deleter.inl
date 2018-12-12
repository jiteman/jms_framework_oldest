#pragma once


#include "Pointer_deleter.hpp"

//#include "debugging/ObjectDeletionLogging.h"
#include "../../memorying/Destructor.inl"


namespace jmsf {
namespace pointing {
namespace internals {


// static
template< class A_type >
void Pointer_deleter< A_type >::delete_object( const memorying::Omp< A_type > &object ) throw() {
	memorying::Destructor< A_type >::destruct( object );
}

// static
template< class A_type >
memorying::Womp< A_type > Pointer_deleter< A_type >::get_null_object_via_deleter() throw() {
	return memorying::Womp< A_type >();
}

template< class A_type >
Pointer_deleter< A_type >::Pointer_deleter() throw()
{}


} // namespace internals
} // namespace pointing
} // namespace jmsf
