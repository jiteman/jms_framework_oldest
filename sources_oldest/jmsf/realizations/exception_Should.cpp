#include "exception_Should.h"


#include "../TextString.h"


namespace jmsf {
namespace realizations {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_Should::~exception_Should() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_Should::exception_Should( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
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


} // namespace
}
