#include "Memory_block_descriptor.h"


namespace jmsf {
namespace memorying {
namespace allocating {


// statics
// const typing::ShortestNatural Memory_block_descriptor::type_empty_constant = typing::ShortestNaturalZero;
// const typing::ShortestNatural Memory_block_descriptor::type_empty_memory_constant = typing::ShortestNaturalOne;
// const typing::ShortestNatural Memory_block_descriptor::type_used_memory_constant = typing::ShortestNaturalTwo;
//~statics


// typing::ShortestNatural Memory_block_descriptor::get_type() const noexept {
// 	return _type;
// }

typing::Memory_size Memory_block_descriptor::get_memory_block_address() const noexept {
	return _memory_block_address;
}

typing::Memory_size Memory_block_descriptor::get_returned_address() const noexept {
	return _returned_address;
}

// Memory_pointer Memory_block_descriptor::take_memory_block() noexept {
// 	return _memory_block;
// }
// 
// Memory_pointer Memory_block_descriptor::take_returned_address() noexept {
// 	return _returned_address;
// }

typing::Memory_size Memory_block_descriptor::get_size() const noexept {
	return _the_size;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// void Memory_block_descriptor::set_type( const typing::ShortestNatural aType ) noexept {
// 	_type = aType;
// }

// void Memory_block_descriptor::set_memory_block( const Memory_pointer memory_block ) noexept {
// 	_memory_block = memory_block;
// }
// 
// void Memory_block_descriptor::set_returned_address( const Memory_pointer returned_address ) noexept {
// 	_returned_address = returned_address;
// }
void Memory_block_descriptor::set_memory_block_address( const typing::Memory_size memory_block_address ) noexept {
	_memory_block_address = memory_block_address;
}

void Memory_block_descriptor::set_returned_address( const typing::Memory_size returned_address ) noexept {
	_returned_address = returned_address;
}

void Memory_block_descriptor::set_size( typing::Memory_size a_size ) noexept {
	_the_size = a_size;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memory_block_descriptor::~Memory_block_descriptor() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_block_descriptor::Memory_block_descriptor() noexept
{}

Memory_block_descriptor::Memory_block_descriptor( const typing::Memory_size memory_block_address, const typing::Memory_size returned_address, const typing::Memory_size a_size ) noexept
	:
		_memory_block_address( memory_block_address ),
		_returned_address( returned_address ),
		_the_size( a_size )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_block_descriptor::Memory_block_descriptor( const Memory_block_descriptor &another ) noexept
	:
		_the_size( another._the_size ),
		_memory_block_address( another._memory_block_address ),
		_returned_address( another._returned_address )
{}

const Memory_block_descriptor &Memory_block_descriptor::operator =( const Memory_block_descriptor &another ) noexept {
	if ( &another == this ) return *this;

	_memory_block_address = another._memory_block_address;
	_returned_address = another._returned_address;
	_the_size = another._the_size;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
