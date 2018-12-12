#include "exception_WaitingForEvenetIsFailed.h"


#include "jmsf/pointing/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_WaitingForEvenetIsFailed::~exception_WaitingForEvenetIsFailed() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_WaitingForEvenetIsFailed::exception_WaitingForEvenetIsFailed( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_WaitingForEvenetIsFailed::exception_WaitingForEvenetIsFailed( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
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
