#include "exception_EventIsNullptr.h"
#include "jmsf/TextStream.h"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventIsNullptr::~exception_EventIsNullptr() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsNullptr::exception_EventIsNullptr( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_EventIsNullptr::exception_EventIsNullptr( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsNullptr::exception_EventIsNullptr( const exception_EventIsNullptr &other ) throw()
	: mixin_Exception( other )
{}

const exception_EventIsNullptr &exception_EventIsNullptr::operator =( const exception_EventIsNullptr &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
