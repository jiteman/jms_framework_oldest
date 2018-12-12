#pragma once


#include "Ansii_string.h"
//#include "jmsf/memorying/Womp.hpp"
#include "jmsf/structing/containing/List.hpp"

#include "jmsf/memorying/Allocator.hxx"
#include "Ansii_character.hxx"
#include "Integers.hxx"
#include "Naturals.hxx"
#include "Reals.hxx"



#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


// Moving copying and moving copy construction
class JMSF_DLL_INTERFACE Ansii_string_stream {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void put_string( const Ansii_string &a_string ) noexept;
	void put_character( const Ansii_character &a_character ) noexept;

	template< class A_type >
	void put_integer( Integers< A_type > integer_number ) noexept;

	template< class A_type >
	void put_natural( Naturals< A_type > natural_number ) noexept;

	template< class A_type >
	void put_hexadecimal( A_type hexadecimal_number ) noexept;

	template< class A_type >
	void put_real( Reals< A_type > real_number ) noexept;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const structing::containing::List< Ansii_string > &get_ansii_string_list() const noexept;
	Ansii_string create_consolidated_ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_string_stream() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:	
	static Ansii_string_stream create( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_string_stream( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept; // Allocator for ansii_string

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string_stream( const Ansii_string_stream &another ) noexept;
	const Ansii_string_stream &operator =( const Ansii_string_stream &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _character_array_allocator;
	memorying::Womp< memorying::Allocator > _list_node_allocator;
	structing::containing::List< Ansii_string > _ansii_string_list;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void put_integer_32( Integer integer_number ) noexept;
	void put_integer_64( Long_integer integer_number ) noexept;
	void put_natural_32( Natural natural_number ) noexept;
	void put_natural_64( Long_natural natural_number ) noexept;
	void put_hexadecimal_32( Natural hexadecimal_number ) noexept;
	void put_hexadecimal_64( Long_natural hexadecimal_number ) noexept;
	void put_real_double( Real real_number ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


template<>
JMSF_DLL_INTERFACE void Ansii_string_stream::put_integer( const Integers< internals::platform_signed_long_int > integer_number ) noexept;

template<>
JMSF_DLL_INTERFACE void Ansii_string_stream::put_natural( const Naturals< internals::platform_unsigned_long_int > natural_number ) noexept;

template<>
JMSF_DLL_INTERFACE void Ansii_string_stream::put_hexadecimal( const Integers< internals::platform_signed_long_int > hexadecimal_number ) noexept;

template<>
JMSF_DLL_INTERFACE void Ansii_string_stream::put_hexadecimal( const Naturals< internals::platform_unsigned_long_int > hexadecimal_number ) noexept;

template<>
JMSF_DLL_INTERFACE void Ansii_string_stream::put_real( const Reals< short_real_value_type > real_number ) noexept;


} // namespace typing
} // namespace jmsf
