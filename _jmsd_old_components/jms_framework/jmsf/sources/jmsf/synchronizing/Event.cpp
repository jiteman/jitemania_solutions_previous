#include "Event.h"

#include <functional>


namespace jmsf {
namespace synchronizing {


Event::Event() {
	_is_set = false;
	_is_set_to_cancel = false;
}

bool Event::wait() const {
	bool was_canceled = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		//_condition_variable.wait( lock, [ & ]()->bool{ return _is_set || _is_set_to_cancel; } );
		_condition_variable.wait( lock, ::std::bind( &Event::is_signaled_or_is_canceled, this ) );
		was_canceled = _is_set_to_cancel;
	}

	return !was_canceled;
}

bool Event::signal() {
	bool was_signalled = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		was_signalled = _is_set;
		_is_set = true;
	}

	_condition_variable.notify_all();
	return was_signalled == false;
}

bool Event::reset() {
	bool was_signalled = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		was_signalled = _is_set;
		_is_set = false;
	}

	return was_signalled;
}

bool Event::is_set() const {
	bool is_set = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		is_set = _is_set;
	}

	return is_set;
}

void Event::signal_to_cancel() {
	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		_is_set = false;
		_is_set_to_cancel = true;
	}

	this->signal();
}

bool Event::is_set_to_cancel() const {
	bool is_set_to_cancel = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		is_set_to_cancel = _is_set_to_cancel;
	}

	return is_set_to_cancel;
}

bool Event::is_signaled_or_is_canceled() const {
	return _is_set || _is_set_to_cancel;
}


} // namespace synchronizing
} // namespace jmsf
