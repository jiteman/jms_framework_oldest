#pragma once

#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_EventIsAlreadyAdded :
	public validating::mixing::mixin_Exception
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
	exception_EventIsAlreadyAdded( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw();
	exception_EventIsAlreadyAdded( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw();

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
