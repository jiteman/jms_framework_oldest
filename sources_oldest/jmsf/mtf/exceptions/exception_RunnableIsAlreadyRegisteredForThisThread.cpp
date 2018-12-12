#include "exception_RunnableIsAlreadyRegisteredForThisThread.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace mtf {
namespace exceptions {


// static
const char_type *exception_RunnableIsAlreadyRegisteredForThisThread::EXCEPTION_MESSAGE_exception_RunnableIsAlreadyRegisteredForThisThread = " - exception_RunnableIsAlreadyRegisteredForThisThread";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_RunnableIsAlreadyRegisteredForThisThread::~exception_RunnableIsAlreadyRegisteredForThisThread() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_RunnableIsAlreadyRegisteredForThisThread::exception_RunnableIsAlreadyRegisteredForThisThread( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_RunnableIsAlreadyRegisteredForThisThread ) ) )
{}

exception_RunnableIsAlreadyRegisteredForThisThread::exception_RunnableIsAlreadyRegisteredForThisThread( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_RunnableIsAlreadyRegisteredForThisThread ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_RunnableIsAlreadyRegisteredForThisThread::exception_RunnableIsAlreadyRegisteredForThisThread( const exception_RunnableIsAlreadyRegisteredForThisThread &other ) throw()
	: mixin_Exception( other )
{}

const exception_RunnableIsAlreadyRegisteredForThisThread &exception_RunnableIsAlreadyRegisteredForThisThread::operator =( const exception_RunnableIsAlreadyRegisteredForThisThread &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace exceptions
} // namespace mtf
} // namespace jmsf
