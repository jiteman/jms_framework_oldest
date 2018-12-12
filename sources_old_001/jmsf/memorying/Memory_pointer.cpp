#include "Memory_pointer.h"

#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/Should.h"
#include "jmsf/validating/logging_macroses.h"


namespace jmsf {
namespace memorying {


typeing::Boolean Memory_pointer::is_empty() const noexcept {
	return typeing::Boolean::create( _the_memory == nullptr );
}

typeing::Boolean Memory_pointer::is_not_empty() const noexcept {
	return typeing::Boolean::create( _the_memory != nullptr );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::internals::platform_byte *Memory_pointer::take() {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( _the_memory == nullptr, "Memory_pointer::take()" );
	jmsf_Should_never_be_null_native_pointer( _the_memory );
//	validating::Should::never_be_null_native_pointer( _the_memory, JMSF_FILE_AND_LINE );
	return _the_memory;
}

const typeing::internals::platform_byte *Memory_pointer::get() const {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( _the_memory == nullptr, "Memory_pointer::take()" );
	jmsf_Should_never_be_null_native_pointer( _the_memory );
	return _the_memory;
}

typeing::Memory_natural Memory_pointer::get_address() const noexcept {
	return typeing::Memory_natural::create( reinterpret_cast< typeing::memory_natural_value_type >( _the_memory ) );
}

void Memory_pointer::set_address( const typeing::Memory_natural an_address ) noexcept {
	_the_memory = reinterpret_cast< typeing::internals::platform_byte * >( an_address.get_native_value() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Memory_pointer::~Memory_pointer() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer::Memory_pointer() noexcept {
	_the_memory = nullptr;
}

// static
// Memory_pointer Memory_pointer::create( typeing::internals::platform_byte *const a_memory ) noexcept {
// 	return Memory_pointer( a_memory );
// }

// static
Memory_pointer Memory_pointer::create_from_address( const typeing::Memory_natural an_address ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( an_address.is_nill(), "Memory_pointer::create_from_address( an_address )" );
	jmsf_Should_never_be( an_address.is_nill() );
	return Memory_pointer( typeing::get_pointer_from_Memory_natural< typeing::internals::platform_byte >( an_address ) );
}

Memory_pointer::Memory_pointer( typeing::internals::platform_byte *const a_memory ) noexcept {
	_the_memory = a_memory;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Memory_pointer::Memory_pointer( const Memory_pointer &another ) noexcept {
	_the_memory = another._the_memory;
}

const Memory_pointer &Memory_pointer::operator =( const Memory_pointer &another ) noexcept {
	if ( &another == this ) return *this;

	_the_memory = another._the_memory;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace memorying
} // namespace jmsf
