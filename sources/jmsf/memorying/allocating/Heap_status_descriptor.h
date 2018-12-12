#pragma once


#include "jmsf/typing/Naturals.hpp"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {
namespace allocating {


class Heap_status_descriptor {

public:
	typing::Memory_size get_memory_heap_start() const noexept;
	typing::Memory_size get_memory_heap_end() const noexept;
	typing::Memory_size get_memory_heap_size() const noexept;
	typing::Memory_size get_middle_block_start() const noexept;
	typing::Memory_size get_middle_block_end() const noexept;
	typing::Memory_size get_middle_block_size() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void set_middle_block_start( typing::Memory_size an_address );
	void set_middle_block_end( typing::Memory_size an_address );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Heap_status_descriptor() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Heap_status_descriptor() noexept;

	Heap_status_descriptor( typing::Memory_size memory_heap_start, typing::Memory_size memory_heap_size ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Heap_status_descriptor( const Heap_status_descriptor &another ) noexept;
	const Heap_status_descriptor &operator =( const Heap_status_descriptor &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Memory_size _memory_heap_start;
	typing::Memory_size _memory_heap_end;
	typing::Memory_size _middle_block_start;
	typing::Memory_size _middle_block_end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
