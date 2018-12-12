#pragma once


#include "../Allocator.h"

#include "jmsf/memorying/Womp.hpp"
#include "jmsf/typing/Naturals.hpp"

#include "Heap_status_descriptor.hxx"
#include "Pool_block_descriptor.hxx"
#include "Memory_block_descriptor.hxx"

#include "jmsf/memorying/Memory_pointer.hxx"

#include "jmsf/structing/noding/Doubly_linked_node.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {


// Allocates fixed sized ( sizeof( A_type ) ) blocks on the top of heap downwards
template< class A_type >
class Top_pool_allocator :
	public Allocator 
{

public:
	// virtuals
	Memory_pointer allocate_memory( typing::Memory_size a_size, typing::Memory_size an_alignment );
	void deallocate_memory( const Memory_pointer &a_memory, typing::Memory_size an_alignment );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Top_pool_allocator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Top_pool_allocator() noexept;

	Top_pool_allocator( const memorying::Womp< Heap_status_descriptor > &heap_status_descriptor ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Top_pool_allocator( const Top_pool_allocator &another ) noexept;
	const Top_pool_allocator &operator =( const Top_pool_allocator &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< Heap_status_descriptor > _heap_status_descriptor;
	typing::Memory_size _quantity_of_pool_blocks_allocated;
	typing::Memory_size _aligned_heap_end_address;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::Memory_size get_first_pool_block_address() noexept;
	typing::Memory_size get_pool_block_address( typing::Memory_size pool_block_index ) noexept;
	Memory_pointer get_empty_memory_block() noexept;	
	Womp< Pool_block_descriptor< A_type > > take_pool_block_with_empty_memory_block() noexept;
	Womp< Pool_block_descriptor< A_type > > create_new_pool_block() noexept;
	void release_unused_pool_block_descriptors( const Womp< Pool_block_descriptor< A_type >  > &pool_block_descriptor, typing::Memory_size pool_block_address ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static A_type *get_empty_object_memory_block( Womp< Pool_block_descriptor< A_type > > &pool_block_descriptor ) noexept;

};



} // namespace allocating
} // namespace memorying
} // namespace jmsf
