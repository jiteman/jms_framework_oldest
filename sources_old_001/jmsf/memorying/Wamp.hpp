#pragma once


#include "Wamp.hxx"

#include "jmsf/typeing/Boolean.hxx"

#include "Memory_pointer.h"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Wamp {

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

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Wamp() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp() noexcept;

// SenSEI: todonext - figure out the need for several factory methods (create_from_memory_pointer, create_from_pointer, create_from_address)
public:
	static Wamp create( const Memory_pointer &a_memory_pointer, typeing::Memory_natural a_quantity );

private:
	Wamp( const Memory_pointer &a_memory_pointer, typeing::Memory_natural a_quantity ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Wamp( const Wamp &another ) noexcept;
	const Wamp &operator =( const Wamp &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Memory_pointer _the_memory_pointer;
	typeing::Memory_natural _the_quantity;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf
