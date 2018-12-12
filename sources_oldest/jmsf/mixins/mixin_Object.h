#pragma once


#include "jmsf/Object.h"
#include "jmsf/ConstantProxy.hpp"

#include "jmsf/types/Boolean.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_Object :
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
	mixin_Object() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const ConstantProxy< TextString > MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;
//	static const char_type *const MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;

};


} // namespace
}
