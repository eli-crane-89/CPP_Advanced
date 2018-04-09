#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>
#include <atomic>

class StopWatch
{
public:
	StopWatch();

	StopWatch & operator=(const StopWatch &);

	void StartStopWatch();
	void StopStopWatch();
	void Reset();

	double GetTime() const;
private:
	double storedTime;
	std::chrono::time_point<std::chrono::system_clock> startTime;
	bool inProgress;

	StopWatch(const StopWatch &);
	
};

#endif // ! STOPWATCH_HPP