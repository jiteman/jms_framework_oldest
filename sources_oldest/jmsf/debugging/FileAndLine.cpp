#include "FileAndLine.h"


namespace jmsf {
namespace debugging {


const ConstantProxy< TextString > &FileAndLine::getFilename() const throw() {
	return _filename;
}

const types::Natural FileAndLine::getLineNumber() const throw() {
	return _lineNubmer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
FileAndLine::~FileAndLine() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FileAndLine::FileAndLine( const ConstantProxy< TextString > &filename, const types::Natural lineNumber ) throw()
	:
		_filename( filename->createClone() ),
		_lineNumber( lineNumber )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FileAndLine::FileAndLine( const FileAndLine &other ) throw() // other
	:
		_filename( other._filename->createClone() ),
		_lineNumber( other._lineNumber )
{}

const FileAndLine &FileAndLine::operator =( const FileAndLine &other ) throw() {
	if ( &other != this ) {
		_filename = other._filename->createClone();
		_lineNumber = other._lineNumber;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace debugging
} // namespace jmsf
