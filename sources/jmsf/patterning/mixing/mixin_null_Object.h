#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/typing/Boolean.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_DLL_INTERFACE mixin_null_Object :
	public virtual Object
{

public:
	// virtuals
	typing::Boolean is_null() const noexept;
	typing::Boolean is_exception() const noexept;

	void throw_if_exception() const;
	//~virtuals	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~mixin_null_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Object() noexept;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
