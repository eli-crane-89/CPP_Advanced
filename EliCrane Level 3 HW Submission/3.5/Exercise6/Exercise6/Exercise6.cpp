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

	sw.StopStopWatch();
	std::cout << "Running thread without stopwatch to show it stop\n";
	std::thread t_sleep2(ThreadTest, 2);
	t_sleep2.join();
	std::cout << "The time on the stop watch after 2 more seconds is still: " << sw.GetTime() << " seconds to complete\n";

	sw.Reset();
	std::cout << "The stopwatch has been running for " << sw.GetTime() << " seconds after the reset.\n";

	
	



    return 0;
}

