#include "Mbd_size_comparator.h"


#include "../Memory_block_descriptor.h"

#include "jmsf/assisting/Comparator.hin"
#include "jmsf/typeing/Comparasion_result.h"
#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


typeing::Comparasion_result Mbd_size_comparator::compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const noexcept {
	return typeing::Comparasion_result::create( first.get_size(), second.get_size() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Mbd_size_comparator::~Mbd_size_comparator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_comparator::Mbd_size_comparator() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Mbd_size_comparator::Mbd_size_comparator( const Mbd_size_comparator & ) noexcept { // another
}

const Mbd_size_comparator &Mbd_size_comparator::operator =( const Mbd_size_comparator &another ) noexcept {
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
