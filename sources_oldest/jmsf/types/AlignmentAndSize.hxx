#pragma once


#include "Natural.hxx"


namespace jmsf {
namespace types {


template< class A_type >
Natural AlignmentOf();

template< class A_type >
Natural AlignmentOf( const A_type & );

template< class A_type >
Natural SizeOf();

template< class A_type >
Natural SizeOf( const A_type & );

template< class A_type >
Natural BitSizeOf();

template< class A_type >
Natural BitSizeOf( const A_type & );


} // namespace types
} // namespace jmsf
