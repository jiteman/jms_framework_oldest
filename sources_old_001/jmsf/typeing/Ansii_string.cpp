#include "Ansii_string.h"


#include "Aso.hpp"
#include "Boolean.h"
#include "Naturals.hin"
#include "Native_C_string.hin"
#include "jmsf/structing/containing/List.hin"
#include "jmsf/structing/traversing/List_traverser.hin"
#include "jmsf/structing/containing/Buffer.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Wamp.hin"

#include "jmsf/validating/logging_macroses.h"

//#include <cstdlib>
#include <cstring>


namespace jmsf {
namespace typeing {


Native_C_string Ansii_string::get_as_native_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator ) const noexcept {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( character_array_allocator.is_empty(), "Ansii_string::get_as_native_C_string( allocator )" );
	jmsf_Should_never_be_null( character_array_allocator );

	Native_C_string result_native_c_string;

	if ( _character_array_memory_pointer.get_allocator().is_empty() ) { // constant literal
		char some_string[ 1024 ] = {};
		::strncpy( some_string, reinterpret_cast< const char * >( _character_array_memory_pointer.get() ), _character_array_memory_pointer.get_quantity().get_native_value() );

		result_native_c_string =
			Native_C_string::create(
			memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
				character_array_allocator,
				_character_array_memory_pointer.get_quantity() + Memory_natural_one ) );

		const internals::platform_character *source = _character_array_memory_pointer.get();
		internals::platform_character *destination = result_native_c_string.take_array().take();

		if ( source != nullptr ) {
			for ( typeing::Memory_natural counter = _character_array_memory_pointer.get_quantity(); counter.is_not_nill(); --counter ) {
				*destination++ = *source++;
			}
		}

		*destination = '\0';

//		::memset( some_string, 0, 2048 );

		char some_string_1[ 1024 ] = {};
		::strcpy( some_string_1, result_native_c_string.get_array().get() );

		return result_native_c_string;
	} else {
		char some_another_string[ 1024 ] = {};

		::strncpy(
			some_another_string,
			reinterpret_cast< const char * >( _character_array_memory_pointer.get() ),
			_character_array_memory_pointer.get_quantity().get_native_value() );

		result_native_c_string =
			Native_C_string::create(
				memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
					character_array_allocator,
					_character_array_memory_pointer.get_quantity() + Memory_natural_one ) );

		const internals::platform_character *source = _character_array_memory_pointer.get();
		internals::platform_character *destination = result_native_c_string.take_array().take();

		if ( source != nullptr ) {
			for ( typeing::Memory_natural counter = _character_array_memory_pointer.get_quantity(); counter.is_not_nill(); --counter ) {
				*destination++ = *source++;
			}
		}

		*destination = '\0';

		char some_another_string_1[ 1024 ] = {};
		::strcpy( some_another_string_1, result_native_c_string.get_array().get() );

		return result_native_c_string;
	}

//	return result_native_c_string;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Ansii_string::is_empty() const noexcept {
	return _character_array_memory_pointer.get_quantity().is_nill();
}

Boolean Ansii_string::is_not_empty() const noexcept {
	return _character_array_memory_pointer.get_quantity().is_not_nill();
}

Memory_natural Ansii_string::get_quantity() const noexcept {
	return _character_array_memory_pointer.get_quantity();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Ansii_string::is_equal( const Ansii_string &another ) const noexcept {
	if ( _character_array_memory_pointer.get_quantity() != another._character_array_memory_pointer.get_quantity() ) return False;

	const internals::platform_character *this_character_array = _character_array_memory_pointer.get();
	const internals::platform_character *another_character_array = another._character_array_memory_pointer.get();

	for ( Memory_natural quantity = _character_array_memory_pointer.get_quantity(); quantity.is_not_nill(); quantity -= Memory_natural_one ) {
		if ( *this_character_array++ != *another_character_array++ ) return False;
	}

	return True;
}

Boolean Ansii_string::is_not_equal( const Ansii_string &another ) const noexcept {
	return is_equal( another ).inversion();
}

Boolean Ansii_string::is_same( const Ansii_string &another ) const noexcept {
	return _character_array_memory_pointer.get_memory().get_address() == another._character_array_memory_pointer.get_memory().get_address();
}

Boolean Ansii_string::is_not_same( const Ansii_string &another ) const noexcept {
	return _character_array_memory_pointer.get_memory().get_address() != another._character_array_memory_pointer.get_memory().get_address();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_string::~Ansii_string() noexcept {
//	if ( _character_array_memory_pointer.get_allocator().is_empty() ) return;

	memorying::Destructor< internals::platform_character >::destruct( _character_array_memory_pointer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// statics
Ansii_string Ansii_string::create_from_constant_literal( const internals::platform_character *const characters ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( characters == nullptr, "Ansii_string::create_from_constant_literal( characters )" );
	jmsf_Should_never_be_null_native_pointer( characters );

//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::create_from_constant_literal()" );
	return Ansii_string (
		memorying::Womp< memorying::Allocator >(),
		memorying::Wamp< internals::platform_character >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			count_quantity_of_characters( characters ) ) );
}

//Ansii_string Ansii_string::create_empty( const memorying::Womp< memorying::Allocator > &character_array_allocator ) noexcept {
//	return Ansii_string( character_array_allocator );
//}

Ansii_string Ansii_string::create_from_c_language_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character *const characters ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( characters == nullptr, "Ansii_string::create_from_c_language_string( allocator, characters )" );
	jmsf_Should_never_be_null_native_pointer( characters );

	const typeing::Memory_natural quantity_of_characters = count_quantity_of_characters( characters );

//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::create_from_c_language_string()" );
	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			quantity_of_characters ) );
}

