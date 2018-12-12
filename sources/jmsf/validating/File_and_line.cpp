#include "File_and_line.h"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace validating {


const typing::Ansii_string &File_and_line::get_filename() const noexept {
	return _filename;
}

typing::Memory_size File_and_line::get_line_number() const noexept {
	return _line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
File_and_line::~File_and_line() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line() noexept
	:
		_filename( typing::Ansii_string::create_from_another( memorying::Womp< memorying::Allocator >(), UNKNOWN_FILENAME ) ),
		_line_number( typing::Memory_size_badmax )
{}

// static
File_and_line File_and_line::create( const typing::internals::platform_character_type *a_filename, typing::memory_size_value_type line_number ) noexept {
	return File_and_line( typing::Ansii_string::create_from_constant_literal( a_filename ), typing::Memory_size::create( line_number ) );
}

File_and_line::File_and_line( const typing::Ansii_string &a_filename, const typing::Memory_size line_number ) noexept
	:
		_filename( a_filename ),
		_line_number( line_number )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line( const File_and_line &other ) noexept // other
	:
		_filename( other._filename ),
		_line_number( other._line_number )
{}

const File_and_line &File_and_line::operator =( const File_and_line &other ) noexept {
	if ( &other != this ) {
// 		_filename = other._filename->createClone();
// 		_lineNumber = other._lineNumber;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
typing::Ansii_string File_and_line::UNKNOWN_FILENAME = typing::Ansii_string::create_from_constant_literal( "Filename is unknown" );

} // namespace validating
} // namespace jmsf
