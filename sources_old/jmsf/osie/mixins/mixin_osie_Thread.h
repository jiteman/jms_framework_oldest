#pragma once


#include "../osie_Thread.h"
#include "jmsf/pointing/Pointer.hpp"

#include "jmsf/typing/Natural.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_osie_Thread :
	public virtual osie_Thread
{

public:
	// virtuals osie_Thread
	void setPriority( typing::Natural priorityLevel ) throw( validating::Exception );
	void setHiddenThread( pointing::Pointer< hiddens::hidden_Thread > hiddenThread ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~mixin_osie_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_osie_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_osie_Thread( const mixin_osie_Thread &other ) throw();
	const mixin_osie_Thread &operator =( const mixin_osie_Thread &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Pointer< hiddens::hidden_Thread > _mixin_Thread_HiddenThread;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixins
} // namespace osie
} // namespace jmsf