Ansii_string Ansii_string::create_from_native_buffer(
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const internals::platform_character *const characters,
	const Memory_natural quantity_of_characters )
{
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( characters == nullptr, "Ansii_string::create_from_c_language_string( allocator, characters )" );
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( quantity_of_characters.is_nill(), "Ansii_string::create_from_c_language_string( allocator, characters )" );
	jmsf_Should_never_be_null_native_pointer( characters );
	jmsf_Should_never_be( quantity_of_characters.is_nill() );

	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			quantity_of_characters ) );
}

Ansii_string Ansii_string::create_from_another( const memorying::Womp< memorying::Allocator > &character_array_allocator, const Ansii_string &another ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( another.is_empty(), "Ansii_string::create_from_another( allocator, another )" );
	jmsf_Should_never_be( another.is_empty() );

	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character >::create(
			another._character_array_memory_pointer.get_memory(),
			another._character_array_memory_pointer.get_quantity() ) );
}

Ansii_string Ansii_string::create_from_list( const memorying::Womp< memorying::Allocator > &character_array_allocator, const structing::containing::List< Ansii_string > &ansii_string_list ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( ansii_string_list.is_empty(), "Ansii_string::create_from_list( allocator, list )" );
	jmsf_Should_never_be( ansii_string_list.is_empty() );

	const Memory_natural total_count = count_total_size_of_strings( ansii_string_list );

	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( total_count.is_nill(), "Ansii_string::create_from_list( allocator, list )" );
	jmsf_Should_never_be( total_count.is_nill() );

	Ansii_string consolidated_string( character_array_allocator, total_count );

	internals::platform_character *destination = consolidated_string._character_array_memory_pointer.take();

	for ( structing::traversing::List_traverser< Ansii_string > list_traverser = const_cast< structing::containing::List< Ansii_string > & >( ansii_string_list ).create_traverser_at_begin(); list_traverser.is_not_done(); list_traverser.move_one_step_to_end() ) {
		JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( list_traverser.get_object().is_empty(), "Ansii_string::create_from_list( allocator, list )" );
		jmsf_Should_never_be( list_traverser.get_object().is_empty() );
		const internals::platform_character *source = list_traverser.get_object()._character_array_memory_pointer.get();

		for ( typeing::Memory_natural counter = list_traverser.get_object().get_quantity(); counter.is_not_nill(); --counter ) {
			*destination++ = *source++;
		}
	}

//	char some_string[ 1024 ] = {};

//	::strncpy( some_string, reinterpret_cast< const char * >( consolidated_string._character_array_memory_pointer.get() ), total_count.get_native_value() );

	return consolidated_string;
}
//~statics

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const typeing::Memory_natural a_quantity ) noexcept
	:
		_character_array_memory_pointer(
			memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
				character_array_allocator,
				a_quantity ) )


//			memorying::Amp< internals::platform_character >::create(
//				memorying::Memory_pointer(),
//				Memory_natural_nill,
//				character_array_allocator,
//				alignment_of< internals::platform_character >() ) )
{
//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator )" );
}

