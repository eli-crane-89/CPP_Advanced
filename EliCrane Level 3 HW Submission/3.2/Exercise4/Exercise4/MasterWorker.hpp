#ifndef MASTERWORKER_HPP
#define MASTERWORKER_HPP


#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>

int data; //Resource worker updates
std::mutex m; //Mutex to syncrhonize access between resources

//Thread notification
std::condition_variable cv;

//Atomic booleans
//std::atomic<bool> workerReady = false;
//std::atomic<bool> masterReady = false;

std::atomic_flag workerReady = ATOMIC_FLAG_INIT;
std::atomic_flag masterReady = ATOMIC_FLAG_INIT;

//b) Thread function
void WorkerThread()
{
	std::cout << "Worker is called...\n";

	//False state: wait until master sends data
	//acquires lock
	std::unique_lock<std::mutex> mxLock(m); //acquires lock
	//cv.wait(mxLock, [] {return workerReady.load(); }
	cv.wait(mxLock, [] {return workerReady.test_and_set(std::memory_order_acquire); }); //waits for workerRead to be true


	//Now in True state
	std::cout << "Worker is processing data\n";
	data += 18956; //Add 100 to data

	//Notify master
	masterReady.test_and_set(std::memory_order_acquire); //Notifies master is ready

	//Postprocess
	mxLock.unlock(); //Unlock mutex
	cv.notify_one(); //Notifies waiting master thread
	std::cout << "Worker is exited...\n";
}

#endif	