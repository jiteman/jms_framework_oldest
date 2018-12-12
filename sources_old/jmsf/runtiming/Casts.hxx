#pragma once


#include "jmsf/texting/TextString.hxx"
#include "jmsf/pointing/ConstantPointer.hxx"
#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"


namespace jmsf {
namespace runtiming {


template< class A_derived_type, class A_base_type_with_placeholder >
const pointing::ConstantPointer< A_derived_type > constantDowncast( const A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames );

template< class A_derived_type, class A_base_type_with_placeholder >
pointing::Pointer< A_derived_type > downcast( A_base_type_with_placeholder &baseObject, const pointing::ConstantProxy< texting::TextString > &typenames );

template< class A_target_type, class A_source_type_with_placeholder >
const pointing::ConstantPointer< A_target_type > constantAdjacentCast( const A_source_type_with_placeholder &sourceObject );

template< class A_target_type, class A_base_type_with_placeholder >
pointing::Pointer< A_target_type > adjacentCast( A_base_type_with_placeholder sourceObject );


} // namespace runtiming
} // namespace jmsf
