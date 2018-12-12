#include "RunnableExceptionInformation.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/TextString.h"
#include "jmsf/Pointers.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace mtf {
namespace exceptions {

Boolean RunnableExceptionInformation::wasException() const throw() {
	return _wasException;
}

const ConstantProxy< TextString > RunnableExceptionInformation::getExceptionMessageText() const throw() {
	return _exceptionMessageText;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
RunnableExceptionInformation::~RunnableExceptionInformation() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Pointer< RunnableExceptionInformation > RunnableExceptionInformation::create( const ConstantProxy< TextString > &message ) throw() {
	RunnableExceptionInformation *runnableExceptionInformation = new RunnableExceptionInformation( message );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( runnableExceptionInformation, MACROS_FILE_AND_LINE ) );
	return Pointer< RunnableExceptionInformation >::createUnique( runnableExceptionInformation );
}

// static
Pointer< RunnableExceptionInformation > RunnableExceptionInformation::create( const Proxy< TextStream > &message ) throw() {
	RunnableExceptionInformation *runnnableExceptionInformation = new RunnableExceptionInformation( message->createTextString() );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( runnnableExceptionInformation, MACROS_FILE_AND_LINE ) );
	return Pointer< RunnableExceptionInformation >::createUnique( runnnableExceptionInformation );
}

RunnableExceptionInformation::RunnableExceptionInformation() throw()
	:
		_exceptionMessageText( CONSTANT_TEXT_STRING( NO_EXCEPTION_INFORMATION_MESSAGE ) )
{
	_wasException = false;
}

RunnableExceptionInformation::RunnableExceptionInformation( const ConstantProxy< TextString > &message ) throw()
	: _exceptionMessageText( message )
{
	_wasException = true;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Pointer< RunnableExceptionInformation > RunnableExceptionInformation::createClone() const throw() {
	RunnableExceptionInformation *runnableExceptionInformation = new RunnableExceptionInformation( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( runnableExceptionInformation, MACROS_FILE_AND_LINE ) );
	return Pointer< RunnableExceptionInformation >::createUnique( runnableExceptionInformation );
}

RunnableExceptionInformation::RunnableExceptionInformation( const RunnableExceptionInformation &other ) throw() // other
	:
		_exceptionMessageText( other._exceptionMessageText->createClone() )
{}

const RunnableExceptionInformation &RunnableExceptionInformation::operator =( const RunnableExceptionInformation &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// statics
const char_type *RunnableExceptionInformation::NO_EXCEPTION_INFORMATION_MESSAGE = "No exception";
const char_type *RunnableExceptionInformation::UNKNOWN_EXCEPTION_INFORMATION_MESSAGE = "No exception information available";
//~statics


} // namespace
}
}
