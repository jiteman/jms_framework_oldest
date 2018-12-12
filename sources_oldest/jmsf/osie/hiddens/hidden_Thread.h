#pragma once

#include "jmsf/Exception.hxx"
#include "jmsf/types.h"
#include "../../jmsf.h"

namespace jmsf {
namespace osie {
namespace hiddens {

class JMSF_DLL_INTERFACE hidden_Thread {

public:
	virtual void setPriority( natural_size priorityLevel ) throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~hidden_Thread() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace hiddens
} // namespace osie
} // namespace jmsf
