#include "exception_EventIsAlreadyAdded.h"
#include "jmsf/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventIsAlreadyAdded::~exception_EventIsAlreadyAdded() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsAlreadyAdded::exception_EventIsAlreadyAdded( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_EventIsAlreadyAdded::exception_EventIsAlreadyAdded( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsAlreadyAdded::exception_EventIsAlreadyAdded( const exception_EventIsAlreadyAdded &other ) throw()
	: mixin_Exception( other )
{}

const exception_EventIsAlreadyAdded &exception_EventIsAlreadyAdded::operator =( const exception_EventIsAlreadyAdded &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
