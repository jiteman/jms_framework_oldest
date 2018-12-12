#pragma once


#include "../Object.h"
#include "jmsf/typing/Boolean.hxx"
#include "jmsf/typing/Ansii_string.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_DLL_INTERFACE mixin_Object :
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
	~mixin_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const typing::Ansii_string MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;
//	static const char_type *const MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
