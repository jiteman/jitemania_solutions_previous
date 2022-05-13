#pragma once


namespace jmsf {
namespace typeing {


template< class A_type, int dummy > class Integers;


} // namespace typeing
} // namespace jmsf


#include "internals/internal_types.h"


namespace jmsf {
namespace typeing {


typedef internals::platform_memory_integer memory_integer_value_type;
typedef internals::platform_file_integer file_integer_value_type;

typedef internals::platform_shortest_fast_integer shortest_fast_integer_value_type;
typedef internals::platform_shortest_small_integer shortest_small_integer_value_type;
typedef internals::platform_short_fast_integer short_fast_integer_value_type;
typedef internals::platform_short_small_integer short_small_integer_value_type;
typedef internals::platform_fast_integer fast_integer_value_type;
typedef internals::platform_small_integer small_integer_value_type;
typedef internals::platform_long_fast_integer long_fast_integer_value_type;
typedef internals::platform_long_small_integer long_small_integer_value_type;


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


typedef Integers< memory_integer_value_type, 1 > Memory_integer;
typedef Integers< file_integer_value_type, 2 > File_integer;

typedef Integers< shortest_fast_integer_value_type, 3 > Shortest_integer;
typedef Integers< shortest_small_integer_value_type, 4 > Shortest_integer_small;
typedef Integers< short_fast_integer_value_type, 5 > Short_integer;
typedef Integers< short_small_integer_value_type, 6 > Short_integer_small;
typedef Integers< fast_integer_value_type, 7 > Integer;
typedef Integers< small_integer_value_type, 8 > Integer_small;
typedef Integers< long_fast_integer_value_type, 9 > Long_integer;
typedef Integers< long_small_integer_value_type, 10 > Long_integer_small;


} // namespace typeing
} // namespace jmsf
