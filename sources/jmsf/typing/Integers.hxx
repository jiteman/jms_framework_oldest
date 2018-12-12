#pragma once


namespace jmsf {
namespace typing {


template< class A_type > class Integers;


} // namespace typing
} // namespace jmsf


#include "internals/internal_types.h"


namespace jmsf {
namespace typing {


typedef internals::platform_signed_char shortest_integer_value_type;
typedef internals::platform_signed_short_int short_integer_value_type;
typedef internals::platform_signed_int integer_value_type;
typedef internals::platform_signed_long_int long_integer_value_type;
typedef internals::platform_memory_diff memory_diff_value_type;
typedef internals::platform_file_diff file_diff_value_type;


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


typedef Integers< shortest_integer_value_type > Shortest_integer;
typedef Integers< short_integer_value_type > Short_integer;
typedef Integers< integer_value_type > Integer;
typedef Integers< long_integer_value_type > Long_integer;
typedef Integers< memory_diff_value_type > Memory_diff;
typedef Integers< file_diff_value_type > File_diff;


} // namespace typing
} // namespace jmsf
