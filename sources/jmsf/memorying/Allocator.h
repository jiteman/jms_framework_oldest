#pragma once


#include "jmsf/patterning/mixing/mixin_null_Object.hxx"
#include "jmsf/patterning/mixing/mixin_exception_Object.hxx"
#include "jmsf/patterning/mixing/mixin_Object.hxx"

#include "Memory_pointer.hxx"

#include "jmsf/typing/Naturals.hxx"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace memorying {


class JMSF_DLL_INTERFACE Allocator {

public:
	virtual Memory_pointer allocate_memory( typing::Memory_size a_size, typing::Memory_size an_alignment ) = 0;
	virtual void deallocate_memory( const Memory_pointer &a_memory, typing::Memory_size an_alignment ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	friend patterning::mixing::mixin_null_Object;
	friend patterning::mixing::mixin_exception_Object;
	friend patterning::mixing::mixin_Object;
	virtual ~Allocator() noexept = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace memorying
} // namespace jmsf
