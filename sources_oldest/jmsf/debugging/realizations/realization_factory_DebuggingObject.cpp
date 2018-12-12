#include "realization_factory_DebuggingObject.h"
#include "realization_Log.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace debugging {
namespace realizations {

Proxy< Log > realization_factory_DebuggingObject::createLog( const ConstantProxy< TextString > &pathToLogFile ) const throw() {
	realization_Log *log = new realization_Log( pathToLogFile );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( log, MACROS_FILE_AND_LINE ) );
	return Proxy< Log >::createUnique( log );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_DebuggingObject::~realization_factory_DebuggingObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_DebuggingObject::realization_factory_DebuggingObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_DebuggingObject::realization_factory_DebuggingObject( const realization_factory_DebuggingObject & ) throw() // other
{}

const realization_factory_DebuggingObject &realization_factory_DebuggingObject::operator =( const realization_factory_DebuggingObject &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_factory_DebuggingObject::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace debugging
} // namespace jmsf
