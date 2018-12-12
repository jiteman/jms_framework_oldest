#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_DLL_INTERFACE mixin_exception_Object :
	public virtual Object
{

public:
	// virtuals Object
	typing::Boolean is_null() const noexept;
	typing::Boolean is_exception() const noexept;

	void throw_if_exception() const;
	//~virtuals	Object

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~mixin_exception_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_exception_Object() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
