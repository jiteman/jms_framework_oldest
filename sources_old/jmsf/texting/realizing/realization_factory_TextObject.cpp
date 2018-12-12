#include "realization_factory_TextObject.h"


#include "realization_TextString.h"
#include "constant_TextString.h"
#include "realization_TextStream.h"

#include "jmsf/pointing/ConstantProxy.hpp"
#include "jmsf/pointing/Proxy.hpp"

#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/Allocator.h"

//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace texting {
namespace realizations {


pointing::ConstantProxy< TextString > realization_factory_TextObject::createTextString( memorying::Allocator &anAllocator ) const throw() {
	return createTextString( anAllocator, nullptr );
}

pointing::ConstantProxy< TextString > realization_factory_TextObject::createTextString( memorying::Allocator &anAllocator, const char *const c_text ) const throw() {
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textString, MACROS_FILE_AND_LINE ) );
	return pointing::ConstantProxy< TextString >::createUnique( memorying::Constructor< TextString, realization_TextString >::construct( anAllocator, c_text ) );
}

pointing::ConstantProxy< TextString > realization_factory_TextObject::createConstantTextString( memorying::Allocator &anAllocator ) const throw() {
	return createTextString( anAllocator, nullptr );
}

pointing::ConstantProxy< TextString > realization_factory_TextObject::createConstantTextString( memorying::Allocator &anAllocator, const char *c_text ) const throw() {
	return pointing::ConstantProxy< TextString >::createUnique( memorying::Constructor< TextString, constant_TextString >::construct( anAllocator, c_text ) );
}

pointing::Proxy< TextStream > realization_factory_TextObject::createTextStream( memorying::Allocator &anAllocator ) const throw() {
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textStream, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< TextStream >::createUnique( memorying::Constructor< TextStream, realization_TextStream >::construct( anAllocator ) );
}


realization_factory_TextObject::~realization_factory_TextObject() throw()
{}

realization_factory_TextObject::realization_factory_TextObject() throw()
{}


} // namespace realizations
} // namespace texting
} // namespace jmsf
