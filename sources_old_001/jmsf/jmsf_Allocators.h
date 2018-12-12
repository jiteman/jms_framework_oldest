#pragma once

#include "jmsf_Allocators.hxx"


#include "patterning/Singleton.hpp"

#include "memorying/Womp.hxx"
#include "memorying/Allocator.hxx"
#include "memorying/Destructor.hxx"


namespace jmsf {


class jmsf_Allocators :
	public patterning::Singleton< jmsf_Allocators >
{

public:
//	virtual const memorying::Womp< memorying::Allocator > &get_application_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_subsystem_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_character_array_allocator() const noexcept = 0;
	virtual const memorying::Womp< memorying::Allocator > &get_list_node_allocator() const noexcept = 0;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< jmsf_Allocators >;
	virtual ~jmsf_Allocators() noexcept = 0;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace jmsf
