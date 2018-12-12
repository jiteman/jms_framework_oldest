#pragma once


#include "Omp.hxx"

#include "Allocator.hxx"
#include "jmsf/typeing/Boolean.hxx"

#include "Memory_pointer.h"
#include "Womp.hpp"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Omp {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;

	const A_type *get() const;

	const A_type &operator *() const;
	const A_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type *take();

	A_type &operator *();
	A_type *operator ->();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Memory_pointer get_memory() const;
	Womp< Allocator > get_allocator() const noexcept;
	typeing::Memory_natural get_alignment() const noexcept;
	Womp< A_type > get_as_weak() const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Omp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp() noexcept;
	static Omp create( const Memory_pointer &a_memory_pointer, const Womp< Allocator > &an_allocator, typeing::Memory_natural an_alignment );
	static Omp create_from_weak( const Womp< A_type > &weak_omp );

private:
	Omp( const Memory_pointer &a_memory_pointer, const Womp< Allocator > &an_allocator, typeing::Memory_natural an_alignment ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Omp( const Omp &another ) noexcept;
	const Omp &operator =( const Omp &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	Womp< Allocator > _the_allocator;
	typeing::Memory_natural _the_alignment;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
