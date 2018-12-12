#include "exception_UnableToCreateThread.h"
#include "jmsf/TextStream.h"
#include "jmsf/Proxy.hpp"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_UnableToCreateThread::~exception_UnableToCreateThread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnableToCreateThread::exception_UnableToCreateThread( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_UnableToCreateThread::exception_UnableToCreateThread( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason )
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
