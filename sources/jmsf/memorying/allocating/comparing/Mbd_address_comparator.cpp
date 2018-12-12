#include "Mbd_address_comparator.h"

#include "jmsf/assisting/Comparator.inl"

#include "../Memory_block_descriptor.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Comparasion_result.h"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


typing::Comparasion_result Mbd_address_comparator::compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const noexept {
	return typing::Comparasion_result::create( first.get_memory_block_address(), second.get_memory_block_address() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mbd_address_comparator::~Mbd_address_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_address_comparator::Mbd_address_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_address_comparator::Mbd_address_comparator( const Mbd_address_comparator & ) noexept { // another
}

const Mbd_address_comparator &Mbd_address_comparator::operator =( const Mbd_address_comparator &another ) noexept {
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
