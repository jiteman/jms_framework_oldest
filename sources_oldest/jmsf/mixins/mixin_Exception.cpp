#include "mixin_Exception.h"


#include "../TextStream.h"
#include "../TextString.h"

#include "../Should.h"


namespace jmsf {
namespace mixins {


const ConstantProxy< TextString > &mixin_Exception::getName() const throw() {
	return _name;
}

const ConstantProxy< TextString > &mixin_Exception::getFilename() const throw() {
	return _filename;
}

const types::Natural mixin_Exception::getLineNumber() const throw() {
	return _lineNumber;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Exception::~mixin_Exception() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const ConstantProxy< TextString > &name, const ConstantProxy< TextString > filename, const types::Natural lineNumber ) throw()
	:
		_name( name ),
		_filename( filename ),
		_lineNumber( lineNumber )
{}

mixin_Exception::mixin_Exception( const Proxy< TextStream > &name, const ConstantProxy< TextString > filename, const types::Natural lineNumber ) throw()
	:
		_name( name->createClone() ),
		_filename( filename->createClone() ),
		_lineNumber( lineNumber )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const mixin_Exception &other ) throw()
	:
		_name( other._name->createClone() ),
		_filename( other._filename->createClone() ),
		_lineNumber( other._lineNumber )
{}

const mixin_Exception &mixin_Exception::operator =( const mixin_Exception &other ) throw( Exception ) {
	Should::neverViolateCopyingProhibition( "mixin_Exception::operator =()" );
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
