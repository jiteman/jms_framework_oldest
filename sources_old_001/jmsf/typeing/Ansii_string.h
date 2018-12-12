#pragma once


#include "jmsf/memorying/Amp.hpp"

#include "jmsf/typeing/internals/internal_types.h"

#include "Native_C_string.hxx"
#include "jmsf/structing/containing/List.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Wamp.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "Naturals.hxx"
#include "Boolean.hxx"

#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"

#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"


namespace jmsf {
namespace typeing {


// Moving copying and moving copy construction
class JMSF_SHARED_INTERFACE Ansii_string {

public:
	Native_C_string get_as_native_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_empty() const noexcept;
	Boolean is_not_empty() const noexcept;
	Memory_natural get_quantity() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_equal( const Ansii_string &another ) const noexcept;
	Boolean is_not_equal( const Ansii_string &another ) const noexcept;
	Boolean is_same( const Ansii_string &another ) const noexcept;
	Boolean is_not_same( const Ansii_string &another ) const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_string() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Ansii_string create_from_constant_literal( const internals::platform_character *characters );
//	static Ansii_string create_empty( const memorying::Womp< memorying::Allocator > &character_array_allocator ) noexcept;
	static Ansii_string create_from_c_language_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character *characters );
	static Ansii_string create_from_native_buffer( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character *characters, Memory_natural quantity_of_characters );
	static Ansii_string create_from_another( const memorying::Womp< memorying::Allocator > &character_array_allocator, const Ansii_string &another );
	static Ansii_string create_from_list( const memorying::Womp< memorying::Allocator > &character_array_allocator, const structing::containing::List< Ansii_string > &ansii_string_list );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Ansii_string( const memorying::Womp< memorying::Allocator > &an_allocator ) noexcept;
	Ansii_string( const memorying::Womp< memorying::Allocator > &an_allocator, typeing::Memory_natural a_quantity ) noexcept;
	Ansii_string( const memorying::Womp< memorying::Allocator > &an_allocator, const memorying::Wamp< internals::platform_character > &character_array ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string( const Ansii_string &another ) noexcept;

public:
	Ansii_string( Ansii_string &&another ) noexcept;

private:
	const Ansii_string &operator =( const Ansii_string &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Amp< internals::platform_character > _character_array_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Memory_natural count_quantity_of_characters( const internals::platform_character *characters ) noexcept;
	static Memory_natural count_total_size_of_strings( const structing::containing::List< Ansii_string > &ansii_string_list ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {


JMSF_SHARED_INTERFACE typeing::Ansii_string AS_string_literal( const typeing::internals::platform_character *characters ) noexcept;

JMSF_SHARED_INTERFACE typeing::Ansii_string AS_C_string(
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const typeing::internals::platform_character *characters ) noexcept;


} // namespace jmsf
