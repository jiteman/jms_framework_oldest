#include "exception_exception_Object.h"


namespace jmsf {
namespace realizations {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_exception_Object::~exception_exception_Object() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_exception_Object::exception_exception_Object( const exception_exception_Object &other ) throw()
	: mixin_Exception( other )
{}

const exception_exception_Object &exception_exception_Object::operator =( const exception_exception_Object &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
