#pragma once


#include "Aso.hpp"

#include "Naturals.inl"
#include "Aso.h"


#include "internals/internal_types.h"


namespace jmsf {
namespace typing {


// alignment
#if defined( _MSC_VER ) && ( _MSC_VER >= 1300 ) // If VC7.0 or later...

	template< class A_type >
	Memory_size alignment_of() noexept {
		return Memory_size::create( __alignof( A_type ) );
	}

// 	template< class A_type >
// 	Memory_size alignment_of( const A_type & ) { // anObject
// 		return Memory_size::create( __alignof( A_type ) );
// 	}

#elif defined( __GNUC__ ) || defined( __MWERKS__ )

	template< class A_type >
	Memory_size alignment_of() noexept {
		return Memory_size::create( __alignof__( A_type ) );
	}

// 	template< class A_type >
// 	Memory_size alignment_of( const A_type & ) { // anObject
// 		return Memory_size::create( __alignof__( A_type ) );
// 	}

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
	Memory_size alignment_of() noexept {
		return Memory_size::create( JMSFAlignOfTemplate< A_type >::alignValue );
	}

// 	template< class A_type >
// 	Memory_size alignment_of( const A_type & ) { // anObject
// 		return Memory_size::create( JMSFAlignOfTemplate< A_type >::alignValue );
// 	}

#endif

template< class A_type >
Memory_size align_up( const Memory_size an_address ) noexept {
	return align_up( an_address, alignment_of< A_type >() );
}

template< class A_type >
Memory_size align_down( const Memory_size an_address ) noexept {
	return align_down( an_address, alignment_of< A_type >() );
}

template< class A_type >
Memory_size get_alignment_up_value( const Memory_size an_address ) noexept {
	return get_alignment_up_value( an_address, alignment_of< A_type >() );
}

template< class A_type >
Memory_size get_alignment_down_value( const Memory_size an_address ) noexept {
	return get_alignment_down_value( an_address, alignment_of< A_type >() );
}

template< class A_type >
Boolean is_aligned( const Memory_size an_address ) noexept {
	return is_aligned( an_address, alignment_of< A_type >() );
}

template< class A_type >
Boolean is_not_aligned( const Memory_size an_address ) noexept {
	return is_not_aligned( an_address, alignment_of< A_type >() );
}

//~alignment


// size of
template< class A_type >
Memory_size size_of() noexept {
	return Memory_size::create( sizeof( A_type ) );
}

// template< class A_type >
// Memory_size size_of( const A_type & ) { // anObject
// 	return Memory_size::create( sizeof( A_type ) );
// }
//~size of


// bits
template< class A_type >
Memory_size _bit_size_of() noexept {
	return Memory_size::create( CHAR_BIT_SIZE * sizeof( A_type ) );
}

// template< class A_type >
// Memory_size bit_size_of( const A_type & ) { // anObject
// 	return Memory_size::create( static_cast< internals::typing::platform_unsigned_int >( CHAR_BIT_SIZE ) * sizeof( A_type ) );
// }
//~bits


} // namespace typing
} // namespace jmsf
