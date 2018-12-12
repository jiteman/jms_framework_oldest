#include "realization_factory_TextObject.h"
#include "realization_TextString.h"
#include "constant_TextString.h"
#include "realization_TextStream.h"
#include "../Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {
	
ConstantProxy< TextString > realization_factory_TextObject::createTextString() const throw() {
	return createTextString( nullptr );
}

ConstantProxy< TextString > realization_factory_TextObject::createTextString( const char *const c_text ) const throw() {
	realization_TextString *textString = new realization_TextString( c_text );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textString, MACROS_FILE_AND_LINE ) );
	return ConstantProxy< TextString >::createUnique( textString );
}

ConstantProxy< TextString > realization_factory_TextObject::createConstantTextString() const throw() {
	return createTextString( nullptr );
}

ConstantProxy< TextString > realization_factory_TextObject::createConstantTextString( const char *c_text ) const throw() {
	constant_TextString *textString = new constant_TextString( c_text );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textString, MACROS_FILE_AND_LINE ) );
	return ConstantProxy< TextString >::createUnique( textString );
}

Proxy< TextStream > realization_factory_TextObject::createTextStream() const throw() {
	realization_TextStream *textStream = new realization_TextStream;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textStream, MACROS_FILE_AND_LINE ) );
	return Proxy< TextStream >::createUnique( textStream );
}


realization_factory_TextObject::~realization_factory_TextObject() throw()
{}

realization_factory_TextObject::realization_factory_TextObject() throw()
{}

} // namespace
}
