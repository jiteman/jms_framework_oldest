#include "Log.h"


#include <iostream>
#include <fstream>
#include <sstream>


namespace jmsf {
namespace validating {


// static
void Log::write( const char *a_message, const char *file_name, const size_t file_line ) noexcept {
	::std::stringstream char_stream;
	char_stream << ::std::endl << "SenSEI => ";
	char_stream << a_message << " in " << file_name << " at " << file_line << ::std::endl;

	::std::ofstream error_log_file( "debug_output.log", ( ::std::ios_base::out | ::std::ios_base::app ) );
	error_log_file << char_stream.str();
}

// static
void Log::write( const char *a_message, const char *a_type, const char *file_name, const size_t file_line ) noexcept {
	::std::stringstream char_stream;
	char_stream << ::std::endl << "SenSEI => ";
	char_stream << a_message << " in " << file_name << " at " << file_line << " for " << a_type << ::std::endl;
	::std::ofstream error_log_file( "debug_output.log", ( ::std::ios_base::out | ::std::ios_base::app ) );
	error_log_file << char_stream.str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Log::~Log() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Log::Log() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Log::Log( const Log &/*another*/ ) noexcept {
}

const Log &Log::operator =( const Log &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf
