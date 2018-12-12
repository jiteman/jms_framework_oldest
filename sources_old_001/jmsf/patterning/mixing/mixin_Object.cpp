#include "mixin_Object.h"


#include "jmsf/typeing/Ansii_string.h"
#include "jmsf/typeing/Boolean.h"

//#include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace patterning {
namespace mixing {


typeing::Boolean mixin_Object::is_null() const noexcept {
	return typeing::False;
}

typeing::Boolean mixin_Object::is_exception() const noexcept {
	return typeing::False;
}

void mixin_Object::throw_if_exception() const
{}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Object::~mixin_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Object::mixin_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
const typeing::Ansii_string mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = typeing::Ansii_string::create_from_constant_literal( "mixin_Object - copy prohibition is violated" );

// static
// const char_type *const mixin_Object::MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED = "mixin_Object - copy prohibition is violated";


} // namespace mixing
} // namespace patterning
} // namespace jmsf
