#include "File_and_line.h"

#include "jmsf/typeing/Ansii_string.h"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/logging_flags.h"


#if defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )
	#include "Log.h"

#endif


namespace jmsf {
namespace validating {


typeing::Ansii_string File_and_line::get_filename() const {
	return AS_string_literal( _filename );
}

typeing::Memory_natural File_and_line::get_line_number() const noexcept {
	return typeing::Memory_natural::create( _line_number );
}

const typeing::internals::platform_character *File_and_line::get_debug_filename() const noexcept {
	return _filename;
}

typeing::memory_natural_value_type File_and_line::get_debug_line_number() const noexcept {
	return _line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
File_and_line::~File_and_line() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line() noexcept
	:
		_filename( UNKNOWN_FILENAME ),
		_line_number( ~typeing::memory_natural_value_type( 0 ) )
{}

// static
File_and_line File_and_line::create( const typeing::internals::platform_character *const a_filename, const typeing::memory_natural_value_type line_number ) noexcept {
//	JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT( "File_and_line::create( %filename%, %line_number% )" );

#if defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )
	Log::write( "File_and_line::create( %filename%, %line_number% ) parameters", a_filename, line_number );

#endif

	return File_and_line( a_filename, line_number );
}

File_and_line::File_and_line( const typeing::internals::platform_character *const a_filename, const typeing::memory_natural_value_type line_number ) noexcept
	:
		_filename( a_filename ),
		_line_number( line_number )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
File_and_line::File_and_line( const File_and_line &other ) noexcept // other
	:
		_filename( other._filename ),
		_line_number( other._line_number )
{}

const File_and_line &File_and_line::operator =( const File_and_line &other ) noexcept {
	if ( &other == this ) return *this;

	_filename = other._filename;
	_line_number = other._line_number;
return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const typeing::internals::platform_character *const File_and_line::UNKNOWN_FILENAME = "Filename is unknown";

// static
const File_and_line File_and_line::EMPTY_FILE_AND_LINE( __FILE__, __LINE__ );


} // namespace validating
} // namespace jmsf
