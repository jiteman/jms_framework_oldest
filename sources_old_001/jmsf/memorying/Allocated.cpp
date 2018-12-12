#include "Allocated.h"


namespace jmsf {
namespace memorying {


const Allocator &Allocated::getAllocator() const noexcept {
	return *_theAllocator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Allocated::~Allocated() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Allocated::Allocated( const Allocator &anAllocator ) noexcept {
	_theAllocator = &anAllocator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Allocated::Allocated( const Allocated &another ) noexcept {
	_theAllocator = another._theAllocator;
}

const Allocated &Allocated::operator =( const Allocated &another ) noexcept {
	if ( &another == this ) return *this;

	_theAllocator = another._theAllocator;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
