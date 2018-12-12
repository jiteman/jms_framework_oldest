#pragma once


#include "Memory_pointer.hxx"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/typing/Naturals.hxx"
#include "jmsf/typing/Boolean.hxx"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"

namespace jmsf {
namespace memorying {


// pointer to void
class JMSF_DLL_INTERFACE Memory_pointer {

public:
	typing::Boolean is_empty() const noexept;
	typing::Boolean is_not_empty() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typing::internals::platform_byte *take() noexept;
	const typing::internals::platform_byte *get() const noexept;
	typing::Memory_size get_address() const noexept;

	void set_address( typing::Memory_size an_address ) noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Memory_pointer() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer() noexept;

public:
//	static Memory_pointer create( typing::internals::platform_byte *a_memory ) noexept;

	template< class A_type >
	static Memory_pointer create_from_pointer( const A_type *a_memory ) noexept;

	static Memory_pointer create_from_address( typing::Memory_size an_address ) noexept;

private:
	Memory_pointer( typing::internals::platform_byte *a_memory ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer( const Memory_pointer &another ) noexept;
	const Memory_pointer &operator =( const Memory_pointer &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::internals::platform_byte *_the_memory;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// static
template< class A_type >
Memory_pointer Memory_pointer::create_from_pointer( const A_type *const a_memory ) noexept {
	return Memory_pointer( reinterpret_cast< typing::internals::platform_byte * >( const_cast< A_type * >( a_memory ) ) );
}


} // namespace memorying
} // namespace jmsf
