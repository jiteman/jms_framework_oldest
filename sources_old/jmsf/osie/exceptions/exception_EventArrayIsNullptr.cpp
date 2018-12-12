#include "exception_EventArrayIsNullptr.h"


#include "jmsf/texting/TextStream.h"


namespace jmsf {
namespace osie {
namespace exceptions {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_EventArrayIsNullptr::~exception_EventArrayIsNullptr() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventArrayIsNullptr::exception_EventArrayIsNullptr( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_EventArrayIsNullptr::exception_EventArrayIsNullptr( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_EventArrayIsNullptr::exception_EventArrayIsNullptr( const exception_EventArrayIsNullptr &other ) throw()
	: mixin_Exception( other )
{}

const exception_EventArrayIsNullptr &exception_EventArrayIsNullptr::operator =( const exception_EventArrayIsNullptr &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
