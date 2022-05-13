#include "realization_Test_stop_watch.h"


#include "jmsf/cule/to_libs/system/System_time.h"

//#include "jmsf/pointing/Pointer.hin"

#include "jmsf/pointing/Shared.hin"

#include "jmsf/patterning/Singleton.hin"


namespace jmsf {
namespace cule {
namespace executing {
namespace realizing {


// virtuals Test_stop_watch
typeing::Natural realization_Test_stop_watch::get_global_duration() {
	return _system_time_device->getCurrentTimeInMilliseconds() - _global_at_start;
}

typeing::Natural realization_Test_stop_watch::get_local_duration() {
	return _system_time_device->getCurrentTimeInMilliseconds() - _local_at_start;
}

void realization_Test_stop_watch::start_global() {
	_global_at_start = _system_time_device->getCurrentTimeInMilliseconds();
}

void realization_Test_stop_watch::start_local() {
	_local_at_start = _system_time_device->getCurrentTimeInMilliseconds();
}
//~virtuals Test_stop_watch

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Test_stop_watch::~realization_Test_stop_watch() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Test_stop_watch::realization_Test_stop_watch( const pointing::Shared< to_libs::system::System_time > &system_time ) noexcept
	:
		_system_time_device( system_time )
{}

// static
memorying::Omp< Test_stop_watch > realization_Test_stop_watch::create(
	const memorying::Womp<memorying::Allocator> &an_allocator,
	const pointing::Shared< to_libs::system::System_time > &system_time )
{
	return memorying::Constructor< Test_stop_watch, realization_Test_stop_watch >::construct( an_allocator, system_time );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Test_stop_watch::realization_Test_stop_watch( const realization_Test_stop_watch &/*another*/ ) noexcept {
}

const realization_Test_stop_watch &realization_Test_stop_watch::operator =( const realization_Test_stop_watch &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace realizing
} // namespace executing
} // namespace cule
} // namespace jmsf
