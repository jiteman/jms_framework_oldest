#include "Heap_status_descriptor.h"

#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace memorying {
namespace allocating {


typing::Memory_size Heap_status_descriptor::get_memory_heap_start() const noexept {
	return _memory_heap_start;
}

typing::Memory_size Heap_status_descriptor::get_memory_heap_end() const noexept {
	return _memory_heap_end;
}

typing::Memory_size Heap_status_descriptor::get_memory_heap_size() const noexept {
	return ++( _memory_heap_end - _memory_heap_start );
}

typing::Memory_size Heap_status_descriptor::get_middle_block_start() const noexept {
	return _middle_block_start;
}

typing::Memory_size Heap_status_descriptor::get_middle_block_end() const noexept {
	return _middle_block_end;
}

typing::Memory_size Heap_status_descriptor::get_middle_block_size() const noexept {
	return ++( _middle_block_end - _middle_block_start );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Heap_status_descriptor::set_middle_block_start( const typing::Memory_size an_address ) {
	_middle_block_start = an_address;
}

void Heap_status_descriptor::set_middle_block_end( const typing::Memory_size an_address ) {
	_middle_block_end = an_address;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Heap_status_descriptor::~Heap_status_descriptor() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Heap_status_descriptor::Heap_status_descriptor() noexept
{}

Heap_status_descriptor::Heap_status_descriptor( const typing::Memory_size memory_heap_start, const typing::Memory_size memory_heap_size ) noexept
	:
		_memory_heap_start( memory_heap_start ),
		_memory_heap_end( --( memory_heap_start + memory_heap_size ) ),
		_middle_block_start( memory_heap_start ),
		_middle_block_end( --( memory_heap_start + memory_heap_size ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Heap_status_descriptor::Heap_status_descriptor( const Heap_status_descriptor &another ) noexept
	:
		_memory_heap_start( another._memory_heap_start ),
		_memory_heap_end( another._memory_heap_end ),
		_middle_block_start( another._middle_block_start ),
		_middle_block_end( another._middle_block_end )
{}

const Heap_status_descriptor &Heap_status_descriptor::operator =( const Heap_status_descriptor &another ) noexept {
	if ( &another == this ) return *this;

	_memory_heap_start = another._memory_heap_start;
	_memory_heap_end = another._memory_heap_end;
	_middle_block_start = another._middle_block_start;
	_middle_block_end = another._middle_block_end;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace allocating
} // namespace memorying
} // namespace jmsf
