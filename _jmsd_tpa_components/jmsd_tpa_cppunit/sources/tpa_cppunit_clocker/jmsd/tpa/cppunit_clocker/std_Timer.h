#pragma once


#include <chrono>


class std_Timer {
public:
	void start(); // start
	void finish(); // stop

	double elapsedTime() const; // in seconds
	double elapsed_time_in_microseconds() const;

private:
	::std::chrono::time_point< ::std::chrono::high_resolution_clock > _start_time;
	double _elapsed_time_in_microseconds;
	double _elapsed_time_in_seconds;

private:
	static double const MICROSECONDS_PER_SECOND; // = 1000000.0;
};
