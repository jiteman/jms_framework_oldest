#pragma once


#include "Aso.hxx"


#include "Naturals.hxx"
#include "Boolean.hxx"
#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


// alignments
Memory_size align_up( Memory_size an_address, Memory_size an_alignment ) noexept;
Memory_size align_down( Memory_size an_address, Memory_size an_alignment ) noexept;
Memory_size get_alignment_up_value( Memory_size an_address, Memory_size an_alignment ) noexept;
Memory_size get_alignment_down_value( Memory_size an_address, Memory_size an_alignment ) noexept;
Boolean is_aligned( Memory_size an_address, Memory_size an_alignment ) noexept;
Boolean is_not_aligned( Memory_size an_address, Memory_size an_alignment ) noexept;
//~alignments


} // namespace typing
} // namespace jmsf
