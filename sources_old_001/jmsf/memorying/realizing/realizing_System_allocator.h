#pragma once

#include "realizing_System_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace memorying {
namespace realizing {


class realizing_System_allocator :
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
	~realizing_System_allocator() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_System_allocator() noexcept;

private: friend jmsf_Environment;
	static Omp< Allocator > create() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_System_allocator( const realizing_System_allocator &another ) noexcept;
	const realizing_System_allocator &operator =( const realizing_System_allocator &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