Ansii_string::Ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Wamp< internals::platform_character > &character_array ) noexcept
//	:
//		_character_array_memory_pointer(
//			character_array_allocator.is_empty() ?
//					memorying::Amp< internals::platform_character >::create( // constant literal
//						character_array.get_memory(),
//						character_array.get_quantity(),
//						character_array_allocator,
//						typeing::alignment_of< internals::platform_character >() )
//				:
//					memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
//						character_array_allocator,
//						character_array.get_quantity() ) )
{
//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );

	if ( character_array_allocator.is_empty() ) {
//		JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );
//		const memorying::Memory_pointer temporary_memory_pointer = character_array.get_memory();
//		JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );
//		const typeing::Memory_natural temporary_quantity = character_array.get_quantity();
//		JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );
		_character_array_memory_pointer =
			memorying::Amp< internals::platform_character >::create( // constant literal
				character_array.get_memory(),
				character_array.get_quantity(),
				character_array_allocator,
				typeing::alignment_of< internals::platform_character >() );
	} else {
//		JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );

		_character_array_memory_pointer =
			memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
				character_array_allocator,
				character_array.get_quantity() );
	}

//	_character_array_memory_pointer =
//			character_array_allocator.is_empty() ?
//					memorying::Amp< internals::platform_character >::create( // constant literal
//						character_array.get_memory(),
//						character_array.get_quantity(),
//						character_array_allocator,
//						typeing::alignment_of< internals::platform_character >() )
//				:
//					memorying::Constructor< internals::platform_character, internals::platform_character >::construct_default_as_array(
//						character_array_allocator,
//						character_array.get_quantity() );

//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( allocator, array )" );

	if ( character_array_allocator.is_empty() ) return; // constant literal

	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( character_array.is_empty(), "Ansii_string::Ansii_string( allocator, Wamp< platform_character > )" );
	jmsf_Should_never_be_null( character_array );

	const internals::platform_character *source = character_array.get();
	internals::platform_character *destination = _character_array_memory_pointer.take();

	for ( typeing::Memory_natural counter = character_array.get_quantity(); counter.is_not_nill(); --counter ) {
		*destination++ = *source++;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string( const Ansii_string &another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
//	JMSF_LOG_INFORMING_OUTPUT( "Ansii_string::Ansii_string( another )" );
	Ansii_string &non_contant_another = const_cast< Ansii_string & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< internals::platform_character >();
}

Ansii_string::Ansii_string( Ansii_string &&another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
	another._character_array_memory_pointer = memorying::Amp< internals::platform_character >();
}

const Ansii_string &Ansii_string::operator =( const Ansii_string &another ) noexcept {
	if ( &another == this ) return *this;

	if ( _character_array_memory_pointer.get_allocator().is_not_empty() ) {
		memorying::Destructor< internals::platform_character >::destruct( _character_array_memory_pointer );
	}

	_character_array_memory_pointer = another._character_array_memory_pointer;

	Ansii_string &non_contant_another = const_cast< Ansii_string & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< internals::platform_character >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
typeing::Memory_natural Ansii_string::count_quantity_of_characters( const internals::platform_character *const characters ) noexcept {
	if ( characters == nullptr ) return typeing::Memory_natural_nill;

	const internals::platform_character *pointer_to_characters = characters;
	typeing::Memory_natural quantity_of_characters;

	for ( ; *pointer_to_characters++ != '\0'; ++quantity_of_characters );
// 	{
// 		while ( *pointer_to_characters++ != '\0' ) {
// 			++quantity_of_characters;
// 		}
// 	}

	return quantity_of_characters;
}

// static
Memory_natural Ansii_string::count_total_size_of_strings( const structing::containing::List< Ansii_string > &ansii_string_list ) noexcept {
	Memory_natural total_count;

	for ( structing::traversing::List_traverser< Ansii_string > list_traverser = const_cast< structing::containing::List< Ansii_string > & >( ansii_string_list ).create_traverser_at_begin(); list_traverser.is_not_done(); list_traverser.move_one_step_to_end() ) {
		total_count += list_traverser.get_object().get_quantity();
	}

	return total_count;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typeing
} // namespace jmsf


namespace jmsf {


//JMSF_DLL_INTERFACE
typeing::Ansii_string AS_string_literal( const typeing::internals::platform_character *characters ) noexcept {
//	JMSF_LOG_INFORMING_OUTPUT( "AS_string_literal( characters )" );
	return typeing::Ansii_string::create_from_constant_literal( characters );
}

//JMSF_DLL_INTERFACE
typeing::Ansii_string AS_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const typeing::internals::platform_character *characters ) noexcept {
//	JMSF_LOG_INFORMING_OUTPUT( "AS_C_string( allocator, characters )" );
	return typeing::Ansii_string::create_from_c_language_string( character_array_allocator, characters );
}


} // namespace jmsf
