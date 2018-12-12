#pragma once


//#include "jmsf/typing/ShortestNatural.h"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/memorying/Memory_pointer.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {
namespace allocating {


// static const typing::ShortestNatural MEMORY_BLOCK_TYPE_LIMIT = typing::ShortestNatural::create( 3 );


class Memory_block_descriptor {

// public:
// 	static const typing::ShortestNatural type_empty_constant;
// 	static const typing::ShortestNatural type_empty_memory_constant;
// 	static const typing::ShortestNatural type_used_memory_constant;

public:
	typing::Memory_size get_memory_block_address() const noexept;
	typing::Memory_size get_returned_address() const noexept;
//	typing::ShortestNatural get_type() const noexept;
// 	Memory_pointer take_memory_block() noexept;
// 	Memory_pointer take_returned_address() noexept;
	typing::Memory_size get_size() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	void set_type( typing::ShortestNatural aType ) noexept;
// 	void set_memory_block( Memory_pointer memoryBlock ) noexept;
// 	void set_returned_address( Memory_pointer returnedAddress ) noexept;
	void set_memory_block_address( typing::Memory_size memoryBlock ) noexept;
	void set_returned_address( typing::Memory_size returnedAddress ) noexept;
	void set_size( typing::Memory_size a_size ) noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Memory_block_descriptor() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_block_descriptor() noexept;

	Memory_block_descriptor( typing::Memory_size memory_block_address, typing::Memory_size returned_address, typing::Memory_size a_size ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_block_descriptor( const Memory_block_descriptor &another ) noexept;
	const Memory_block_descriptor &operator =( const Memory_block_descriptor &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	typing::ShortestNatural _type;
//	Memory_pointer _memory_block;
//	Memory_pointer _returned_address;
	typing::Memory_size _memory_block_address;
	typing::Memory_size _returned_address;
	typing::Memory_size _the_size;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
