#pragma once


#include "Amp.hxx"

#include "Allocator.hxx"
#include "jmsf/typing/Boolean.hxx"

#include "Memory_pointer.h"
#include "Womp.hpp"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Amp {

public:
	typing::Boolean is_empty() const noexept;
	typing::Boolean is_not_empty() const noexept;

	const A_type *get() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type *take() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer get_memory() const noexept;
	typing::Memory_size get_quantity() const noexept;
	Womp< Allocator > get_allocator() const noexept;
	typing::Memory_size get_alignment() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Amp() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp() noexept;

public:
	static Amp create(
		const Memory_pointer &a_memory_pointer,
		typing::Memory_size a_quantity,
		const Womp< Allocator > &an_allocator,
		typing::Memory_size an_alignment ) noexept;

private:
	Amp(
		const Memory_pointer &a_memory_pointer,
		typing::Memory_size a_quantity,
		const Womp< Allocator > &an_allocator,
		typing::Memory_size an_alignment ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp( const Amp &another ) noexept;
	const Amp &operator =( const Amp &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	typing::Memory_size _the_quantity;
	Womp< Allocator > _the_allocator;
	typing::Memory_size _the_alignment;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
