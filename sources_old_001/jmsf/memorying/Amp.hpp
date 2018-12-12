#pragma once


#include "Amp.hxx"

#include "Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "Memory_pointer.h"
#include "Womp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Amp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	const A_type *get() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type *take();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer get_memory() const;
	typeing::Memory_natural get_quantity() const noexcept;
	Womp< Allocator > get_allocator() const noexcept;
	typeing::Memory_natural get_alignment() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Amp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp() noexcept;

public:
	static Amp create(
		const Memory_pointer &a_memory_pointer,
		typeing::Memory_natural a_quantity,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment );

private:
	Amp(
		const Memory_pointer &a_memory_pointer,
		typeing::Memory_natural a_quantity,
		const Womp< Allocator > &an_allocator,
		typeing::Memory_natural an_alignment ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Amp( const Amp &another ) noexcept;
	const Amp &operator =( const Amp &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	typeing::Memory_natural _the_quantity;
	Womp< Allocator > _the_allocator;
	typeing::Memory_natural _the_alignment;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
