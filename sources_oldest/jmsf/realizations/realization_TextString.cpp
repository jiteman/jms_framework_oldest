#include "realization_TextString.h"
#include "hiddens/hidden_realization_TextString.h"
#include "../Proxies.hpp"
#include "../Boolean.h"
#include "../factory_TextObject.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const char_type *realization_TextString::getCtext() const throw() {
	return _hidden_realizationementation_TextString->get();
}

Boolean realization_TextString::isEqual( const ConstantProxy< TextString > &other ) const throw() {
	return _hidden_realizationementation_TextString->isEqual( other->getCtext() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_TextString::~realization_TextString() throw() {
	debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
	delete _hidden_realizationementation_TextString;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TextString::realization_TextString( const char_type *const c_text ) throw() {
	_hidden_realizationementation_TextString = new hiddens::hidden_realization_TextString( c_text );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ConstantProxy< TextString > realization_TextString::createClone() const throw() {
	return TEXT_STRING( _hidden_realizationementation_TextString->get() );	
}

realization_TextString::realization_TextString( const realization_TextString &other ) throw() {
	_hidden_realizationementation_TextString = new hiddens::hidden_realization_TextString( *other._hidden_realizationementation_TextString );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realizationementation_TextString, MACROS_FILE_AND_LINE ) );
}

const realization_TextString &realization_TextString::operator =( const realization_TextString &other ) throw() {
	if ( this == &other ) return *this;

	// *_hidden_realizationementation_TextString = *other._hidden_realizationementation_TextString;
	Should::neverViolateCopyingProhibition( "realization_TextString::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
