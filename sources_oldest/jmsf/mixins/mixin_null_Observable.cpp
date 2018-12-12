#include "mixin_null_Observable.h"

#include "../warning_suppressor.h"

namespace jmsf {
namespace mixins {

void mixin_null_Observable::attach( const Pointer< Observer > & ) throw() // observer
{}

void mixin_null_Observable::detach( const Pointer< Observer > & ) throw() // observer
{}

void mixin_null_Observable::notify() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Observable::~mixin_null_Observable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Observable::mixin_null_Observable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Observable::mixin_null_Observable( const mixin_null_Observable & ) throw() // other
{}

const mixin_null_Observable &mixin_null_Observable::operator =( const mixin_null_Observable &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
