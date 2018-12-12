#include "exception_EventListIsEmpty.h"


#include "jmsf/texting/TextStream.h"
#include "jmsf/pointing/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventListIsEmpty::~exception_EventListIsEmpty() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventListIsEmpty::exception_EventListIsEmpty( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_EventListIsEmpty::exception_EventListIsEmpty( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
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
