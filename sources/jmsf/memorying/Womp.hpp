#pragma once


#include "Womp.hxx"

#include "Omp.hxx"

#include "jmsf/typing/Boolean.hxx"

#include "Memory_pointer.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Womp {

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
	typing::Memory_size get_address() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Womp() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Womp() noexept;	

public:
	static Womp create_from_memory_pointer( const Memory_pointer &a_memory_pointer ) noexept;
	static Womp create_from_pointer( const A_type *an_object ) noexept;
	static Womp create_from_address( typing::Memory_size an_address ) noexept;
//	static Womp create( const Omp< A_type > &object_memory_pointer ) noexept;

private:
	Womp( const Memory_pointer &a_memory_pointer ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Womp( const Womp &another ) noexept;
	const Womp &operator =( const Womp &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
