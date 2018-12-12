#include "mixin_null_Object.h"


#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace patterning {
namespace mixing {


typing::Boolean mixin_null_Object::is_null() const noexept {
	return typing::True;
}

typing::Boolean mixin_null_Object::is_exception() const noexept {
	return typing::False;
}

void mixin_null_Object::throw_if_exception() const
{}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Object::~mixin_null_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Object::mixin_null_Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixing
} // namespace patterning
} // namespace jmsf
