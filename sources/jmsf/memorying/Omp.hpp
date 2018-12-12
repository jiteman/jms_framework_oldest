#pragma once


#include "Omp.hxx"

#include "Allocator.hxx"
#include "jmsf/typing/Boolean.hxx"

#include "Memory_pointer.h"
#include "Womp.hpp"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Omp {

public:
	typing::Boolean is_empty() const noexept;
	typing::Boolean is_not_empty() const noexept;

	const A_type *get() const noexept;

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type *take() noexept;

	A_type &operator *();
	A_type *operator ->();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer get_memory() const noexept;
	Womp< Allocator > get_allocator() const noexept;
	typing::Memory_size get_alignment() const noexept;
	Womp< A_type > get_as_weak() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Omp() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp() noexept;
	static Omp create( const Memory_pointer &a_memory_pointer, const Womp< Allocator > &an_allocator, typing::Memory_size an_alignment ) noexept;
	static Omp create_from_weak( const Womp< A_type > &weak_omp ) noexept;

private:
	Omp( const Memory_pointer &a_memory_pointer, const Womp< Allocator > &an_allocator, typing::Memory_size an_alignment ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp( const Omp &another ) noexept;
	const Omp &operator =( const Omp &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	Womp< Allocator > _the_allocator;
	typing::Memory_size _the_alignment;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
