#pragma once


namespace jmsf {
namespace typing {


template< class A_type > class Reals;


} // namespace typing
} // namespace jmsf


#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace typing {


typedef internals::platform_short_real short_real_value_type;
typedef internals::platform_real real_value_type;


} // namespace typing
} // namespace jmsf


namespace jmsf {
namespace typing {


typedef Reals< short_real_value_type > Short_real;
typedef Reals< real_value_type > Real;


} // namespace typing
} // namespace jmsf