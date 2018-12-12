#pragma once


#include "Allocator.h"


namespace jmsf {
namespace memorying {


class JMSF_DLL_INTERFACE temporary_Allocator :
	public Allocator
{

public:
	// virtuals Allocator
	Memory_pointer allocate_memory( typing::Memory_size a_size, typing::Memory_size an_alignment );
	void deallocate_memory( const Memory_pointer &a_memory, typing::Memory_size an_alignment );
	//~virtuals Allocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual Allocator
	~temporary_Allocator();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace memorying
} // namespace jmsf
