#pragma once


#include "Naturals.inl"


namespace jmsf {
namespace typing {


//~alignment
Memory_size align_up( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	const Memory_size the_alignment = an_alignment - Memory_size_one;
	return an_address + the_alignment & ~the_alignment;
}

Memory_size align_down( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	const Memory_size the_alignment = an_alignment - Memory_size_one;
	return an_address & ~the_alignment;
}

Memory_size get_alignment_up_value( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	return align_up( an_address, an_alignment ) - an_address;
}

Memory_size get_alignment_down_value( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	return an_address - align_down( an_address, an_alignment );
}

Boolean is_aligned( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	return ( an_address & ( an_alignment - Memory_size_one ) ).is_nill();
}

Boolean is_not_aligned( const Memory_size an_address, const Memory_size an_alignment ) noexept {
	return ( an_address & ( an_alignment - Memory_size_one ) ).is_not_nill();
}
//~alignment


} // namespace typing
} // namespace jmsf
