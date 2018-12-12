#include "realization_TextStream.h"


#include "hiddens/hidden_realization_TextStream.h"

#include "../factory_TextObject.h"
#include "../TextString.h"

#include "C_Characters.h"

#include "jmsf/pointing/Proxy.hpp"

#include "jmsf/typing/Integer.h"
#include "jmsf/typing/LongInteger.h"
#include "jmsf/typing/LongNatural.h"
#include "jmsf/typing/ShortReal.h"
#include "jmsf/typing/Real.h"

#include "jmsf/memorying/Constructor.inl"


//#include "../Real.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace texting {
namespace realizations {


pointing::Proxy< TextStream > realization_TextStream::put( const pointing::ConstantProxy< TextString > &textString ) throw() {
	_hidden_realization_TextStream->put( textString->getCtext() );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putInteger( const typing::Integer value ) throw() {
	_hidden_realization_TextStream->putInteger( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putInteger( const typing::LongInteger value ) throw() {
	_hidden_realization_TextStream->putInteger( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putNatural( const typing::Natural value ) throw() {
	_hidden_realization_TextStream->putNatural( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putNatural( const typing::LongNatural value ) throw() {
	_hidden_realization_TextStream->putNatural( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putReal( const typing::ShortReal &value ) throw() {
	_hidden_realization_TextStream->putReal( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::putReal( const typing::Real &value ) throw() {
	_hidden_realization_TextStream->putReal( value, _base, _width, _fill );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::ConstantProxy< TextString > realization_TextStream::createTextString( memorying::Allocator &anAllocator ) const throw() {
	return factory_TextObject::instance()->createTextString( anAllocator, _hidden_realization_TextStream->get() );
}

pointing::Proxy< TextStream > realization_TextStream::setDecimalBase() throw() {
	_base = typing::ShortestNatural::create( 10 );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::setHexadecimalBase() throw() {
	_base = typing::ShortestNatural::create( 16 );
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::setWidth( const typing::Natural width ) throw() {
	_width = width;
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

pointing::Proxy< TextStream > realization_TextStream::setFill( const pointing::ConstantProxy< TextString > &fill ) throw() {
	_fill = *fill->getCtext();
	return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< realization_TextStream >() ) );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_TextStream::~realization_TextStream() throw() {
//	debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
	delete _hidden_realization_TextStream;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_TextStream::realization_TextStream() throw() {
	_hidden_realization_TextStream = new hiddens::hidden_realization_TextStream;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
	_base = typing::ShortestNatural::create( 10 );
//	_width = 0;
	_fill = C_Characters::SPACE_CHAR;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< TextStream > realization_TextStream::createClone( memorying::Allocator &anAllocator ) const throw() {
//	realization_TextStream *textStream = new realization_TextStream( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( textStream, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< TextStream >::createUnique( memorying::Constructor< TextStream, realization_TextStream >::construct( anAllocator, *this ) );
}

realization_TextStream::realization_TextStream( const realization_TextStream &other ) throw() {
	_hidden_realization_TextStream = new hiddens::hidden_realization_TextStream( *other._hidden_realization_TextStream );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _hidden_realization_TextStream, MACROS_FILE_AND_LINE ) );
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


} // namespace realizations
} // namespace texting
} // namespace jmsf
