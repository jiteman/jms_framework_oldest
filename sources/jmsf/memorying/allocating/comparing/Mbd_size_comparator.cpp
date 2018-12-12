#include "Mbd_size_comparator.h"

#include "../Memory_block_descriptor.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Comparasion_result.h"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


typing::Comparasion_result Mbd_size_comparator::compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const noexept {
	return typing::Comparasion_result::create( first.get_size(), second.get_size() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mbd_size_comparator::~Mbd_size_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_comparator::Mbd_size_comparator() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_comparator::Mbd_size_comparator( const Mbd_size_comparator & ) noexept { // another
}

const Mbd_size_comparator &Mbd_size_comparator::operator =( const Mbd_size_comparator &another ) noexept {
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
