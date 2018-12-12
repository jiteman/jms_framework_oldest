#include "mixin_exception_Object.h"

#include "jmsf/patterning/mixing/excepting/exception_exception_Object.h"
#include "jmsf/typeing/Ansii_string.h"
#include "jmsf/typeing/Boolean.h"

#include "jmsf/validating/File_and_line.h"

//#include "jmsf/memorying/temporary_Allocator.h"
//#include "jmsf/memorying/Wamp.inl"


namespace jmsf {
namespace patterning {
namespace mixing {


typeing::Boolean mixin_exception_Object::is_null() const noexcept {
	return typeing::False;
}

typeing::Boolean mixin_exception_Object::is_exception() const noexcept {
	return typeing::True;
}

void mixin_exception_Object::throw_if_exception() const {
	throw
		exceptions::exception_exception_Object(
			typeing::Ansii_string::create_from_constant_literal(
				"mixin_exception_Object::throw_if_exception() - undefined class" ),
				JMSF_FILE_AND_LINE );
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_exception_Object::~mixin_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_exception_Object::mixin_exception_Object() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace patterning
} // namespace jmsf
