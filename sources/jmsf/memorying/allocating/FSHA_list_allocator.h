#pragma once


#include "../Allocator.h"

#include "jmsf/structing/containing/List.hpp"
#include "jmsf/structing/traversing/List_traverser.hpp"
#include "Fixed_size_heap_allocator.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {


class FSHA_list_allocator :
	public Allocator
{

public:
	// virtuals Allocator
	Memory_pointer allocate_memory( typing::Memory_size a_size, typing::Memory_size an_alignment );
	void deallocate_memory( const Memory_pointer &a_memory, typing::Memory_size an_alignment );
	//~virtuals Allocator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Allocator
	~FSHA_list_allocator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	FSHA_list_allocator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	FSHA_list_allocator( const FSHA_list_allocator &another ) noexept;
	const FSHA_list_allocator &operator =( const FSHA_list_allocator &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	structing::containing::List< Fixed_size_heap_allocator > _fsha_list;
	structing::traversing::List_traverser< Fixed_size_heap_allocator > _last_successfull_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
