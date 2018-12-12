#pragma once


#include "Memory_pointer.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace memorying {


typing::Boolean Memory_pointer::is_empty() const noexept {
	return typing::Boolean::create( _the_memory == nullptr );
}

typing::Boolean Memory_pointer::is_not_empty() const noexept {
	return typing::Boolean::create( _the_memory != nullptr );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typing::internals::platform_byte *Memory_pointer::take() noexept {
	return _the_memory;
}

const typing::internals::platform_byte *Memory_pointer::get() const noexept {
	return _the_memory;
}

typing::Memory_size Memory_pointer::get_address() const noexept {
	return typing::Memory_size::create( reinterpret_cast< typing::memory_size_value_type >( _the_memory ) );
}

void Memory_pointer::set_address( const typing::Memory_size an_address ) noexept {
	_the_memory = reinterpret_cast< typing::internals::platform_byte * >( an_address.get_value() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memory_pointer::~Memory_pointer() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer::Memory_pointer() noexept {
	_the_memory = nullptr;
}

// static
// Memory_pointer Memory_pointer::create( typing::internals::platform_byte *const a_memory ) noexept {
// 	return Memory_pointer( a_memory );
// }

// static
Memory_pointer Memory_pointer::create_from_address( const typing::Memory_size an_address ) noexept {
	return Memory_pointer( typing::get_pointer_from_memory_size< typing::internals::platform_byte >( an_address ) );
}

Memory_pointer::Memory_pointer( typing::internals::platform_byte *const a_memory ) noexept {
	_the_memory = a_memory;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer::Memory_pointer( const Memory_pointer &another ) noexept {
	_the_memory = another._the_memory;
}

const Memory_pointer &Memory_pointer::operator =( const Memory_pointer &another ) noexept {
	if ( &another == this ) return *this;

	_the_memory = another._the_memory;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
