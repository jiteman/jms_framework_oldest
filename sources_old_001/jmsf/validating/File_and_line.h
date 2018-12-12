#pragma once


#include "jmsf/typeing/Ansii_string.hxx"
#include "jmsf/typeing/Naturals.hxx"

#include "jmsf/typeing/Ansii_string.h"

#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace validating {


// SenSEI: key idea - creating/using speed tradeoff - desided to use fast creation and slow using
// (storing as pointer to char, returning as Ansii_string
// reason - quantity of calls to validating::Should is maxed out, while using the contents of File_and_line
// happens in case of error only (several times)
class JMSF_SHARED_INTERFACE File_and_line {

public:
	typeing::Ansii_string get_filename() const;
	typeing::Memory_natural get_line_number() const noexcept;
	const typeing::internals::platform_character *get_debug_filename() const noexcept;
	typeing::memory_natural_value_type get_debug_line_number() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~File_and_line() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line() noexcept;

public:
	static File_and_line create( const typeing::internals::platform_character *a_filename, typeing::memory_natural_value_type line_number ) noexcept;

private:
	File_and_line( const typeing::internals::platform_character *a_filename, typeing::memory_natural_value_type line_number ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	File_and_line( const File_and_line &other ) noexcept;

private:
	const File_and_line &operator =( const File_and_line &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const typeing::internals::platform_character *_filename;
	typeing::memory_natural_value_type _line_number;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const typeing::internals::platform_character *const UNKNOWN_FILENAME;

public:
	static const File_and_line EMPTY_FILE_AND_LINE; // optimization (for the case if we don't realy need file and line)

};


} // namespace debugging
} // namespace jmsf


#include "jmsf/validating/logging_flags.h"


#if !defined( JMSF_FILE_AND_LINE )

	#define	JMSF_FILE_AND_LINE \
		( ::jmsf::validating::File_and_line::create( __FILE__, __LINE__ ) )

	#define	JMSF_FILE_AND_LINE_OPTIONAL( boolean_expression ) \
		( boolean_expression ) ? ( ::jmsf::validating::File_and_line::create( __FILE__, __LINE__ ) ) : ( ::jmsf::validating::File_and_line::EMPTY_FILE_AND_LINE )

#endif
