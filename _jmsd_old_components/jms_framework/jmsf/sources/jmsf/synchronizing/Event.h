#pragma once

#include "Event.hxx"


#include <mutex>
#include <condition_variable>
#include <chrono>


#include "jmsf/jmsf.h"


namespace jmsf {
namespace synchronizing {


class JMSF_SHARED_INTERFACE Event {

public:
	Event();

	bool wait() const;

	template< typename R,typename P >
	bool wait( ::std::chrono::duration< R, P > const &relative_time ) const;

	bool signal();
	bool reset();
	bool is_set() const;

	void signal_to_cancel();
	bool is_set_to_cancel() const;

private:
	bool is_signaled_or_is_canceled() const;

private:
	bool _is_set;
	bool _is_set_to_cancel;
	mutable ::std::mutex _the_mutex;
	mutable ::std::condition_variable _condition_variable;
};


} // namespace synchronizing
} // namespace jmsf
