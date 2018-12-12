#pragma once

#include "jmsf_Environment.hxx"


#include "jmsf/encodebuba/mixing/mixin_Environment.h"

#include "jmsf/memorying/Owomp.hpp"

#include "jmsf_Allocators.hxx"
#include "jmsf/memorying/Womp.hxx"

#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"
#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {


class JMSF_SHARED_INTERFACE jmsf_Environment :
	public encodebuba::mixing::mixin_Environment
{

public:
	const memorying::Womp< memorying::Allocator > &get_application_allocator() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static const jmsf_Environment *instance() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	// virtuals mixin_Environment
	void initialize_status_text_messages();
	int initialize_environment();
	void terminate_environment() noexcept;
	//~virtuals mixin_Environment

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~jmsf_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	jmsf_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	jmsf_Environment( const jmsf_Environment &another ) noexcept;
	const jmsf_Environment &operator =( const jmsf_Environment &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Owomp< memorying::Allocator > _system_allocator;
	memorying::Owomp< memorying::Allocator > _application_allocator;
//	memorying::Owomp< jmsf_Allocators > _jmsf_allocators;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace jmsf
