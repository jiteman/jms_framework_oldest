#pragma once


#include "AlignmentAndSize.hpp"

#include "Natural.h"


namespace jmsf {
namespace types {


// alignment
#if defined( _MSC_VER ) && ( _MSC_VER >= 1300 ) // If VC7.0 or later...

	template< class A_type >
	Natural AlignmentOf() {
		return Natural::create( __alignof( A_type ) );
	}

	template< class A_type >
	Natural AlignmentOf( const A_type & ) { // anObject
		return Natural::create( __alignof( A_type ) );
	}

#elif defined( __GNUC__ ) || defined( __MWERKS__ )

	template< class A_type >
	Natural AlignmentOf() {
		return Natural::create( __alignof__( A_type ) );
	}

	template< class A_type >
	Natural AlignmentOf( const A_type & ) { // anObject
		return Natural::create( __alignof__( A_type ) );
	}

#else

	template< typename A_type >
	struct JMSFAlignOfTemplate {
		struct AlightStruct {
			char charMember;
			A_type typeMember;
		};

		static const size_t alignValue = ( size_t )( ( char * ) &( ( struct AlightStruct * )0 )->typeMember - ( char * )0 );
	};

	template< class A_type >
	Natural AlignmentOf() {
		return Natural::create( JMSFAlignOfTemplate< type >::alignValue );
	}

	template< class A_type >
	Natural AlignmentOf( const A_type & ) { // anObject
		return Natural::create( JMSFAlignOfTemplate< type >::alignValue );
	}

#endif


template< class A_type >
Natural SizeOf() {
	return Natural::create( sizeof( A_type ) );
}

template< class A_type >
Natural SizeOf( const A_type & ) { // anObject
	return Natural::create( sizeof( A_type ) );
}

template< class A_type >
ShortestNatural BitSizeOf() {
	return ShortestNatural::create( static_cast< internals::types::platform_unsigned_int >( CHAR_BIT_SIZE ) * sizeof( A_type ) );
}

template< class A_type >
ShortestNatural BitSizeOf( const A_type & ) { // anObject
	return ShortestNatural::create( static_cast< internals::types::platform_unsigned_int >( CHAR_BIT_SIZE ) * sizeof( A_type ) );
}


} // namespace types
} // namespace jmsf
