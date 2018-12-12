#pragma once


#include "Reals.inl"


namespace jmsf {
namespace typing {


template<>
Boolean Reals< internals::platform_short_real >::math_is_about_zero( const internals::platform_short_real real_value ) noexept {
	return Boolean::create( !( math_compute_absolute( real_value ) > SHORT_REAL_DEFAULT_ACCURACY ) );
}

template<>
Boolean Reals< internals::platform_real >::math_is_about_zero( const internals::platform_real real_value ) noexept {
	return Boolean::create( !( math_compute_absolute( real_value ) > REAL_DEFAULT_ACCURACY ) );
}


} // namespace typing
} // namespace jmsf
