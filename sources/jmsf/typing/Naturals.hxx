#pragma once


namespace jmsf {
namespace typing {


template< class A_type > class Naturals;


} // namespace typing
} // namespace jmsf


#include "internals/internal_types.h"
#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


typedef internals::platform_unsigned_char shortest_natural_value_type;
typedef internals::platform_unsigned_short_int short_natural_value_type;
typedef internals::platform_unsigned_int natural_value_type;
typedef internals::platform_unsigned_long_int long_natural_value_type;
typedef internals::platform_memory_size memory_size_value_type;
typedef internals::platform_file_size file_size_value_type;


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


typedef Naturals< shortest_natural_value_type > Shortest_natural;
typedef Naturals< short_natural_value_type > Short_natural;
typedef Naturals< natural_value_type > Natural;
typedef Naturals< long_natural_value_type > Long_natural;
typedef Naturals< memory_size_value_type > Memory_size;
typedef Naturals< file_size_value_type > File_size;


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


// JMSF_DLL_INTERFACE
Memory_size create_address_from_pointer( const void *memory_pointer ) noexept;

template< class A_type >
A_type *get_pointer_from_memory_size( Memory_size memory_address ) noexept;


} // namespace typing
} // namespace jmsf

