#include "MasterWorker.hpp"

int main()
{
	//c)Implements master duties
	std::cout << "Master is called...\n";
	std::thread worker(WorkerThread); //Create worker thread

	//Transition intro True state
	{
		std::lock_guard<std::mutex> mxLock(m); //Create mutex lock
		//workerReady = true; //lets WorkerThread know worker is ready
		workerReady.test_and_set(std::memory_order_acquire);
	}

	std::cout << "Master has notified worker, wait for response...\n";
	cv.notify_one(); //Notifies thread that workerThread has completed
	
	{
		std::unique_lock<std::mutex> mxLock(m); //locks thread
		//cv.wait(mxLock, [] { return masterReady.load();}
		cv.wait(mxLock, [] { return masterReady.test_and_set(std::memory_order_acquire); }); //waits for masterReady to be true
	}
	
	std::cout << "Master back again...\n";

	worker.join(); //join threads

	std::cout << "The data is: " << data << std::endl;
	
    return 0;
}

