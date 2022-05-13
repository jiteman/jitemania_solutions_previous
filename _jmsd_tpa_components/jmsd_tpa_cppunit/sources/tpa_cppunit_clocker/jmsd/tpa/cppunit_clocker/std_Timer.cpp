#include "std_Timer.h"


// static
double const std_Timer::MICROSECONDS_PER_SECOND = 1000000.0;


void std_Timer::start() {
	_start_time = ::std::chrono::high_resolution_clock::now();
}

void std_Timer::finish() {
	auto const stop_time = ::std::chrono::high_resolution_clock::now();
	_elapsed_time_in_microseconds = static_cast< double >( ::std::chrono::duration_cast< ::std::chrono::microseconds >( stop_time - _start_time ).count() );
	_elapsed_time_in_seconds = _elapsed_time_in_microseconds / MICROSECONDS_PER_SECOND;
}

double std_Timer::elapsedTime() const {
	return _elapsed_time_in_seconds;
}

double std_Timer::elapsed_time_in_microseconds() const {
	return _elapsed_time_in_microseconds;
}
