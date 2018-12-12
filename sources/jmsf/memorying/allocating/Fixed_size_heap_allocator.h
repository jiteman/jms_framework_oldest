#pragma once


#include "../Allocator.h"

#include "jmsf/typing/Naturals.hpp"

#include "Heap_status_descriptor.h"
#include "Top_pool_allocator.hpp"

#include "Memory_block_descriptor.hxx"
#include "jmsf/structing/noding/Doubly_linked_node.hxx"
#include "jmsf/structing/containing/List.hpp"


namespace jmsf {
namespace memorying {
namespace allocating {


//class Memory_block_descriptor;


// Maintains fixed size heap (used for stack allocated memory or as granularity member of variable size heap maintainer)
class Fixed_size_heap_allocator :
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
	~Fixed_size_heap_allocator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixed_size_heap_allocator( const Memory_pointer &memory_heap, typing::Memory_size heap_size );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Fixed_size_heap_allocator( const Fixed_size_heap_allocator &another ) noexept;
	const Fixed_size_heap_allocator &operator =( const Fixed_size_heap_allocator &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Heap_status_descriptor _heap_status_descriptor;
	Top_pool_allocator< structing::noding::Doubly_linked_node< Memory_block_descriptor > > _list_nodes_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	structing::containing::List< Memory_block_descriptor > _empty_memory_list_sorted_by_address;
	structing::containing::List< Memory_block_descriptor > _empty_memory_list_sorted_by_size;
	structing::containing::List< Memory_block_descriptor > _used_memory_list;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Memory_pointer tryToAllocateMemory( typing::Memory_size size_to_allocate, typing::Memory_size an_alignment ) noexept;
	void consolidate_and_add( const Memory_block_descriptor &new_empty_memory_block ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typing::Boolean isFit( typing::Memory_size address_of_the_block, typing::Memory_size size_of_the_block, typing::Memory_size size_to_allocate, typing::Memory_size an_alignment ) noexept;

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
