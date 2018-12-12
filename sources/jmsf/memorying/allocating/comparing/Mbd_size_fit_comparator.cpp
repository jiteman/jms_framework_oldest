#include "Mbd_size_fit_comparator.h"

#include "../Memory_block_descriptor.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Comparasion_result.h"

#include "jmsf/typing/Aso.h"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


typing::Comparasion_result Mbd_size_fit_comparator::compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const noexept {
	const typing::Memory_size address_of_the_block = second.get_memory_block_address();
	const typing::Memory_size size_of_the_block = second.get_size();
	const typing::Memory_size size_to_allocate = first.get_size();
	const typing::Memory_size an_alignment = first.get_returned_address(); // - first.get_memory_block_address();

	const typing::Memory_size new_start_address = typing::align_up( address_of_the_block, an_alignment );
	const typing::Memory_size total_size_to_allocate = size_to_allocate + ( new_start_address - address_of_the_block );

	return typing::Comparasion_result::create( size_to_allocate, total_size_to_allocate );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mbd_size_fit_comparator::~Mbd_size_fit_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_fit_comparator::Mbd_size_fit_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_fit_comparator::Mbd_size_fit_comparator( const Mbd_size_fit_comparator & ) noexept { // another
}

const Mbd_size_fit_comparator &Mbd_size_fit_comparator::operator =( const Mbd_size_fit_comparator &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace comparing
} // namespace allocating
} // namespace memorying
} // namespace jmsf
