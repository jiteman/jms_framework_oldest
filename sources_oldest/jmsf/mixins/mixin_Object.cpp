#include "mixin_Object.h"


#include "jmsf/TextString.h"
#include "jmsf/types/Boolean.h"

#include "jmsf/ConstantProxy.inl"


namespace jmsf {
namespace mixins {


const types::Boolean mixin_Object::isNull() const throw() {
	return types::False;asd
}

const types::Boolean mixin_Object::isException() const throw() {
	return types::False;
}

void mixin_Object::throwIfException() const throw( Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Object::mixin_Object() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
const ConstantProxy< TextString > mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = "mixin_Object - copy prohibition is violated";

// static
// const char_type *const mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = "mixin_Object - copy prohibition is violated";


} // namespace
}
