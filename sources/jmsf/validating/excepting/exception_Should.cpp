#include "exception_Should.h"


//#include "jmsf/typing/AnsiiString.h"


namespace jmsf {
namespace validating {
namespace realizations {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should::~exception_Should() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const typing::Ansii_string &reason, const File_and_line &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const exception_Should &other ) throw()
	: mixin_Exception( other )
{}

const exception_Should &exception_Should::operator =( const exception_Should &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizations
} // namespace validating
} // namespace jmsf
