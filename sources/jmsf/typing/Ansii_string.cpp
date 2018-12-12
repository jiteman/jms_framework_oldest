#include "Ansii_string.h"


#include "Aso.hpp"
#include "Boolean.h"
#include "jmsf/structing/containing/List.inl"
#include "jmsf/structing/traversing/List_traverser.inl"
#include "jmsf/memorying/Destructor.inl"
#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/Wamp.inl"


namespace jmsf {
namespace typing {


const memorying::Amp< internals::platform_character_type > Ansii_string::get_as_C_string( const memorying::Womp< memorying::Allocator > character_array_allocator ) const noexept {
	if ( character_array_allocator.is_empty() ) return memorying::Amp< internals::platform_character_type >(); // EIS: rework to throw error

	memorying::Amp< internals::platform_character_type > C_string =
		memorying::Constructor< internals::platform_character_type, internals::platform_character_type >::construct_default_as_array(
			character_array_allocator,
			_character_array_memory_pointer.get_quantity() + Memory_size_one );

	const internals::platform_character_type *source = _character_array_memory_pointer.get();
	internals::platform_character_type *destination = C_string.take();

	if ( source != nullptr ) {
		for ( typing::Memory_size counter = _character_array_memory_pointer.get_quantity(); counter.is_not_nill(); --counter ) {
			*destination++ = *source++;
		}
	}

	*destination = '\0';

	return C_string;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Ansii_string::is_empty() const noexept {
	return _character_array_memory_pointer.get_quantity().is_nill();
}

Boolean Ansii_string::is_not_empty() const noexept {
	return _character_array_memory_pointer.get_quantity().is_not_nill();
}

Memory_size Ansii_string::get_quantity() const noexept {
	return _character_array_memory_pointer.get_quantity();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Ansii_string::is_equal( const Ansii_string &another ) const noexept {
	if ( _character_array_memory_pointer.get_quantity() != another._character_array_memory_pointer.get_quantity() ) return False;

	const internals::platform_character_type *this_character_array = _character_array_memory_pointer.get();
	const internals::platform_character_type *another_character_array = another._character_array_memory_pointer.get();

	for ( Memory_size quantity = _character_array_memory_pointer.get_quantity(); quantity.is_not_nill(); quantity -= Memory_size_one ) {
		if ( *this_character_array++ != *another_character_array++ ) return False;
	}

	return True;
}

Boolean Ansii_string::is_not_equal( const Ansii_string &another ) const noexept {
	return is_equal( another ).not();
}

Boolean Ansii_string::is_same( const Ansii_string &another ) const noexept {
	return _character_array_memory_pointer.get_memory().get_address() == another._character_array_memory_pointer.get_memory().get_address();
}

Boolean Ansii_string::is_not_same( const Ansii_string &another ) const noexept {
	return _character_array_memory_pointer.get_memory().get_address() != another._character_array_memory_pointer.get_memory().get_address();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_string::~Ansii_string() noexept {
	if ( _character_array_memory_pointer.get_allocator().is_empty() ) return;

	memorying::Destructor< internals::platform_character_type >::destruct( _character_array_memory_pointer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// statics
Ansii_string Ansii_string::create_from_constant_literal( const internals::platform_character_type *const characters ) noexept {
	const typing::Memory_size quantity_of_characters = count_quantity_of_characters( characters );

	return Ansii_string( 
		memorying::Womp< memorying::Allocator >(),
		memorying::Wamp< internals::platform_character_type >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			quantity_of_characters ) );
}

Ansii_string Ansii_string::create_empty( const memorying::Womp< memorying::Allocator > &character_array_allocator ) noexept {
	return Ansii_string( character_array_allocator );
}

Ansii_string Ansii_string::create_from_c_language_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character_type *const characters ) noexept {
	const typing::Memory_size quantity_of_characters = count_quantity_of_characters( characters );

	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character_type >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			quantity_of_characters ) );
}

Ansii_string Ansii_string::create_from_buffer( const memorying::Womp< memorying::Allocator > &character_array_allocator, const internals::platform_character_type *const characters, const Memory_size quantity_of_characters ) noexept {
	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character_type >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			quantity_of_characters ) );
}

Ansii_string Ansii_string::create_from_another( const memorying::Womp< memorying::Allocator > &character_array_allocator, const Ansii_string &another ) noexept {
	return Ansii_string(
		character_array_allocator,
		memorying::Wamp< internals::platform_character_type >::create(
			another._character_array_memory_pointer.get_memory(),
			another._character_array_memory_pointer.get_quantity() ) );
}

Ansii_string Ansii_string::create_from_list( const memorying::Womp< memorying::Allocator > &character_array_allocator, const structing::containing::List< Ansii_string > &ansii_string_list ) noexept {
	const Memory_size total_count = count_total_size_of_strings( ansii_string_list );

	if ( total_count.is_nill() ) return Ansii_string();

	Ansii_string consolidated_string = create_from_buffer( character_array_allocator, nullptr, total_count );

	internals::platform_character_type *destination = consolidated_string._character_array_memory_pointer.take();

	for ( structing::traversing::List_traverser< Ansii_string > list_traverser = const_cast< structing::containing::List< Ansii_string > & >( ansii_string_list ).create_traverser_at_begin(); list_traverser.is_not_done(); list_traverser.move_one_step_to_end() ) {
		const internals::platform_character_type *source = list_traverser.get_object()._character_array_memory_pointer.get();

		for ( typing::Memory_size counter = list_traverser.get_object().get_quantity(); counter.is_not_nill(); --counter ) {
			*destination++ = *source++;
		}
	}

	return consolidated_string;
}
//~statics

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator ) noexept
	:
		_character_array_memory_pointer(
			memorying::Amp< internals::platform_character_type >::create(
				memorying::Memory_pointer(),
				Memory_size_nill,
				character_array_allocator,
				alignment_of< internals::platform_character_type >() ) )
{}

