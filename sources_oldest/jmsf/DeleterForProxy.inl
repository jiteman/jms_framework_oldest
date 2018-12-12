#pragma once


#include "DeleterForProxy.hpp"


namespace jmsf {


template< class A_type >
// static
void DeleterForProxy< A_type >::_deleteObject( const A_type *const object ) throw() {
//	delete debugging::static_ObjectDeletionLogger< A_type >::registerDeletion( object, sizeof( A_type ), MACROS_FILE_AND_LINE );
	if ( object != nullptr ) {
		object->_deleteThisIfReal();
	}
}

template< class A_type >
// static
A_type *DeleterForProxy< A_type >::getNull() throw() {
	return A_type::getNull();
}

template< class A_type >
DeleterForProxy< A_type >::DeleterForProxy() throw()
{}


} // namespace
