#include "System_time.h"


#include "jmsf/typeing/Naturals.hin"

#include "jmsf/al_std/stl_hin/ctime_al_std.hin"


namespace jmsf {
namespace cule {
namespace to_libs {
namespace system {


// static
const typeing::Natural System_time::MILLISECONDS_IN_SECOND = typeing::Natural::create( 1000 );


System_time::~System_time() noexcept
{}

System_time::System_time() noexcept
{}

System_time::System_time( const System_time & ) noexcept
{}

const System_time &System_time::operator=( const System_time & ) noexcept {
	return *this;
}

typeing::Natural System_time::getCurrentTimeInMilliseconds() const noexcept {
	const typeing::Natural clocksInThousand = typeing::Natural::create( static_cast< typeing::Natural::my_natural_integral_type >( ::clock() ) ) * MILLISECONDS_IN_SECOND;
	return clocksInThousand / typeing::Natural::create( CLOCKS_PER_SEC );
}


} // namespace
}
}
}
