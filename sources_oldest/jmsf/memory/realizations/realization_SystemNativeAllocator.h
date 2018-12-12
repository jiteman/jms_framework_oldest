#pragma once


#include "../NativeAllocator.h"


namespace jmsf {
namespace memory {
namespace realizations {


class realization_SystemNativeAllocator :
	public NativeAllocator
{

public:
	// virtual NativeAllocator
	natural_small *allocateMemory( natural_size sizeToAllocate ) throw( Exception );
	void deallocateMemory( const natural_small *memoryToDeallocate ) throw( Exception );
	natural_size getAllocationLimit() const throw();
	//~virtual NativeAllocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~realization_SystemNativeAllocator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_SystemNativeAllocator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_SystemNativeAllocator( const realization_SystemNativeAllocator &other ) throw();
	const realization_SystemNativeAllocator &operator =( const realization_SystemNativeAllocator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const natural_size ALLOCATION_LIMIT;

};


} // namespace realizations
} // namespace memory
} // namespace jmsf
