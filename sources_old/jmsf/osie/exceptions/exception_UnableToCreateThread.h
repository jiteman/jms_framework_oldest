#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_UnableToCreateThread :
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
	~exception_UnableToCreateThread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_UnableToCreateThread( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw();
	exception_UnableToCreateThread( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_UnableToCreateThread( const exception_UnableToCreateThread &other ) throw();
	const exception_UnableToCreateThread &operator =( const exception_UnableToCreateThread &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
