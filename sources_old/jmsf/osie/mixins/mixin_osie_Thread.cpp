#include "mixin_osie_Thread.h"


#include "../hiddens/hidden_Thread.h"


namespace jmsf {
namespace osie {
namespace mixins {


void mixin_osie_Thread::setPriority( const typing::Natural priorityLevel ) throw( validating::Exception ) {
	_mixin_Thread_HiddenThread->setPriority( priorityLevel );
}

void mixin_osie_Thread::setHiddenThread( pointing::Pointer< hiddens::hidden_Thread > hiddenThread ) throw() {
	_mixin_Thread_HiddenThread = hiddenThread;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_osie_Thread::~mixin_osie_Thread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_osie_Thread::mixin_osie_Thread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_osie_Thread::mixin_osie_Thread( const mixin_osie_Thread & ) throw() // other
{}

const mixin_osie_Thread &mixin_osie_Thread::operator =( const mixin_osie_Thread &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixins
} // namespace osie
} // namespace jmsf
