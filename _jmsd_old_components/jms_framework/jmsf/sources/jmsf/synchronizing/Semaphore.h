#pragma once

#include "Semaphore.hxx"


#include <mutex>
#include <condition_variable>
#include <chrono>


#include "jmsf/jmsf.h"


namespace jmsf {
namespace synchronizing {


class JMSF_SHARED_INTERFACE Semaphore {

public:
	Semaphore( size_t signal_counter );

	bool wait();

	template< typename R,typename P >
	bool wait( ::std::chrono::duration< R, P > const &relative_time );

	void signal();

	void set_to_cancel();
	bool is_set_to_cancel() const;

private:
	size_t _signal_counter;
	bool _is_set_to_cancel;
	mutable ::std::mutex _the_mutex;
	::std::condition_variable _condition_variable;
};


} // namespace synchronizing
} // namespace jmsf
