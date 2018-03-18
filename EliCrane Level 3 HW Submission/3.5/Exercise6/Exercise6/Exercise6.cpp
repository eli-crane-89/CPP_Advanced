#include <iostream>
#include <thread>
#include <chrono>

#include "StopWatch.hpp"

void ThreadTest(int durSleep) {
	std::this_thread::sleep_for(std::chrono::seconds(durSleep));
}

int main()
{
	StopWatch sw;
	std::cout << "Starting test...\n";

	sw.StartStopWatch();
	std::thread t_sleep5(ThreadTest, 5);
	t_sleep5.join();
	sw.StopStopWatch();
	std::cout << "It took t_sleep5 " << sw.GetTime() << " seconds to complete\n";

	sw.StartStopWatch();
	std::thread t_sleep3(ThreadTest, 3);
	t_sleep3.join();
	std::cout << "It took t_sleep5 + t_sleep3 " << sw.GetTime() << " seconds to complete\n";

	sw.Reset();
	std::cout << "The stopwatch has been running for " << sw.GetTime() << " seconds after the reset.\n";

	
	



    return 0;
}

