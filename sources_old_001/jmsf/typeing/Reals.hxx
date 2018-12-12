#pragma once


namespace jmsf {
namespace typeing {


template< class A_type > class Reals;


} // namespace typeing
} // namespace jmsf


#include "jmsf/typeing/internals/internal_types.h"


namespace jmsf {
namespace typeing {


typedef internals::platform_short_real short_real_value_type;
typedef internals::platform_real real_value_type;


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


typedef Reals< short_real_value_type > Short_real;
typedef Reals< real_value_type > Real;


} // namespace typeing
} // namespace jmsf
