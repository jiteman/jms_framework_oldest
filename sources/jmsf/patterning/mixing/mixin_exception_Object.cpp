#include "mixin_exception_Object.h"

#include "jmsf/patterning/mixing/excepting/exception_exception_Object.h"
#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Boolean.h"

//#include "jmsf/memorying/temporary_Allocator.h"
//#include "jmsf/memorying/Wamp.inl"


namespace jmsf {
namespace patterning {
namespace mixing {


typing::Boolean mixin_exception_Object::is_null() const noexept {
	return typing::False;
}

typing::Boolean mixin_exception_Object::is_exception() const noexept {
	return typing::True;
}

void mixin_exception_Object::throw_if_exception() const {
	throw exceptions::exception_exception_Object( typing::Ansii_string::create_from_constant_literal( "mixin_exception_Object::throw_if_exception() - undefined class" ), FILE_AND_LINE );
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_exception_Object::~mixin_exception_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_exception_Object::mixin_exception_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace patterning
} // namespace jmsf
