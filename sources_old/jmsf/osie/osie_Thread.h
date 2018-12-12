#pragma once


#include "hiddens/hidden_Thread.hxx"
#include "jmsf/pointing/Pointer.hxx"

#include "jmsf/typing/Natural.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE osie_Thread {

public:
	virtual void runThread() throw() = 0;
	virtual void setPriority( typing::Natural priorityLevel ) throw() = 0;
	virtual void setHiddenThread( pointing::Pointer< hiddens::hidden_Thread > hiddenThread ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~osie_Thread() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace osie
} // namespace jmsf
