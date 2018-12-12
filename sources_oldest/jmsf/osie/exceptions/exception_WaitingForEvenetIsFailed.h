#pragma once

#include "jmsf/mixins/mixin_Exception.h"

#include "../../jmsf.h"

namespace jmsf {
namespace osie {
namespace exceptions {

class JMSF_DLL_INTERFACE exception_WaitingForEvenetIsFailed :
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
	~exception_WaitingForEvenetIsFailed() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_WaitingForEvenetIsFailed( const ConstantProxy< TextString > &reason ) throw();
	exception_WaitingForEvenetIsFailed( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_WaitingForEvenetIsFailed( const exception_WaitingForEvenetIsFailed &other ) throw();
	const exception_WaitingForEvenetIsFailed &operator =( const exception_WaitingForEvenetIsFailed &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
