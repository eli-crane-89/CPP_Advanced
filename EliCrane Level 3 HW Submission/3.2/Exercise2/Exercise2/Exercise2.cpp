// Exercise2.cpp : Defines the entry point for the console application.
//

#include <thread>

#include "X.h"

int main()
{
	PointerType pt = PointerType(new X());

	
	//b) create thread array
	const int noThreads = 100;
	std::thread myThreads[noThreads];

	for (int i = 0; i < noThreads; i++) {
		myThreads[i] = std::thread(Modify, pt, static_cast<double>(i));
	}

	//Join threads
	for (int i = 0; i < noThreads; i++) {
		myThreads[i].join();
		std::cout << "The value of pt is: " << pt->val << std::endl;
	}

	//c)
	//Running the program several times demonstrates that the thread with the highest sleep time
	//end up being the thread that makes the final modification. The value remains the same after
	//a thread has been joined until a subsequent thread has a longer sleep time and changes the value of the 
	//std::cout

    return 0;
}

