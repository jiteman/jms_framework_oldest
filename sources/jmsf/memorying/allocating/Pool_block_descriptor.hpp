#pragma once


//#include "Memory_block_descriptor.h"

#include "jmsf/typing/Naturals.hpp"
#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/typing/Bitwise.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {


template< class A_type >
class Pool_block_descriptor {

	static const typing::memory_size_value_type _object_memory_block_quantity_constant = typing::MAXIMUM_INTEGRAL_BIT_SIZE;
	static const typing::Memory_size _block_size;
// #if defined( JMSF_64 )
// 		64;
// #elif defined( JMSF_32 )
// 		32;
// #else
// 	#error Pool_block_descriptor.h - neither of JMSF_32 or JMSF_64 is defined
// #endif
	
public:
//	typing::Memory_size get_usage_indicator() const noexept;
	typing::Memory_size get_first_free_index() const noexept;
	typing::Boolean is_not_used() const noexept;
	typing::Boolean is_not_full() const noexept;
	typing::Boolean is_used( typing::Memory_size object_memory_block_index ) const;
	typing::Boolean is_free( typing::Memory_size object_memory_block_index ) const;
	const A_type *get_object_memory_block_by( typing::Shortest_natural object_memory_block_index ) const noexept;
	typing::Memory_size get_object_memory_block_index( const A_type *object_memory_block ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	void set_usage_indicator( typing::Memory_size using_indicator ) noexept;
	void set_as_used( typing::Memory_size object_memory_block_index );
	void set_as_free( typing::Memory_size object_memory_block_index );
	A_type *take_object_memory_block_by( typing::Memory_size object_memory_block_index ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static typing::Memory_size get_max_quantity_of_desctriptors() noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Pool_block_descriptor() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pool_block_descriptor() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pool_block_descriptor( const Pool_block_descriptor &another ) noexept;
	const Pool_block_descriptor &operator =( const Pool_block_descriptor &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Memory_size _usage_indicator;

	A_type _object_memory_blocks[ _object_memory_block_quantity_constant ];

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::Bitwise< typing::Memory_size > get_bitwise_usage_indicator() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:


};


} // namespace allocating
} // namespace memorying
} // namespace jmsf
