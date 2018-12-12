#pragma once


#include "Aso.hxx"


#include "Naturals.hxx"
#include "Boolean.hxx"
#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


// alignments
template< class A_type >
Memory_size alignment_of() noexept;

// template< class A_type >
// Memory_size alignment_of( const A_type & )noexept;

template< class A_type >
Memory_size align_up( Memory_size an_address ) noexept;

template< class A_type >
Memory_size align_down( Memory_size an_address ) noexept;

template< class A_type >
Memory_size get_alignment_up_value( Memory_size an_address ) noexept;

template< class A_type >
Memory_size get_alignment_down_value( Memory_size an_address ) noexept;

template< class A_type >
Boolean is_aligned( Memory_size an_address ) noexept;

template< class A_type >
Boolean is_not_aligned( Memory_size an_address ) noexept;
//~alignments


// size of
template< class A_type >
Memory_size size_of() noexept;

// template< class A_type >
// Memory_size size_of( const A_type & );
//~size of


// bits
template< class A_type >
Memory_size _bit_size_of() noexept;

// template< class A_type >
// Memory_size bit_size_of( const A_type & );
//~bits


} // namespace typing
} // namespace jmsf
