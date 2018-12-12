#pragma once

#include "realizing_Subsystem_allocator.hxx"


#include "../Allocator.h"

#include "jmsf/memorying/Womp.hin"

//#include "jmsf/jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace memorying {
namespace realizing {


class realizing_Subsystem_allocator :
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
private:
	~realizing_Subsystem_allocator() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Constructor< Allocator, realizing_Subsystem_allocator >;
	realizing_Subsystem_allocator( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

public:
	// SenSEI: todonext - create allocator subtypes - like with exceptions (application, subsystem, etc.) +
	// realizations to mix them into final allocator (like cule_subsystem_allocator)
	// friend jmsf_Environment;
	static Omp< Allocator > create( const memorying::Womp< memorying::Allocator > &application_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_Subsystem_allocator( const realizing_Subsystem_allocator &another ) noexcept;
	const realizing_Subsystem_allocator &operator =( const realizing_Subsystem_allocator &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Womp< Allocator > _application_allocator;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace memorying
} // namespace jmsf
