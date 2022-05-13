#pragma once


namespace jmsf {
namespace typeing {


template< class A_type, int dummy > class Naturals;


} // namespace typeing
} // namespace jmsf


#include "internals/internal_types.h"


namespace jmsf {
namespace typeing {


typedef internals::platform_memory_natural memory_natural_value_type;
typedef internals::platform_file_natural file_natural_value_type;

typedef internals::platform_shortest_fast_natural shortest_fast_natural_value_type;
typedef internals::platform_shortest_small_natural shortest_small_natural_value_type;
typedef internals::platform_short_fast_natural short_fast_natural_value_type;
typedef internals::platform_short_small_natural short_small_natural_value_type;
typedef internals::platform_fast_natural fast_natural_value_type;
typedef internals::platform_small_natural small_natural_value_type;
typedef internals::platform_long_fast_natural long_fast_natural_value_type;
typedef internals::platform_long_small_natural long_small_natural_value_type;


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


typedef Naturals< memory_natural_value_type, 1 > Memory_natural;
typedef Naturals< file_natural_value_type, 2 > File_natural;

typedef Naturals< shortest_fast_natural_value_type, 3 > Shortest_natural;
typedef Naturals< shortest_small_natural_value_type, 4 > Shortest_natural_small;
typedef Naturals< short_fast_natural_value_type, 5 > Short_natural;
typedef Naturals< short_small_natural_value_type, 6 > Short_natural_small;
typedef Naturals< fast_natural_value_type, 7 > Natural;
typedef Naturals< small_natural_value_type, 8 > Natural_small;
typedef Naturals< long_fast_natural_value_type, 9 > Long_natural;
typedef Naturals< long_small_natural_value_type, 10 > Long_natural_small;


} // namespace typeing
} // namespace jmsf


#include "jmsf/jmsf.h"


// Eisha: move this stuff to memorying?
namespace jmsf {
namespace typeing {


// JMSF_DLL_INTERFACE
Memory_natural JMSF_SHARED_INTERFACE create_address_from_pointer( const void *memory_pointer ) noexcept;

template< class A_type >
A_type *get_pointer_from_Memory_natural( Memory_natural memory_address ) noexcept;


} // namespace typeing
} // namespace jmsf

