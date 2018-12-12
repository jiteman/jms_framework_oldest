#include "exception_EventIsAlreadyAdded.h"


#include "jmsf/pointing/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventIsAlreadyAdded::~exception_EventIsAlreadyAdded() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsAlreadyAdded::exception_EventIsAlreadyAdded( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_EventIsAlreadyAdded::exception_EventIsAlreadyAdded( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
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
