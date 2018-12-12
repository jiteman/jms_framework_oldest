#pragma once


#include "Ansii_string.h"
//#include "jmsf/memorying/Womp.hpp"
#include "jmsf/structing/containing/List.hpp"

#include "jmsf/memorying/Allocator.hxx"
#include "Ansii_character.hxx"
#include "Integers.hxx"
#include "Naturals.hxx"
#include "Reals.hxx"


#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace typeing {


// Moving copying and moving copy construction
class JMSF_SHARED_INTERFACE Ansii_string_stream {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void put_string( const Ansii_string &a_string );
	void put_character( const Ansii_character &a_character ) noexcept;

	template< class A_type, int dummy >
	void put_integer( Integers< A_type, dummy > integer_number ) noexcept;

	template< class A_type, int dummy >
	void put_natural( Naturals< A_type, dummy > natural_number ) noexcept;

	template< class A_type, int dummy >
	void put_hexadecimal( Naturals< A_type, dummy > hexadecimal_number ) noexcept;

	template< class A_type >
	void put_real( Reals< A_type > real_number ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const structing::containing::List< Ansii_string > &get_ansii_string_list() const noexcept;
	Ansii_string create_consolidated_ansii_string_( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Ansii_string_stream() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Ansii_string_stream create( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_string_stream( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept; // Allocator for ansii_string

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Ansii_string_stream( const Ansii_string_stream &another ) noexcept;
	const Ansii_string_stream &operator =( const Ansii_string_stream &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< memorying::Allocator > _character_array_allocator;
	memorying::Womp< memorying::Allocator > _list_node_allocator;
	structing::containing::List< Ansii_string > _ansii_string_list;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void put_integer_32( Integer integer_number ) noexcept;
	void put_integer_64( Long_integer integer_number ) noexcept;
	void put_natural_32( Natural natural_number ) noexcept;
	void put_natural_64( Long_natural natural_number ) noexcept;
	void put_hexadecimal_32( Natural hexadecimal_number ) noexcept;
	void put_hexadecimal_64( Long_natural hexadecimal_number ) noexcept;
	void put_real_double( Real real_number ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


template<>
JMSF_SHARED_INTERFACE void Ansii_string_stream::put_integer( const Long_integer integer_number ) noexcept;

template<>
JMSF_SHARED_INTERFACE void Ansii_string_stream::put_natural( const Long_natural natural_number ) noexcept;

//template<>
//JMSF_DLL_INTERFACE void Ansii_string_stream::put_hexadecimal( const Long_integer hexadecimal_number ) noexcept;

template<>
JMSF_SHARED_INTERFACE void Ansii_string_stream::put_hexadecimal( const Long_natural hexadecimal_number ) noexcept;


template<>
JMSF_SHARED_INTERFACE void Ansii_string_stream::put_real( const Short_real real_number ) noexcept;


} // namespace typeing
} // namespace jmsf
