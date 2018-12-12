#pragma once


#include "jmsf/types.h"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace memory {


class NativeAllocator {

public:
	virtual natural_small *allocateMemory( natural_size sizeToAllocate ) throw( Exception ) = 0;
	virtual void deallocateMemory( const natural_small *memoryToDeallocate ) throw( Exception ) = 0;
	virtual natural_size getAllocationLimit() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ~NativeAllocator() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memory
} // namespace jmsf
