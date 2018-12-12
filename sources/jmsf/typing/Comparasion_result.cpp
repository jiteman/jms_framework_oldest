#include "Comparasion_result.h"

#include "Integers.inl"


namespace jmsf {
namespace typing {


Boolean Comparasion_result::is_lower() const noexept {
	return _the_value.is_negative();
}

Boolean Comparasion_result::is_equal() const noexept {
	return _the_value.is_nill();
}

Boolean Comparasion_result::is_greater() const noexept {
	return _the_value.is_not_nill() && _the_value.is_positive();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparasion_result::is_not_lower() const noexept {
	return is_lower().not();
}

Boolean Comparasion_result::is_not_equal() const noexept {
	return is_equal().not();
}

Boolean Comparasion_result::is_not_greater() const noexept {
	return is_greater().not();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparasion_result::operator ==( const Comparasion_result &another ) const noexept {
	return Boolean::create( _the_value == another._the_value );
}

Boolean Comparasion_result::operator !=( const Comparasion_result &another ) const noexept {
	return Boolean::create( _the_value != another._the_value );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Comparasion_result::~Comparasion_result() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result() noexept
{}

// static
Comparasion_result Comparasion_result::create_lower() noexept {
	return Comparasion_result( Integer_minus );
}

// static
Comparasion_result Comparasion_result::create_equal() noexept {
	return Comparasion_result();
}

// static
Comparasion_result Comparasion_result::create_greater() noexept {
	return Comparasion_result( Integer_one );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result( const Integer a_value ) noexept
	:
		_the_value( a_value )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result( const Comparasion_result &another ) noexept
	:
		_the_value( another._the_value )
{}

const Comparasion_result &Comparasion_result::operator =( const Comparasion_result &another ) noexept {
	if ( &another == this ) return *this;

	_the_value = another._the_value;
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typing
} // namespace jmsf
