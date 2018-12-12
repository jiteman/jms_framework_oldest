#pragma once


#include "Memory_pointer.hxx"

#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/typeing/Naturals.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace memorying {


// pointer to void
class JMSF_SHARED_INTERFACE Memory_pointer {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::internals::platform_byte *take();
	const typeing::internals::platform_byte *get() const;
	typeing::Memory_natural get_address() const noexcept;

	void set_address( typeing::Memory_natural an_address ) noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Memory_pointer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer() noexcept;

public:
//	static Memory_pointer create( typeing::internals::platform_byte *a_memory ) noexcept;

	template< class A_type >
	static Memory_pointer create_from_pointer( const A_type *a_memory );

	static Memory_pointer create_from_address( typeing::Memory_natural an_address );

private:
	Memory_pointer( typeing::internals::platform_byte *a_memory ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer( const Memory_pointer &another ) noexcept;
	const Memory_pointer &operator =( const Memory_pointer &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::internals::platform_byte *_the_memory;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
