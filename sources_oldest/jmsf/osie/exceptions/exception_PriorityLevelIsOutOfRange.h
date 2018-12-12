#pragma once

#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"

#include "../../jmsf.h"

namespace jmsf {
namespace osie {
namespace exceptions {

class JMSF_DLL_INTERFACE exception_PriorityLevelIsOutOfRange :
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
	~exception_PriorityLevelIsOutOfRange() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_PriorityLevelIsOutOfRange( const ConstantProxy< TextString > &reason ) throw();
	exception_PriorityLevelIsOutOfRange( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_PriorityLevelIsOutOfRange( const exception_PriorityLevelIsOutOfRange &other ) throw();
	const exception_PriorityLevelIsOutOfRange &operator =( const exception_PriorityLevelIsOutOfRange &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange;

};

} // namespace exceptions
} // namespace osie
} // namespace jmsf
