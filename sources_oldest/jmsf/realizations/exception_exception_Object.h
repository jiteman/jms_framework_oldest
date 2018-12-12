#pragma once

#include "../mixins/mixin_Exception.h"


namespace jmsf {
namespace realizations {


class exception_exception_Object :
	public mixins::mixin_Exception
{

public:
	// virtuals
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_exception_Object() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_exception_Object( const ConstantProxy< TextString > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	exception_exception_Object( const exception_exception_Object &other ) throw();

private:
	const exception_exception_Object &operator =( const exception_exception_Object &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
