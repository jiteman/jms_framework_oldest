#include "exception_UnexpectedStlException.h"

#include "../Proxy.hpp"


namespace jmsf {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_UnexpectedStlException::~exception_UnexpectedStlException() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnexpectedStlException::exception_UnexpectedStlException( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_UnexpectedStlException::exception_UnexpectedStlException( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnexpectedStlException::exception_UnexpectedStlException( const exception_UnexpectedStlException &other ) throw()
	: mixin_Exception( other )
{}

const exception_UnexpectedStlException &exception_UnexpectedStlException::operator =( const exception_UnexpectedStlException &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
