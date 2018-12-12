#include "Object.h"
#include "Boolean.h"
#include "jmsf/debugging/ObjectDeletionLogging.h"

namespace jmsf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const Boolean Object::isReal() const throw() {
	return isNull().not().and( isException().not() );
}

void Object::_deleteThisIfReal() const throw() {
	if ( isReal() ) {
		debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( this, MACROS_FILE_AND_LINE ) );
		delete this;
	}
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Object::~Object() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
