#include "null_mixin_osie_Thread.h"
#include "../hiddens/hidden_Thread.h"
#include "jmsf/Pointers.hpp"

#include "../../warning_suppressor.h"

namespace jmsf {
namespace osie {
namespace mixins {


void null_mixin_osie_Thread::runThread() throw()
{}

void null_mixin_osie_Thread::setPriority( const natural_size  ) throw( Exception ) // priorityLevel
{}

void null_mixin_osie_Thread::setHiddenThread( Pointer< hiddens::hidden_Thread >  ) throw() // hiddenThread
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_mixin_osie_Thread::~null_mixin_osie_Thread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
null_mixin_osie_Thread::null_mixin_osie_Thread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
null_mixin_osie_Thread::null_mixin_osie_Thread( const null_mixin_osie_Thread & ) throw() // other
{}

const null_mixin_osie_Thread &null_mixin_osie_Thread::operator =( const null_mixin_osie_Thread &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixins
} // namespace osie
} // namespace jmsf
