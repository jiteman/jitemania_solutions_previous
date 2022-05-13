#pragma once


#include "jmsf/cule/executing/Test_stop_watch.h"

//#include "jmsf/pointing/Pointer.hpp"

#include "jmsf/pointing/Shared.hpp"

#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/cule/realizing/realization_cule_Environment.hxx"
#include "jmsf/cule/to_libs/system/System_time.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace cule {
namespace executing {
namespace realizing {


class realization_Test_stop_watch :
	public Test_stop_watch
{

public:
	// virtuals Test_stop_watch
	typeing::Natural get_global_duration();
	typeing::Natural get_local_duration();
	void start_global();
	void start_local();
	//~virtuals Test_stop_watch

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~realization_Test_stop_watch() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Test_stop_watch, realization_Test_stop_watch >;
	realization_Test_stop_watch( const pointing::Shared< to_libs::system::System_time> &system_time ) noexcept;

private: friend cule::realizing::realization_cule_Environment;
	static memorying::Omp< Test_stop_watch > create(
		const memorying::Womp< memorying::Allocator > &an_allocator,
		const pointing::Shared< to_libs::system::System_time > &system_time );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_Test_stop_watch( const realization_Test_stop_watch &another ) noexcept;
	const realization_Test_stop_watch &operator =( const realization_Test_stop_watch &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typeing::Natural _global_at_start;
	typeing::Natural _local_at_start;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Shared< to_libs::system::System_time > _system_time_device;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace executing
} // namespace cule
} // namespace jmsf
