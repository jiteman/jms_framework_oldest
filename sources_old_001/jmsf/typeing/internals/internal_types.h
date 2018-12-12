#pragma once


#include "jmsf/jmsf.h"


#include "jmsf/encodebuba/platforming/standard_detection.h"


#if JMSF_CPLUSPLUS_VERSION_VALUE >= JMSF_CPLUSPLUS11_VERSION_CONSTANT
	#include <cstdint>

#endif


#include "jmsf/encodebuba/platforming/memory_model_detection.h"


namespace jmsf {
namespace typeing {
namespace internals {


typedef ::jmsf::encodebuba::platforming::memory_models::byte_type platform_byte;
typedef ::jmsf::encodebuba::platforming::memory_models::character_type	platform_character;

typedef ::jmsf::encodebuba::platforming::memory_models::integer_1_byte_type platform_shortest_integer;
typedef ::jmsf::encodebuba::platforming::memory_models::natural_1_byte_type platform_shortest_natural;

typedef ::jmsf::encodebuba::platforming::memory_models::integer_2_bytes_type platform_short_integer;
typedef ::jmsf::encodebuba::platforming::memory_models::natural_2_bytes_type platform_short_natural;

typedef ::jmsf::encodebuba::platforming::memory_models::integer_4_bytes_type platform_integer;
typedef ::jmsf::encodebuba::platforming::memory_models::natural_4_bytes_type platform_natural;

typedef ::jmsf::encodebuba::platforming::memory_models::integer_8_bytes_type platform_long_integer;
typedef ::jmsf::encodebuba::platforming::memory_models::natural_8_bytes_type platform_long_natural;

typedef ::jmsf::encodebuba::platforming::memory_models::integer_pointer_type platform_memory_integer;
typedef ::jmsf::encodebuba::platforming::memory_models::natural_pointer_type platform_memory_natural;

typedef platform_long_integer platform_file_integer;
typedef platform_long_natural platform_file_natural;

typedef bool platform_boolean;

typedef float platform_short_real;
typedef double platform_real;


} // namespace internals


#if JMSF_CPLUSPLUS_VERSION_VALUE >= JMSF_CPLUSPLUS11_VERSION_CONSTANT


namespace internals {


typedef std::int_fast8_t platform_shortest_fast_integer;
typedef std::int_least8_t platform_shortest_small_integer;
typedef std::uint_fast8_t platform_shortest_fast_natural;
typedef std::uint_least8_t platform_shortest_small_natural;

typedef std::int_fast16_t platform_short_fast_integer;
typedef std::int_least16_t platform_short_small_integer;
typedef std::uint_fast16_t platform_short_fast_natural;
typedef std::uint_least16_t platform_short_small_natural;

typedef std::int_fast32_t platform_fast_integer;
typedef std::int_least32_t platform_small_integer;
typedef std::uint_fast32_t platform_fast_natural;
typedef std::uint_least32_t platform_small_natural;

typedef std::int_fast64_t platform_long_fast_integer;
typedef std::int_least64_t platform_long_small_integer;
typedef std::uint_fast64_t platform_long_fast_natural;
typedef std::uint_least64_t platform_long_small_natural;


} // namespace internals


#else
	#error This file "jmsf/typeing/internals/internal_types.h" - fast and least integral types required (C++11). Old versions of C++ are not supported yet.

#endif


extern const internals::platform_memory_natural CHAR_BIT_SIZE;
extern const internals::platform_memory_natural MAXIMUM_INTEGRAL_SIZE;
extern const internals::platform_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE;
extern const internals::platform_real REAL_DEFAULT_ACCURACY;
extern const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY;


// const internals::platform_memory_natural CHAR_BIT_SIZE = 8;
// const internals::platform_memory_natural MAXIMUM_INTEGRAL_SIZE = sizeof( internals::platform_long_natural );
// const internals::platform_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE = CHAR_BIT_SIZE * MAXIMUM_INTEGRAL_SIZE;
// const internals::platform_real REAL_DEFAULT_ACCURACY = 0.000000000000001;
// const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY = 0.000001f;


} // namespace typeing
} // namespace jmsf
