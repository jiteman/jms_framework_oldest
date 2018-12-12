#include "factory_TextObject.h"


#include "TextString.h"
#include "realizing/realization_factory_TextObject.h"

#include "jmsf/pointing/ConstantProxy.hpp"
#include "jmsf/pointing/Proxy.hpp"

//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace texting {


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

} // namespace texting
} // namespace jmsf


namespace jmsf {


pointing::ConstantProxy< texting::TextString > TEXT_STRING( memorying::Allocator &anAllocator, const typing::internals::platform_char *const c_text ) {
	return texting::factory_TextObject::instance()->createTextString( anAllocator, c_text );
}

pointing::ConstantProxy< texting::TextString > CONSTANT_TEXT_STRING( memorying::Allocator &anAllocator, const typing::internals::platform_char *const constant_c_text ) {
	return texting::factory_TextObject::instance()->createConstantTextString( anAllocator, constant_c_text );
}


} // namespace jmsf
