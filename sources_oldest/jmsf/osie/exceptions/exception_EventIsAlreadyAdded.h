#pragma once

#include "jmsf/mixins/mixin_Exception.h"

#include "../../jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_EventIsAlreadyAdded :
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
	~exception_EventIsAlreadyAdded() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_EventIsAlreadyAdded( const ConstantProxy< TextString > &reason ) throw();
	exception_EventIsAlreadyAdded( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_EventIsAlreadyAdded( const exception_EventIsAlreadyAdded &other ) throw();
	const exception_EventIsAlreadyAdded &operator =( const exception_EventIsAlreadyAdded &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
