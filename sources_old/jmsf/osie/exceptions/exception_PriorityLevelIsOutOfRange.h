#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_PriorityLevelIsOutOfRange :
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
	~exception_PriorityLevelIsOutOfRange() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_PriorityLevelIsOutOfRange( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw();
	exception_PriorityLevelIsOutOfRange( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_PriorityLevelIsOutOfRange( const exception_PriorityLevelIsOutOfRange &other ) throw();
	const exception_PriorityLevelIsOutOfRange &operator =( const exception_PriorityLevelIsOutOfRange &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const typing::internals::platform_char *EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange;

};

} // namespace exceptions
} // namespace osie
} // namespace jmsf
