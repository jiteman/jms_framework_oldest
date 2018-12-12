#pragma once

#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"

namespace jmsf {
namespace mtf {
namespace exceptions {


class exception_RunnableIsAlreadyRegisteredForThisThread :
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
	~exception_RunnableIsAlreadyRegisteredForThisThread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_RunnableIsAlreadyRegisteredForThisThread( const ConstantProxy< TextString > &reason ) throw();
	exception_RunnableIsAlreadyRegisteredForThisThread( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_RunnableIsAlreadyRegisteredForThisThread( const exception_RunnableIsAlreadyRegisteredForThisThread &other ) throw();
	const exception_RunnableIsAlreadyRegisteredForThisThread &operator =( const exception_RunnableIsAlreadyRegisteredForThisThread &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_RunnableIsAlreadyRegisteredForThisThread;

};


} // namespace exceptions
} // namespace mtf
} // namespace jmsf
