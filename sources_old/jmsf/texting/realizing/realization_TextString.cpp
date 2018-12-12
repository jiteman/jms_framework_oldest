#include "realization_TextString.h"

#include "hiddens/hidden_realization_TextString.h"

// #include "jmsf/Proxies.hpp"
#include "jmsf/typing/Boolean.h"
#include "../factory_TextObject.h"

#include "jmsf/validating/FileAndLine.h"


namespace jmsf {
namespace texting {
namespace realizations {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const typing::internals::platform_char *realization_TextString::getCtext() const throw() {
	return _hidden_realizationementation_TextString->get();
}

typing::Boolean realization_TextString::isEqual( const pointing::ConstantProxy< TextString > &other ) const throw() {
	return _hidden_realizationementation_TextString->isEqual( other->getCtext() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_TextString::~realization_TextString() throw() {
//	debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
	delete _hidden_realizationementation_TextString;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TextString::realization_TextString( const typing::internals::platform_char *const c_text ) throw() {
	_hidden_realizationementation_TextString = new hiddens::hidden_realization_TextString( c_text );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::ConstantProxy< TextString > realization_TextString::createClone() const throw() {
	return TEXT_STRING( _hidden_realizationementation_TextString->get() );	
}

realization_TextString::realization_TextString( const realization_TextString &other ) throw() {
	_hidden_realizationementation_TextString = new hiddens::hidden_realization_TextString( *other._hidden_realizationementation_TextString );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
}

const realization_TextString &realization_TextString::operator =( const realization_TextString &other ) throw() {
	if ( this == &other ) return *this;

	// *_hidden_realizationementation_TextString = *other._hidden_realizationementation_TextString;
	validating::Should::neverViolateCopyingProhibition( "realization_TextString::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace texting
} // namespace jmsf
