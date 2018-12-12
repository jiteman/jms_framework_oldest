#pragma once


#include "jmsf/typing/Ansii_string.hxx"
#include "jmsf/typing/Naturals.hxx"

#include "jmsf/typing/Ansii_string.h"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


class JMSF_DLL_INTERFACE File_and_line {

public:
	const typing::Ansii_string &get_filename() const noexept;
	typing::Memory_size get_line_number() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~File_and_line() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line() noexept;

public:
	static File_and_line create( const typing::internals::platform_character_type *a_filename, typing::memory_size_value_type line_number ) noexept;

private:
	File_and_line( const typing::Ansii_string &a_filename, typing::Memory_size line_number ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line( const File_and_line &other ) noexept;

private:
	const File_and_line &operator =( const File_and_line &other ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
 	typing::Ansii_string _filename;
	typing::Memory_size _line_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typing::Ansii_string UNKNOWN_FILENAME;

};


#if !defined( FILE_AND_LINE )

	#define	FILE_AND_LINE ( ::jmsf::validating::File_and_line::create( __FILE__, __LINE__ ) )

#endif


} // namespace debugging
} // namespace jmsf
