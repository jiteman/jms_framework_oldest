#pragma once

#include "MulObjectCreationInformation.hxx"
#include "MulObjectDeletionInformation.hxx"
#include "MulArrayCreationInformation.hxx"
#include "MulArrayDeletionInformation.hxx"

#include "jmsf/types/Natural.hxx"
#include "FileAndLine.hxx"


namespace jmsf {
namespace debugging {

template< class A_type >
MulObjectCreationInformation createMulInformationForObjectOrientedCreation( const A_type *object, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulObjectCreationInformation createMulInformationForUnobjectedCreation( const A_type *object, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulObjectCreationInformation createMulInformationForObjectedCreation( const A_type *object, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulObjectDeletionInformation createMulInformationForObjectDeletion( const A_type *object, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulArrayCreationInformation createMulInformationForArrayCreation( const A_type *object, types::Natural quantityOfObjects, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulArrayDeletionInformation createMulInformationForArrayDeletion( const A_type *object, const FileAndLine &fileAndLine ) throw();

template< class A_type >
MulArrayDeletionInformation createMulInformationForArrayDeletion( const A_type *object, types::Natural quantityOfObjects, const FileAndLine &fileAndLine ) throw();

} // namespace debugging
} // namespace jmsf


#include "MulObjectCreationInformation.h"
#include "MulObjectDeletionInformation.h"
#include "MulArrayCreationInformation.h"
#include "MulArrayDeletionInformation.h"
#include <typeinfo>


namespace jmsf {
namespace debugging {


template< class A_type >
MulObjectCreationInformation createMulInformationForObjectOrientedCreation( const A_type *const object, const FileAndLine &fileAndLine ) throw() {
	return MulObjectCreationInformation( reinterpret_cast< natural_size >( static_cast< const Object * >( object ) ), typeid( *object ).name(), sizeof( *object ), pathToFile, lineOfFile );
}

template< class A_type >
MulObjectCreationInformation createMulInformationForUnobjectedCreation( const A_type *object, const char_type *pathToFile, natural_size lineOfFile ) throw() {
	return MulObjectCreationInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), pathToFile, lineOfFile );
}

template< class A_type >
MulObjectCreationInformation createMulInformationForObjectedCreation( const A_type *const object, const char_type *const pathToFile, const natural_size lineOfFile ) throw() {
	return MulObjectCreationInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), pathToFile, lineOfFile );
}

template< class A_type >
MulObjectDeletionInformation createMulInformationForObjectDeletion( const A_type *const object, const char_type *const pathToFile, const natural_size lineOfFile ) throw() {
	return MulObjectDeletionInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), pathToFile, lineOfFile );
}

template< class A_type >
MulArrayCreationInformation createMulInformationForArrayCreation( const A_type *const object, const natural_size quantityOfObjects, const char_type *const pathToFile, const natural_size lineOfFile ) throw() {
	return MulArrayCreationInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), quantityOfObjects, pathToFile, lineOfFile );
}

template< class A_type >
MulArrayDeletionInformation createMulInformationForArrayDeletion( const A_type *const object, const char_type *const pathToFile, const natural_size lineOfFile ) throw() {
	return MulArrayDeletionInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), 0, pathToFile, lineOfFile );
}

template< class A_type >
MulArrayDeletionInformation createMulInformationForArrayDeletion( const A_type *object, const natural_size quantityOfObjects, const char_type *pathToFile, natural_size lineOfFile ) throw() {
	return MulArrayDeletionInformation( reinterpret_cast< natural_size >( object ), typeid( *object ).name(), sizeof( *object ), quantityOfObjects, pathToFile, lineOfFile );
}


} // namespace debugging
} // namespace jmsf
