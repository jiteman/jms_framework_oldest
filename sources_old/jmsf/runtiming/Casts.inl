#pragma once


#include "jmsf/texting/TextString.h"
#include "jmsf/pointing/ConstantPointer.inl"
#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/ConstantProxy.inl"

#include "exceptions/exception_BadDynamicCast.h"
#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/texting/TextString.h"


namespace jmsf {
namespace runtiming {


template< class A_derived_type, class A_base_type_with_placeholder >
const pointing::ConstantPointer< A_derived_type > constantDowncast( const A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames ) {
	pointing::ConstantPointer< A_derived_type > derivedObject;

	try {
		derivedObject = pointing::ConstantPointer< A_derived_type >::createNonlinkedFor( &dynamic_cast< const A_derived_type & >( *baseObject ) );
	} catch ( ... ) {
		throw exceptions::exception_BadDynamicCast( typenames, FILE_AND_LINE );
	}

	return derivedObject;
}

template< class A_derived_type, class A_base_type_with_placeholder >
pointing::Pointer< A_derived_type > downcast( A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames ) {
	pointing::Pointer< A_derived_type > derivedObject;

	try {
		derivedObject = pointing::Pointer< A_derived_type >::createNonlinkedFor( &dynamic_cast< A_derived_type & >( *baseObject ) );
	} catch ( ... ) {
		throw exceptions::exception_BadDynamicCast( typenames, FILE_AND_LINE );
	}

	return derivedObject;
}

template< class A_target_type, class A_source_type_with_placeholder >
const pointing::ConstantPointer< A_target_type > constantAdjacentCast( const A_source_type_with_placeholder &sourceObject ) {
	return pointing::ConstantPointer< A_target_type >::createNonlinkedFor( &static_cast< const A_target_type & >( *sourceObject ) );
}

template< class A_target_type, class A_base_type_with_placeholder >
pointing::Pointer< A_target_type > adjacentCast( A_base_type_with_placeholder sourceObject ) {
	return pointing::Pointer< A_target_type >::createNonlinkedFor( &static_cast< A_target_type & >( *sourceObject ) );
}


} // namespace runtiming
} // namespace jmsf
