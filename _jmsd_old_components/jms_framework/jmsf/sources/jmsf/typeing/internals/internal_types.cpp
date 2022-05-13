#include "internal_types.h"


#include <limits>


namespace jmsf {
namespace typeing {


const internals::platform_memory_natural CHAR_BIT_SIZE = 8;
const internals::platform_memory_natural MAXIMUM_INTEGRAL_SIZE = sizeof( internals::platform_long_natural );
const internals::platform_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE = CHAR_BIT_SIZE * MAXIMUM_INTEGRAL_SIZE;
const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY = ::std::numeric_limits< internals::platform_short_real >::epsilon(); // 0.000001f;
const internals::platform_real REAL_DEFAULT_ACCURACY = ::std::numeric_limits< internals::platform_real >::epsilon(); // 0.000000000000001;
const internals::platform_long_real LONG_REAL_DEFAULT_ACCURACY = ::std::numeric_limits< internals::platform_long_real >::epsilon();


} // namespace typeing
} // namespace jmsf
