#include "Object.h"


#include "jmsf/typing/Boolean.h"
#include "jmsf/memorying/temporary_Allocator.h"
#include "jmsf/memorying/Destructor.inl"


namespace jmsf {
namespace patterning {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// typing::Boolean Object::isReal() const throw() {
// 	return isNull().not().and( isException().not() );
// }
// 
// void Object::_deleteThisIfReal() const throw() {
// 	if ( isReal() ) {
// 		memorying::temporary_Allocator allocator;
// 		memorying::Destruct( *this, allocator );
// 	}
// }

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Object::~Object() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace patterning
} // namespace jmsf
