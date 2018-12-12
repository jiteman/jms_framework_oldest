#include "factory_DebuggingObject.h"
#include "realizations/realization_factory_DebuggingObject.h"
#include "jmsf/Should.h"
#include "ObjectCreationLogging.h"

namespace jmsf {
namespace debugging {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_DebuggingObject::~factory_DebuggingObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_DebuggingObject *factory_DebuggingObject::createInstance() throw() {
	factory_DebuggingObject *factoryDebuggingObject = new realizations::realization_factory_DebuggingObject;
	static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryDebuggingObject, MACROS_FILE_AND_LINE ) );
	return factoryDebuggingObject;
}

factory_DebuggingObject::factory_DebuggingObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_DebuggingObject::factory_DebuggingObject( const factory_DebuggingObject & ) throw() // other
{}

const factory_DebuggingObject &factory_DebuggingObject::operator =( const factory_DebuggingObject &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "factory_DebuggingObject::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace debugging
} // namespace jmsf
