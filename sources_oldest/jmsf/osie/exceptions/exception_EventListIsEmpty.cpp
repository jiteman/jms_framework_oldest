#include "exception_EventListIsEmpty.h"
#include "jmsf/TextStream.h"
#include "jmsf/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventListIsEmpty::~exception_EventListIsEmpty() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventListIsEmpty::exception_EventListIsEmpty( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_EventListIsEmpty::exception_EventListIsEmpty( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventListIsEmpty::exception_EventListIsEmpty( const exception_EventListIsEmpty &other ) throw()
	: mixin_Exception( other )
{}

const exception_EventListIsEmpty &exception_EventListIsEmpty::operator =( const exception_EventListIsEmpty &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
