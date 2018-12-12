#pragma once

#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_EventArrayIsNullptr :
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
	~exception_EventArrayIsNullptr() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_EventArrayIsNullptr( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw();
	exception_EventArrayIsNullptr( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_EventArrayIsNullptr( const exception_EventArrayIsNullptr &other ) throw();
	const exception_EventArrayIsNullptr &operator =( const exception_EventArrayIsNullptr &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
