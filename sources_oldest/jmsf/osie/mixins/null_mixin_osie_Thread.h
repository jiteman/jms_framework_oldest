#pragma once

#include "../osie_Thread.h"
#include "jmsf/Exception.hxx"

#include "../../jmsf.h"

namespace jmsf {
namespace osie {
namespace mixins {


class JMSF_DLL_INTERFACE null_mixin_osie_Thread :
	public virtual osie_Thread
{

public:
	// virtuals osie_Thread
	void runThread() throw();
	void setPriority( natural_size priorityLevel ) throw( Exception );
	void setHiddenThread( Pointer< hiddens::hidden_Thread > hiddenThread ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~null_mixin_osie_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	null_mixin_osie_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_mixin_osie_Thread( const null_mixin_osie_Thread &other ) throw();
	const null_mixin_osie_Thread &operator =( const null_mixin_osie_Thread &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixins
} // namespace osie
} // namespace jmsf
