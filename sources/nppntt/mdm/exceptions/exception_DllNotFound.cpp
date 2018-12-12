#include "exception_DllNotFound.h"
#include "jmsf/TextStream.h"


namespace nppntt {
namespace mdm {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_DllNotFound::~exception_DllNotFound() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_DllNotFound::exception_DllNotFound( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_DllNotFound::exception_DllNotFound( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_DllNotFound::exception_DllNotFound( const exception_DllNotFound &other ) throw()
	: mixin_Exception( other )
{}

const exception_DllNotFound &exception_DllNotFound::operator =( const exception_DllNotFound &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
