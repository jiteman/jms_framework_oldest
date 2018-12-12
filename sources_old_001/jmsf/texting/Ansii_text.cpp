#include "Ansii_text.h"


#include "jmsf/memorying/Amp.hin"
#include "jmsf/pointing/Constant_pointer.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/typeing/Boolean.h"
#include "jmsf/typeing/Naturals.hin"


namespace jmsf {
namespace texting {


typeing::Boolean Ansii_text::is_empty() const noexcept {
	return _character_array_memory_pointer.is_empty();
}

typeing::Boolean Ansii_text::is_not_empty() const noexcept {
	return _character_array_memory_pointer.is_not_empty();
}

typeing::Memory_natural Ansii_text::get_quantity() const noexcept {
	return _character_array_memory_pointer.get_quantity();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typeing::Boolean Ansii_text::is_equal( const pointing::Constant_pointer< Ansii_text > &another ) const {
	if ( _character_array_memory_pointer.get_quantity() != another->_character_array_memory_pointer.get_quantity() ) return typeing::False;

	const typeing::internals::platform_character *this_character_array = _character_array_memory_pointer.get();
	const typeing::internals::platform_character *another_character_array = another->_character_array_memory_pointer.get();

	for ( typeing::Memory_natural quantity = _character_array_memory_pointer.get_quantity(); quantity.is_not_nill(); quantity -= typeing::Memory_natural_one ) {
		if ( *this_character_array++ != *another_character_array++ ) {
			return typeing::False;
		}
	}

	return typeing::True;
}

typeing::Boolean Ansii_text::is_not_equal( const pointing::Constant_pointer< Ansii_text > &another ) const {
	return is_equal( another ).inversion();
}

typeing::Boolean Ansii_text::is_same( const pointing::Constant_pointer< Ansii_text > &another ) const {
	return _character_array_memory_pointer.get_memory().get_address() == another->_character_array_memory_pointer.get_memory().get_address();
}

typeing::Boolean Ansii_text::is_not_same( const pointing::Constant_pointer< Ansii_text > &another ) const {
	return is_same( another ).inversion();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Ansii_text::~Ansii_text() noexcept {
	memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_text::Ansii_text() noexcept
{}

// static
pointing::Constant_pointer< Ansii_text > Ansii_text::create() {
	return pointing::Constant_pointer< Ansii_text >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Ansii_text::Ansii_text( const Ansii_text &another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
	Ansii_text &non_contant_another = const_cast< Ansii_text & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< typeing::internals::platform_character >();
}

const Ansii_text &Ansii_text::operator =( const Ansii_text &another ) noexcept {
	if ( &another == this ) return *this;

	if ( _character_array_memory_pointer.get_allocator().is_not_empty() ) {
		memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer );
	}

	_character_array_memory_pointer = another._character_array_memory_pointer;

	Ansii_text &non_contant_another = const_cast< Ansii_text & >( another );
	non_contant_another._character_array_memory_pointer = memorying::Amp< typeing::internals::platform_character >();
	return *this;
}

Ansii_text::Ansii_text( Ansii_text &&another ) noexcept
	:
		_character_array_memory_pointer( another._character_array_memory_pointer )
{
	another._character_array_memory_pointer = memorying::Amp< typeing::internals::platform_character >();
}

Ansii_text &Ansii_text::operator =( Ansii_text &&another ) noexcept {
	if ( &another == this ) return *this;

	if ( _character_array_memory_pointer.get_allocator().is_not_empty() ) {
		memorying::Destructor< typeing::internals::platform_character >::destruct( _character_array_memory_pointer );
	}

	_character_array_memory_pointer = another._character_array_memory_pointer;
	another._character_array_memory_pointer = memorying::Amp< typeing::internals::platform_character >();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf
