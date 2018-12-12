#pragma once

#include "exceptions/exception_BadDynamicCast.h"
#include "factory_TextObject.h"
#include "TextString.h"


namespace jmsf {


template< class A_derived_type, class A_base_type_with_placeholder >
const ConstantPointer< A_derived_type > constantDowncast( const A_base_type_with_placeholder &baseObject, const ConstantProxy< TextString > &typenames ) {
	ConstantPointer< A_derived_type > derivedObject;

	try {
		derivedObject = ConstantPointer< A_derived_type >::createNonlinkedFor( &dynamic_cast< const A_derived_type & >( *baseObject ) );
	} catch ( ... ) {
		throw exceptions::exception_BadDynamicCast( typenames );
	}

	return derivedObject;
}

template< class A_derived_type, class A_base_type_with_placeholder >
Pointer< A_derived_type > downcast( A_base_type_with_placeholder &baseObject, const ConstantProxy< TextString > &typenames ) {
	Pointer< A_derived_type > derivedObject;

	try {
		derivedObject = Pointer< A_derived_type >::createNonlinkedFor( &dynamic_cast< A_derived_type & >( *baseObject ) );
	} catch ( ... ) {
		throw exceptions::exception_BadDynamicCast( typenames );
	}

	return derivedObject;
}

template< class A_target_type, class A_source_type_with_placeholder >
const ConstantPointer< A_target_type > constantAdjacentCast( const A_source_type_with_placeholder &sourceObject ) {
	return ConstantPointer< A_target_type >::createNonlinkedFor( &static_cast< const A_target_type & >( *sourceObject ) );
}

template< class A_target_type, class A_base_type_with_placeholder >
Pointer< A_target_type > adjacentCast( A_base_type_with_placeholder sourceObject ) {
	return Pointer< A_target_type >::createNonlinkedFor( &static_cast< A_target_type & >( *sourceObject ) );
}


} // namespace
