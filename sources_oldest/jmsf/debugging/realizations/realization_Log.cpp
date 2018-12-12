#include "realization_Log.h"
#include "jmsf/exceptions/exception_CantOpenFile.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/Real.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace debugging {
namespace realizations {

void realization_Log::putWithEol( const ConstantProxy< TextString > &message ) throw() {
	put( message );
	putEol();
}

Proxy< Log > realization_Log::put( const ConstantProxy< TextString > &message ) throw() {
	_logFile << message->getCtext();
	return Proxy< Log >::createNonlinkedFor( this );
}

void realization_Log::putEol() throw() {
	_logFile << std::endl;
}

Proxy< Log > realization_Log::putInteger( const integer_big value ) throw() {
	_logFile << value;
	return Proxy< Log >::createNonlinkedFor( this );
}

Proxy< Log > realization_Log::putNatural( const natural_big value ) throw() {
	_logFile << value;
	return Proxy< Log >::createNonlinkedFor( this );
}

Proxy< Log > realization_Log::putReal( const Real &value ) throw() {
	_logFile << value.getValue();
	return Proxy< Log >::createNonlinkedFor( this );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Log::~realization_Log() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Log::realization_Log( const ConstantProxy< TextString > &pathToLogFile ) throw( Exception )
	:
		_logFile( pathToLogFile->getCtext() )
{
	if ( Boolean( _logFile.is_open() ).not() ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "realization_Log::realization_Log() - " ) )->put( pathToLogFile );
		throw exceptions::exception_CantOpenFile( textStream );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< Log > realization_Log::createClone() const throw() {
	realization_Log *log = new realization_Log( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( log, MACROS_FILE_AND_LINE ) );
	return Proxy< Log >::createUnique( log );
}

realization_Log::realization_Log( const realization_Log & ) throw() // other
{}

const realization_Log &realization_Log::operator =( const realization_Log &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "realization_Log::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace debugging
} // namespace jmsf
