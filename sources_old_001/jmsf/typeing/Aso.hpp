#pragma once

#include "Aso.hxx"


#include "Naturals.hxx"
#include "Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace typeing {


// alignments
template< class A_type >
Memory_natural alignment_of() noexcept;

// template< class A_type >
// Memory_natural alignment_of( const A_type & )noexcept;

template< class A_type >
Memory_natural align_up( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural align_down( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural get_alignment_up_value( Memory_natural an_address ) noexcept;

template< class A_type >
Memory_natural get_alignment_down_value( Memory_natural an_address ) noexcept;

template< class A_type >
Boolean is_aligned( Memory_natural an_address ) noexcept;

template< class A_type >
Boolean is_not_aligned( Memory_natural an_address ) noexcept;
//~alignments


// size of
template< class A_type >
Memory_natural size_of() noexcept;

// template< class A_type >
// Memory_natural size_of( const A_type & );
//~size of


// bits
template< class A_type >
Memory_natural _bit_size_of() noexcept;

// template< class A_type >
// Memory_natural bit_size_of( const A_type & );
//~bits


} // namespace typeing
} // namespace jmsf