Ansii_string::Ansii_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const memorying::Wamp< internals::platform_character_type > &character_array ) noexept
	:
		_character_array_memory_pointer(
			character_array_allocator.is_empty() ?
					memorying::Amp< internals::platform_character_type >::create( // constant literal
						character_array.get_memory(),					
						character_array.get_quantity(),
						character_array_allocator,
						typing::alignment_of< internals::platform_character_type >() )
				:
					memorying::Constructor< internals::platform_character_type, internals::platform_character_type >::construct_default_as_array(
						character_array_allocator,
						character_array.get_quantity() ) )
{
	if ( character_array_allocator.is_empty() ) return; // constant literal

	const internals::platform_character_type *source = character_array.get();

	if ( source == nullptr ) return;

	internals::platform_character_type *destination = _character_array_memory_pointer.take();

	for ( typing::Memory_size counter = character_array.get_quantity(); counter.is_not_nill(); --counter ) {
		*destination++ = *source++;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_string::Ansii_string( const Ansii_string &another ) noexept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
	Ansii_string &non_contant_another = const_cast< Ansii_string & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< internals::platform_character_type >();
}

const Ansii_string &Ansii_string::operator =( const Ansii_string &another ) noexept {
	if ( &another == this ) return *this;

	if ( _character_array_memory_pointer.get_allocator().is_not_empty() ) {
		memorying::Destructor< internals::platform_character_type >::destruct( _character_array_memory_pointer );
	}

	_character_array_memory_pointer = another._character_array_memory_pointer;

	Ansii_string &non_contant_another = const_cast< Ansii_string & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< internals::platform_character_type >();
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
typing::Memory_size Ansii_string::count_quantity_of_characters( const internals::platform_character_type *const characters ) noexept {
	if ( characters == nullptr ) return typing::Memory_size_nill;

	const internals::platform_character_type *pointer_to_characters = characters;
	typing::Memory_size quantity_of_characters;

	for ( ; *pointer_to_characters++ != '\0'; ++quantity_of_characters );
// 	{
// 		while ( *pointer_to_characters++ != '\0' ) {
// 			++quantity_of_characters;
// 		}
// 	}

	return quantity_of_characters;
}

// static
Memory_size Ansii_string::count_total_size_of_strings( const structing::containing::List< Ansii_string > &ansii_string_list ) noexept {
	Memory_size total_count;

	for ( structing::traversing::List_traverser< Ansii_string > list_traverser = const_cast< structing::containing::List< Ansii_string > & >( ansii_string_list ).create_traverser_at_begin(); list_traverser.is_not_done(); list_traverser.move_one_step_to_end() ) {
		total_count += list_traverser.get_object().get_quantity();
	}

	return total_count;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf


namespace jmsf {


//JMSF_DLL_INTERFACE
typing::Ansii_string AS_string_literal( const typing::internals::platform_character_type *characters ) noexept {
	return typing::Ansii_string::create_from_constant_literal( characters );
}

//JMSF_DLL_INTERFACE
typing::Ansii_string AS_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const typing::internals::platform_character_type *characters ) noexept {
	return typing::Ansii_string::create_from_c_language_string( character_array_allocator, characters );
}


} // namespace jmsf
