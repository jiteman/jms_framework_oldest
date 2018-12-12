#include "exception_EventIsNullptr.h"


#include "jmsf/texting/TextStream.h"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventIsNullptr::~exception_EventIsNullptr() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventIsNullptr::exception_EventIsNullptr( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_EventIsNullptr::exception_EventIsNullptr( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
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
