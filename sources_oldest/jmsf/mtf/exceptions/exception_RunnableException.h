#pragma once

#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"

namespace jmsf {
namespace mtf {
namespace exceptions {


class exception_RunnableException :
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
	~exception_RunnableException() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_RunnableException( const ConstantProxy< TextString > &reason ) throw();
	exception_RunnableException( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_RunnableException( const exception_RunnableException &other ) throw();
	const exception_RunnableException &operator =( const exception_RunnableException &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_RunnableException;

};


} // namespace exceptions
} // namespace mtf
} // namespace jmsf
