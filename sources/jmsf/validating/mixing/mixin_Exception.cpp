#include "mixin_Exception.h"


#include "jmsf/validating/Should.h"
#include "jmsf/validating//File_and_line.h"


namespace jmsf {
namespace validating {
namespace mixing {


const typing::Ansii_string &mixin_Exception::get_description() const throw() {
	return _theDescription;
}

const typing::Ansii_string &mixin_Exception::get_filename() const throw() {
	return _filename;
}

typing::Natural mixin_Exception::get_line_number() const throw() {
	return _lineNumber;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Exception::~mixin_Exception() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const typing::Ansii_string &aDescription, const File_and_line &fileAndLine ) throw()
	:
		_theDescription( aDescription ),
		_filename( fileAndLine.get_filename() ),
		_lineNumber( fileAndLine.get_line_number() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Exception::mixin_Exception( const mixin_Exception &another ) throw()
	:
		_theDescription( another._theDescription ),
		_filename( another._filename ),
		_lineNumber( another._lineNumber )
{}

const mixin_Exception &mixin_Exception::operator =( const mixin_Exception &other ) throw( validating::Exception ) {
	Should::never_violate_copy_prohibition( "mixin_Exception::operator =()", FILE_AND_LINE );
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mixing
} // namespace validating
} // namespace jmsf
