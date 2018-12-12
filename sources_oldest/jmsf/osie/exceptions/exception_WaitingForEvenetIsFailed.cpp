#include "exception_WaitingForEvenetIsFailed.h"
#include "jmsf/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_WaitingForEvenetIsFailed::~exception_WaitingForEvenetIsFailed() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_WaitingForEvenetIsFailed::exception_WaitingForEvenetIsFailed( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_WaitingForEvenetIsFailed::exception_WaitingForEvenetIsFailed( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_WaitingForEvenetIsFailed::exception_WaitingForEvenetIsFailed( const exception_WaitingForEvenetIsFailed &other ) throw()
	: mixin_Exception( other )
{}

const exception_WaitingForEvenetIsFailed &exception_WaitingForEvenetIsFailed::operator =( const exception_WaitingForEvenetIsFailed &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
