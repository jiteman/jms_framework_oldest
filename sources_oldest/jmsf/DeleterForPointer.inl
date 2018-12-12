#pragma once


#include "DeleterForPointer.hpp"

#include "debugging/ObjectDeletionLogging.h"


namespace jmsf {


// static
template< class A_type >
void DeleterForPointer< A_type >::_deleteObject( const A_type *const object ) throw() {
	debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( object, MACROS_FILE_AND_LINE ) );
	delete object;
}

// static
template< class A_type >
A_type *DeleterForPointer< A_type >::getNull() throw() {
	return nullptr;
}

template< class A_type >
DeleterForPointer< A_type >::DeleterForPointer() throw()
{}


} // namespace jmsf
