#include "constant_TextString.h"
#include "hiddens/hidden_realization_TextString.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Pointers.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/Boolean.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const char_type *constant_TextString::getCtext() const throw() {
	return _constant_c_text;
}

Boolean constant_TextString::isEqual( const ConstantProxy< TextString > &other ) const throw() {
	hiddens::hidden_realization_TextString *hiddenString = new hiddens::hidden_realization_TextString( _constant_c_text );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( hiddenString, MACROS_FILE_AND_LINE ) );
	const ConstantPointer< hiddens::hidden_realization_TextString > textString = ConstantPointer< hiddens::hidden_realization_TextString >::createUnique( hiddenString );
	return textString->isEqual( other->getCtext() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
constant_TextString::~constant_TextString() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
constant_TextString::constant_TextString( const char_type *const constant_c_text ) throw()
	: _constant_c_text( constant_c_text )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ConstantProxy< TextString > constant_TextString::createClone() const throw() {
	return CONSTANT_TEXT_STRING( _constant_c_text );
}

constant_TextString::constant_TextString( const constant_TextString &other ) throw()
	: _constant_c_text( other._constant_c_text )
{}

const constant_TextString &constant_TextString::operator =( const constant_TextString &other ) throw() {
	if ( this == &other ) return *this;

	//_constant_c_text = other._constant_c_text;
	Should::neverViolateCopyingProhibition( "constant_TextString::opreator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
