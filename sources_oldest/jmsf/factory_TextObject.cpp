#include "factory_TextObject.h"
#include "TextString.h"
#include "realizations/realization_factory_TextObject.h"
#include "Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_TextObject::~factory_TextObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_TextObject *factory_TextObject::createInstance() throw() {
	realizations::realization_factory_TextObject *factoryTextObject = new realizations::realization_factory_TextObject;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryTextObject, MACROS_FILE_AND_LINE ) );
	return factoryTextObject;
}

factory_TextObject::factory_TextObject() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_TextObject::factory_TextObject( const factory_TextObject &  ) throw() // other
{}

const factory_TextObject &factory_TextObject::operator =( const factory_TextObject &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace


namespace jmsf {

ConstantProxy< TextString > TEXT_STRING( const char_type *const c_text ) {
	return factory_TextObject::instance()->createTextString( c_text );
}

ConstantProxy< TextString > CONSTANT_TEXT_STRING( const char_type *const constant_c_text ) {
	return factory_TextObject::instance()->createConstantTextString( constant_c_text );
}

} // namespace
