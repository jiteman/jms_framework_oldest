#pragma once

#include "../mixins/mixin_Exception.h"
#include "../types.h"


namespace jmsf {
namespace exceptions {


class exception_InitializationOrderIsViolated :
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
	~exception_InitializationOrderIsViolated() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_InitializationOrderIsViolated( const char_type *reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_InitializationOrderIsViolated( const exception_InitializationOrderIsViolated &other ) throw();
	const exception_InitializationOrderIsViolated &operator =( const exception_InitializationOrderIsViolated &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_InitializationOrderIsViolated;

};


} // namespace exceptions
} // namespace jmsf
