#include "Semaphore.h"


namespace jmsf {
namespace synchronizing {


Semaphore::Semaphore( size_t const signal_counter ) {
	_signal_counter = signal_counter;
	_is_set_to_cancel = false;
}

bool Semaphore::wait() {
	bool was_canceled = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		_condition_variable.wait( lock, [ & ]()->bool{ return _signal_counter > 0 || _is_set_to_cancel; } );
		was_canceled = _is_set_to_cancel;

		if ( _signal_counter != 0 ) {
			--_signal_counter;
		}
	}

	return was_canceled;
}

void Semaphore::signal() {
	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		++_signal_counter;
	}

	_condition_variable.notify_one();
}

void Semaphore::set_to_cancel() {
	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		_is_set_to_cancel = true;
	}

	_condition_variable.notify_all();
}

bool Semaphore::is_set_to_cancel() const {
	bool is_set_to_cancel = false;

	{
		::std::unique_lock< ::std::mutex > lock( _the_mutex );
		is_set_to_cancel = _is_set_to_cancel;
	}

	return is_set_to_cancel;
}


} // namespace synchronizing
} // namespace jmsf
