#include "Comparasion_result.h"

#include "Integers.hin"
#include "Boolean.h"


namespace jmsf {
namespace typeing {


Boolean Comparasion_result::is_lower() const noexcept {
	return _the_value.is_negative();
}

Boolean Comparasion_result::is_equal() const noexcept {
	return _the_value.is_nill();
}

Boolean Comparasion_result::is_greater() const noexcept {
	return _the_value.is_not_nill() && _the_value.is_positive();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparasion_result::is_not_lower() const noexcept {
	return is_lower().inversion();
}

Boolean Comparasion_result::is_not_equal() const noexcept {
	return is_equal().inversion();
}

Boolean Comparasion_result::is_not_greater() const noexcept {
	return is_greater().inversion();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean Comparasion_result::operator ==( const Comparasion_result &another ) const noexcept {
	return Boolean::create( _the_value == another._the_value );
}

Boolean Comparasion_result::operator !=( const Comparasion_result &another ) const noexcept {
	return Boolean::create( _the_value != another._the_value );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Comparasion_result::~Comparasion_result() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result() noexcept
{}

// static
Comparasion_result Comparasion_result::create_lower() noexcept {
	return Comparasion_result( Integer_minus );
}

// static
Comparasion_result Comparasion_result::create_equal() noexcept {
	return Comparasion_result();
}

// static
Comparasion_result Comparasion_result::create_greater() noexcept {
	return Comparasion_result( Integer_one );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result( const Integer a_value ) noexcept
	:
		_the_value( a_value )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Comparasion_result::Comparasion_result( const Comparasion_result &another ) noexcept
	:
		_the_value( another._the_value )
{}

const Comparasion_result &Comparasion_result::operator =( const Comparasion_result &another ) noexcept {
	if ( &another == this ) return *this;

	_the_value = another._the_value;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace typeing
} // namespace jmsf
