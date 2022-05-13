#pragma once


namespace jmsf {
namespace typeing {


template< class A_type, int dummy > class Reals;


} // namespace typeing
} // namespace jmsf


#include "jmsf/typeing/internals/internal_types.h"


namespace jmsf {
namespace typeing {


typedef internals::platform_short_real short_real_value_type;
typedef internals::platform_real real_value_type;
typedef internals::platform_long_real long_real_value_type;


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


typedef Reals< short_real_value_type, 1 > Short_real;
typedef Reals< real_value_type, 2 > Real;
typedef Reals< long_real_value_type, 3 > Long_real;


} // namespace typeing
} // namespace jmsf
