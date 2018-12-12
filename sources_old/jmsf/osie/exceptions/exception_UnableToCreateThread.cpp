#include "exception_UnableToCreateThread.h"


#include "jmsf/texting/TextStream.h"
#include "jmsf/pointing/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_UnableToCreateThread::~exception_UnableToCreateThread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnableToCreateThread::exception_UnableToCreateThread( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

exception_UnableToCreateThread::exception_UnableToCreateThread( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnableToCreateThread::exception_UnableToCreateThread( const exception_UnableToCreateThread &other ) throw()
	: mixin_Exception( other )
{}

const exception_UnableToCreateThread &exception_UnableToCreateThread::operator =( const exception_UnableToCreateThread &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
