#pragma once

#include "realizing_jmsf_Allocators.hxx"


#include "../jmsf_Allocators.h"

#include "jmsf/memorying/Owomp.hpp"

#include "jmsf/jmsf_Environment.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace realizing {


class realizing_jmsf_Allocators :
		public jmsf_Allocators
{

public:
	// virtuals jmsf_Allocators
//	const memorying::Womp< memorying::Allocator > &get_application_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept;
	const memorying::Womp< memorying::Allocator > &get_list_node_allocator() const noexcept;
	//~virtuals jmsf_Allocators

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~realizing_jmsf_Allocators() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< jmsf_Allocators, realizing_jmsf_Allocators >;
	realizing_jmsf_Allocators(
//		const memorying::Womp< memorying::Allocator > &system_allocator,
//		const memorying::Omp< memorying::Allocator > &application_allocator,
		const memorying::Omp< memorying::Allocator > &subsystem_allocator ) noexcept;

private: friend jmsf_Environment;
	static void create_instance(
		const memorying::Womp< memorying::Allocator > &application_allocator,
		const memorying::Omp< memorying::Allocator > &subsystem_allocator ) noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realizing_jmsf_Allocators( const realizing_jmsf_Allocators &another ) noexcept;
	const realizing_jmsf_Allocators &operator =( const realizing_jmsf_Allocators &another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	memorying::Owomp< memorying::Allocator > _system_allocator;
//	memorying::Womp< memorying::Allocator > _application_allocator;
	memorying::Owomp< memorying::Allocator > _subsystem_allocator;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace jmsf
