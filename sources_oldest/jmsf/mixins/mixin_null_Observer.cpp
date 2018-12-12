#include "mixin_null_Observer.h"
#include "jmsf/Should.h"

#include "../warning_suppressor.h"

namespace jmsf {
namespace mixins {

void mixin_null_Observer::update() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Observer::~mixin_null_Observer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Observer::mixin_null_Observer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Observer::mixin_null_Observer( const mixin_null_Observer & ) throw() // other
{}

const mixin_null_Observer &mixin_null_Observer::operator =( const mixin_null_Observer &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "mixin_null_Observer::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixins
} // namespace jmsf
