#include "mixin_Object.h"


#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Boolean.h"

#include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace patterning {
namespace mixing {


typing::Boolean mixin_Object::is_null() const noexept {
	return typing::False;
}

typing::Boolean mixin_Object::is_exception() const noexept {
	return typing::False;
}

void mixin_Object::throw_if_exception() const
{}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Object::~mixin_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Object::mixin_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
const typing::Ansii_string mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = typing::Ansii_string::create_from_constant_literal( "mixin_Object - copy prohibition is violated" );

// static
// const char_type *const mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = "mixin_Object - copy prohibition is violated";


} // namespace mixing
} // namespace patterning
} // namespace jmsf
