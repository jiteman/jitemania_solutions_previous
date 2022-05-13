#include "native_types.h"


#include <limits>


namespace jmsf {
namespace encodebuba {
namespace nativing {


const native_memory_natural CHAR_BIT_SIZE = 8;
const native_memory_natural MAXIMUM_INTEGRAL_SIZE = sizeof( native_long_natural );
const native_memory_natural MAXIMUM_INTEGRAL_BIT_SIZE = CHAR_BIT_SIZE * MAXIMUM_INTEGRAL_SIZE;
const native_short_real SHORT_REAL_DEFAULT_ACCURACY = ::std::numeric_limits< native_short_real >::epsilon(); // 0.000001f;
const native_real REAL_DEFAULT_ACCURACY = ::std::numeric_limits< native_real >::epsilon(); // 0.000000000000001;
const native_long_real LONG_REAL_DEFAULT_ACCURACY = ::std::numeric_limits< native_long_real >::epsilon();


} // namespace nativing
} // namespace encodebuba
} // namespace jmsf
