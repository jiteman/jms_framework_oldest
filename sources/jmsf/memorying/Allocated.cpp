#include "Allocated.h"


namespace jmsf {
namespace memorying {


const Allocator &Allocated::getAllocator() const throw() {
	return *_theAllocator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Allocated::~Allocated() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Allocated::Allocated( const Allocator &anAllocator ) throw() {
	_theAllocator = &anAllocator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Allocated::Allocated( const Allocated &another ) throw() {
	_theAllocator = another._theAllocator;
}

const Allocated &Allocated::operator =( const Allocated &another ) throw() {
	if ( &another == this ) return *this;

	_theAllocator = another._theAllocator;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
