#include "realization_SystemNativeAllocator.h"

#include "jmsf/Exception.h"

#include <malloc.h>


namespace jmsf {
namespace memory {
namespace realizations {


natural_small *realization_SystemNativeAllocator::allocateMemory( const natural_size sizeToAllocate ) throw( Exception ) {
	if ( sizeToAllocate > ALLOCATION_LIMIT ) {
		// throw; allocation limit exceeded
	}

	natural_small *allocatedMemory = nullptr;
	allocatedMemory = reinterpret_cast< natural_small * >( ::malloc( sizeToAllocate ) );

	if ( allocatedMemory == nullptr ) {
		// throw; memory limit is exceeded
	}

	return allocatedMemory;
}

void realization_SystemNativeAllocator::deallocateMemory( const natural_small *const memoryToDeallocate ) throw( Exception ) {
	if ( memoryToDeallocate == nullptr ) return;

	::free( reinterpret_cast< void * >( const_cast< natural_small * >( memoryToDeallocate ) ) );
}

natural_size realization_SystemNativeAllocator::getAllocationLimit() const throw() {
	return ALLOCATION_LIMIT;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_SystemNativeAllocator::~realization_SystemNativeAllocator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_SystemNativeAllocator::realization_SystemNativeAllocator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_SystemNativeAllocator::realization_SystemNativeAllocator( const realization_SystemNativeAllocator & ) throw() { // other
}

const realization_SystemNativeAllocator &realization_SystemNativeAllocator::operator =( const realization_SystemNativeAllocator &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const natural_size realization_SystemNativeAllocator::ALLOCATION_LIMIT = 64 * 1024 * 1024;

} // namespace realizations
} // namespace memory
} // namespace jmsf
