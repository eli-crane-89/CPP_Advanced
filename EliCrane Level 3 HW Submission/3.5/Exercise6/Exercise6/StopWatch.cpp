#ifndef STOPWATCH_CPP
#define STOPWATCH_CPP

#include <chrono>
#include <thread>

#include "StopWatch.hpp"

inline StopWatch::StopWatch() : storedTime(0.0), inProgress(false) {};

inline void StopWatch::StartStopWatch() {

	//Set the start time for the stop watch to now and marks the watch as in progress
	StopWatch::inProgress = true;
	StopWatch::startTime = std::chrono::system_clock::now();
}

inline void StopWatch::StopStopWatch() {
	//Stores the current time in storedTime and turns off in progress
	StopWatch::storedTime += StopWatch::GetTime();
	StopWatch::inProgress = false;
}

inline void StopWatch::Reset() {
	StopWatch::storedTime = 0;
	StopWatch::inProgress = false;
}

inline double StopWatch::GetTime() const{
	
	//If the stopwatch is in progress return the previously stored time + the diff between the last start time
	if (StopWatch::inProgress) {
		std::chrono::duration<double> diff = std::chrono::system_clock::now() - startTime;
		return diff.count() + StopWatch::storedTime;
	}
	//Else return the stored time
	else {
		return StopWatch::storedTime;
	}

	
}

#endif