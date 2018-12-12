#pragma once

#include "jmsf/Object.h"

#include "jmsf/jmsf.h"

#include "jmsf/types/Boolean.hxx"


namespace jmsf {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_null_Object :
	public virtual Object
{

public:
	// virtuals
	const types::Boolean isNull() const throw();
	const types::Boolean isException() const throw();

	void throwIfException() const throw( Exception );
	//~virtuals	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Object() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace
}
