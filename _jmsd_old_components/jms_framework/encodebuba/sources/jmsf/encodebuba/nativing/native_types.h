#pragma once


#include "jmsd/platform_support/platform_detection/standard_detection.h"


#if JMSD_CPLUSPLUS_VERSION_VALUE >= JMSD_CPLUSPLUS11_VERSION_CONSTANT
	#include <cstdint>

#endif


#include "jmsd/platform_support/platform_detection/memory_model_detection.h"


namespace jmsf {
namespace encodebuba {
namespace nativing {


	typedef ::jmsd::platform_support::memory_models::byte_type native_byte;
	typedef ::jmsd::platform_support::memory_models::character_type native_character;

	typedef ::jmsd::platform_support::memory_models::integer_1_byte_type native_shortest_integer;
	typedef ::jmsd::platform_support::memory_models::natural_1_byte_type native_shortest_natural;

	typedef ::jmsd::platform_support::memory_models::integer_2_bytes_type native_short_integer;
	typedef ::jmsd::platform_support::memory_models::natural_2_bytes_type native_short_natural;

	typedef ::jmsd::platform_support::memory_models::integer_4_bytes_type native_integer;
	typedef ::jmsd::platform_support::memory_models::natural_4_bytes_type native_natural;

	typedef ::jmsd::platform_support::memory_models::integer_8_bytes_type native_long_integer;
	typedef ::jmsd::platform_support::memory_models::natural_8_bytes_type native_long_natural;

	typedef ::jmsd::platform_support::memory_models::integer_pointer_type native_memory_integer;
	typedef ::jmsd::platform_support::memory_models::natural_pointer_type native_memory_natural;

	typedef native_long_integer native_file_integer;
	typedef native_long_natural native_file_natural;

	typedef bool native_boolean;

	typedef float native_short_real;
	typedef double native_real;
	typedef long double native_long_real;


} // namespace nativing


#if JMSD_CPLUSPLUS_VERSION_VALUE >= JMSD_CPLUSPLUS11_VERSION_CONSTANT


namespace nativing {


typedef std::int_fast8_t native_shortest_fast_integer;
typedef std::int_least8_t native_shortest_small_integer;
typedef std::uint_fast8_t native_shortest_fast_natural;
typedef std::uint_least8_t native_shortest_small_natural;

typedef std::int_fast16_t native_short_fast_integer;
typedef std::int_least16_t native_short_small_integer;
typedef std::uint_fast16_t native_short_fast_natural;
typedef std::uint_least16_t native_short_small_natural;

typedef std::int_fast32_t native_fast_integer;
typedef std::int_least32_t native_small_integer;
typedef std::uint_fast32_t native_fast_natural;
typedef std::uint_least32_t native_small_natural;

typedef std::int_fast64_t native_long_fast_integer;
typedef std::int_least64_t native_long_small_integer;
typedef std::uint_fast64_t native_long_fast_natural;
typedef std::uint_least64_t native_long_small_natural;


} // namespace nativing


#else
	#error This file "jmsf/typeing/internals/internal_types.h" - fast and least integral types required (C++11). Old versions of C++ are not supported yet.

#endif


extern const nativing::native_memory_natural CHAR_BIT_SIZE;
extern const nativing::native_memory_natural MAXIMUM_INTEGRAL_SIZE;
extern const nativing::native_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE;
extern const nativing::native_short_real SHORT_REAL_DEFAULT_ACCURACY;
extern const nativing::native_real REAL_DEFAULT_ACCURACY;
extern const nativing::native_long_real LONG_REAL_DEFAULT_ACCURACY;


} // namespace encodebuba
} // namespace jmsf
