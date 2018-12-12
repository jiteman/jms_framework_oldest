#include "mixin_null_Object.h"
#include "../Boolean.h"

namespace jmsf {
namespace mixins {

const Boolean mixin_null_Object::isNull() const throw() {
	return Boolean::True;
}

const Boolean mixin_null_Object::isException() const throw() {
	return Boolean::False;
}

void mixin_null_Object::throwIfException() const throw( Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Object::mixin_null_Object() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
