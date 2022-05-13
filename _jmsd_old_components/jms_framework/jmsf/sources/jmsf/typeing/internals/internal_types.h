#pragma once


#include "jmsf/encodebuba/nativing/native_types.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace typeing {
namespace internals {


typedef encodebuba::nativing::native_byte platform_byte;
typedef encodebuba::nativing::native_character platform_character;

typedef encodebuba::nativing::native_shortest_integer platform_shortest_integer;
typedef encodebuba::nativing::native_shortest_natural platform_shortest_natural;

typedef encodebuba::nativing::native_short_integer platform_short_integer;
typedef encodebuba::nativing::native_short_natural platform_short_natural;

typedef encodebuba::nativing::native_integer platform_integer;
typedef encodebuba::nativing::native_natural platform_natural;

typedef encodebuba::nativing::native_long_integer platform_long_integer;
typedef encodebuba::nativing::native_long_natural platform_long_natural;

typedef encodebuba::nativing::native_memory_integer platform_memory_integer;
typedef encodebuba::nativing::native_memory_natural platform_memory_natural;

typedef platform_long_integer platform_file_integer;
typedef platform_long_natural platform_file_natural;

typedef bool platform_boolean;

typedef float platform_short_real;
typedef double platform_real;
typedef long double platform_long_real;


} // namespace internals


#if JMSD_CPLUSPLUS_VERSION_VALUE >= JMSD_CPLUSPLUS11_VERSION_CONSTANT


namespace internals {


typedef encodebuba::nativing::native_shortest_fast_integer platform_shortest_fast_integer;
typedef encodebuba::nativing::native_shortest_small_integer platform_shortest_small_integer;
typedef encodebuba::nativing::native_shortest_fast_natural platform_shortest_fast_natural;
typedef encodebuba::nativing::native_shortest_small_natural platform_shortest_small_natural;

typedef encodebuba::nativing::native_short_fast_integer platform_short_fast_integer;
typedef encodebuba::nativing::native_short_small_integer platform_short_small_integer;
typedef encodebuba::nativing::native_short_fast_natural platform_short_fast_natural;
typedef encodebuba::nativing::native_short_small_natural platform_short_small_natural;

typedef encodebuba::nativing::native_fast_integer platform_fast_integer;
typedef encodebuba::nativing::native_small_integer platform_small_integer;
typedef encodebuba::nativing::native_fast_natural platform_fast_natural;
typedef encodebuba::nativing::native_small_natural platform_small_natural;

typedef encodebuba::nativing::native_long_fast_integer platform_long_fast_integer;
typedef encodebuba::nativing::native_long_small_integer platform_long_small_integer;
typedef encodebuba::nativing::native_long_fast_natural platform_long_fast_natural;
typedef encodebuba::nativing::native_long_small_natural platform_long_small_natural;


} // namespace internals


#else
	#error This file "jmsf/typeing/internals/internal_types.h" - fast and least integral types required (C++11). Old versions of C++ are not supported yet.

#endif


extern const internals::platform_memory_natural CHAR_BIT_SIZE;
extern const internals::platform_memory_natural MAXIMUM_INTEGRAL_SIZE;
extern const internals::platform_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE;
extern const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY;
extern const internals::platform_real REAL_DEFAULT_ACCURACY;
extern const internals::platform_long_real LONG_REAL_DEFAULT_ACCURACY;


// const internals::platform_memory_natural CHAR_BIT_SIZE = 8;
// const internals::platform_memory_natural MAXIMUM_INTEGRAL_SIZE = sizeof( internals::platform_long_natural );
// const internals::platform_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE = CHAR_BIT_SIZE * MAXIMUM_INTEGRAL_SIZE;
// const internals::platform_real REAL_DEFAULT_ACCURACY = 0.000000000000001;
// const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY = 0.000001f;


} // namespace typeing
} // namespace jmsf
