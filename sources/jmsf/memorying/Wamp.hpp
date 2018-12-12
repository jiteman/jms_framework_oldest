#pragma once


#include "Wamp.hxx"

#include "jmsf/typing/Boolean.hxx"

#include "Memory_pointer.h"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Wamp {

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

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Wamp() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp() noexept;

public:
	static Wamp create( const Memory_pointer &a_memory_pointer, typing::Memory_size a_quantity ) noexept;

private:
	Wamp( const Memory_pointer &a_memory_pointer, typing::Memory_size a_quantity ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp( const Wamp &another ) noexept;
	const Wamp &operator =( const Wamp &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	typing::Memory_size _the_quantity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
