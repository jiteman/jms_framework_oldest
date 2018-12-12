#pragma once


#include "jmsf/memorying/Amp.hpp"

#include "Naturals.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Wamp.hxx"
#include "jmsf/structing/containing/List.hxx"
#include "jmsf/typing/internals/internal_types.h"
#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace typing {


// Moving copying and moving copy construction
class JMSF_DLL_INTERFACE Ansii_string {

public:
	const memorying::Amp< internals::platform_character_type > get_as_C_string( const memorying::Womp< memorying::Allocator > character_array_allocator ) const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
public:
	Boolean is_empty() const noexept;
	Boolean is_not_empty() const noexept;
	Memory_size get_quantity() const noexept;	
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean is_equal( const Ansii_string &another ) const noexept;
	Boolean is_not_equal( const Ansii_string &another ) const noexept;
	Boolean is_same( const Ansii_string &another ) const noexept;
	Boolean is_not_same( const Ansii_string &another ) const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_string() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Ansii_string create_from_constant_literal( const internals::platform_character_type *characters ) noexept;
	static Ansii_string create_empty( const memorying::Womp< memorying::Allocator > &character_array_allocator ) noexept;
	static Ansii_string create_from_c_language_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character_type *characters ) noexept;
	static Ansii_string create_from_buffer( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character_type *characters, Memory_size quantity_of_characters ) noexept;
	static Ansii_string create_from_another( const memorying::Womp< memorying::Allocator > &character_array_allocator, const Ansii_string &another ) noexept;
	static Ansii_string create_from_list( const memorying::Womp< memorying::Allocator > &character_array_allocator, const structing::containing::List< Ansii_string > &ansii_string_list ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_string( const memorying::Womp< memorying::Allocator > &an_allocator ) noexept;
	Ansii_string( const memorying::Womp< memorying::Allocator > &an_allocator, const memorying::Wamp< internals::platform_character_type > &character_array ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string( const Ansii_string &another ) noexept;

private:
	const Ansii_string &operator =( const Ansii_string &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Amp< internals::platform_character_type > _character_array_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static typing::Memory_size count_quantity_of_characters( const internals::platform_character_type *characters ) noexept;
	static Memory_size count_total_size_of_strings( const structing::containing::List< Ansii_string > &ansii_string_list ) noexept;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:	

};


} // namespace typing
} // namespace jmsf


namespace jmsf {


JMSF_DLL_INTERFACE typing::Ansii_string AS_string_literal( const typing::internals::platform_character_type *characters ) noexept;
JMSF_DLL_INTERFACE typing::Ansii_string AS_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const typing::internals::platform_character_type *characters ) noexept;


} // namespace jmsf
