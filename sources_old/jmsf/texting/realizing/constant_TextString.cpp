#include "constant_TextString.h"


#include "../factory_TextObject.h"

#include "jmsf/validating/FileAndLine.h"

#include "jmsf/typing/Boolean.h"

#include "jmsf/pointing/ConstantPointer.inl"

#include "hiddens/hidden_realization_TextString.h"

//#include "jmsf/Pointers.hpp"
//#include "jmsf/Proxies.hpp"
//#include "jmsf/Should.h"
//#include "jmsf/Boolean.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace texting {
namespace realizations {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const typing::internals::platform_char *constant_TextString::getCtext() const throw() {
	return _constant_c_text;
}

typing::Boolean constant_TextString::isEqual( const pointing::ConstantProxy< TextString > &other ) const throw() {
	hiddens::hidden_realization_TextString *hiddenString = new hiddens::hidden_realization_TextString( _constant_c_text );
	memorying::ObjectMemoryPointer< hiddens::hidden_realization_TextString >( 
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( hiddenString, MACROS_FILE_AND_LINE ) );
	const pointing::ConstantPointer< hiddens::hidden_realization_TextString > textString = pointing::ConstantPointer< hiddens::hidden_realization_TextString >::createUnique( hiddenString );
	return textString->isEqual( other->getCtext() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
constant_TextString::~constant_TextString() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
constant_TextString::constant_TextString( const typing::internals::platform_char *const constant_c_text ) throw()
	: _constant_c_text( constant_c_text )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::ConstantProxy< TextString > constant_TextString::createClone( memorying::Allocator &anAllocator ) const throw() {
	return CONSTANT_TEXT_STRING( anAllocator, _constant_c_text );
}

constant_TextString::constant_TextString( const constant_TextString &other ) throw()
	: _constant_c_text( other._constant_c_text )
{}

const constant_TextString &constant_TextString::operator =( const constant_TextString &other ) throw() {
	if ( this == &other ) return *this;

	//_constant_c_text = other._constant_c_text;
	validating::Should::neverViolateCopyingProhibition( "constant_TextString::opreator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizations
} // namespace texting
} // namespace jmsf
