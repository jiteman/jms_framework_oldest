#pragma once


namespace jmsf {
namespace researching {


template< class A_type, class B_type >
void Nullptr_checking_assignment( A_type *a_type_pointer, const B_type &b_value ) noexept {
	if ( a_type_pointer != nullptr ) {
		*a_type_pointer = b_value;
	}
}


} // namespace researching
} // namespace jmsf
