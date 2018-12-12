#include "realization_TextStream.h"
#include "hiddens/hidden_realization_TextStream.h"
#include "../TextString.h"
#include "../factory_TextObject.h"
#include "../C_Characters.h"
#include "../Proxies.hpp"
#include "../Real.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {


Proxy< TextStream > realization_TextStream::put( const ConstantProxy< TextString > &textString ) throw() {
	_hidden_realization_TextStream->put( textString->getCtext() );
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::putInteger( const integer_big value ) throw() {
	_hidden_realization_TextStream->putInteger( value, _base, _width, _fill );
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::putNatural( const natural_big value ) throw() {
	_hidden_realization_TextStream->putNatural( value, _base, _width, _fill );
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::putReal( const Real &value ) throw() {
	_hidden_realization_TextStream->putReal( value, _base, _width, _fill );
	return Proxy< TextStream >::createNonlinkedFor( this );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const ConstantProxy< TextString > realization_TextStream::createTextString() const throw() {
	return factory_TextObject::instance()->createTextString( _hidden_realization_TextStream->get() );
}

Proxy< TextStream > realization_TextStream::setDecimalBase() throw() {
	_base = 10;
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::setHexadecimalBase() throw() {
	_base = 16;
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::setWidth( const natural_size width ) throw() {
	_width = width;
	return Proxy< TextStream >::createNonlinkedFor( this );
}

Proxy< TextStream > realization_TextStream::setFill( const ConstantProxy< TextString > &fill ) throw() {
	_fill = *fill->getCtext();
	return Proxy< TextStream >::createNonlinkedFor( this );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_TextStream::~realization_TextStream() throw() {
	debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
	delete _hidden_realization_TextStream;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TextStream::realization_TextStream() throw() {
	_hidden_realization_TextStream = new hiddens::hidden_realization_TextStream;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
	_base = 10;
	_width = 0;
	_fill = C_Characters::SPACE_CHAR;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< TextStream > realization_TextStream::createClone() const throw() {
	realization_TextStream *textStream = new realization_TextStream( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textStream, MACROS_FILE_AND_LINE ) );
	return Proxy< TextStream >::createUnique( textStream );
}

realization_TextStream::realization_TextStream( const realization_TextStream &other ) throw() {
	_hidden_realization_TextStream = new hiddens::hidden_realization_TextStream( *other._hidden_realization_TextStream );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
	_base = other._base;
	_width = other._width;
	_fill = other._fill;
}

const realization_TextStream &realization_TextStream::operator =( const realization_TextStream &other ) throw() {
	if ( this == &other ) return *this;

	_base = other._base;
	_width = other._width;
	_fill = other._fill;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
