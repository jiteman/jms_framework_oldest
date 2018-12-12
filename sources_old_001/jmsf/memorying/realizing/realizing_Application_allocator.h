#pragma once

#include "realizing_Application_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/memorying/Womp.hpp"

#include "jmsf/jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace memorying {
namespace realizing { // SenSEI: todonext - refactor to singleton


class realizing_Application_allocator :
	public Allocator
{

public:
	// virtuals Allocator
	Memory_pointer allocate_memory( typeing::Memory_natural a_size, typeing::Memory_natural an_alignment );
	void deallocate_memory( const Memory_pointer &a_memory, typeing::Memory_natural an_alignment );
	//~virtuals Allocator

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~realizing_Application_allocator() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Constructor< Allocator, realizing_Application_allocator >;
	realizing_Application_allocator( const Womp< Allocator > &system_allocator ) noexcept;

private: friend jmsf_Environment;
	static Omp< Allocator > create( const Womp< Allocator > &system_allocator ) noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_Application_allocator( const realizing_Application_allocator &another ) noexcept;
	const realizing_Application_allocator &operator =( const realizing_Application_allocator &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Womp< Allocator > _system_allocator;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
