#ifndef BARBERWAITINGCONSUMER_HPP
#define BARBERWAITINGCONSUMER_HPP

#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

#include "SynchronizationDeQue.hpp"

//Atomic to check for application termination
std::atomic<bool> bl_shopOpen = true;

//Global function variable for the amount of times to wait before terminating.
int noWaitCount = 3;

//Create full class in hpp file for brevity
class BarberWaitingConsumer
{
private:
	SynchronizationDeque<Client>* m_deque;
	std::condition_variable* m_cv;

public:
	//Constructor
	BarberWaitingConsumer(SynchronizationDeque<Client>* deque, std::condition_variable * cv) 
		: m_deque(deque), m_cv(cv) {};

	//Fills queue with data
	void operator()() {
		int waitCount; //Counts waits

	    //Continues until std::atomic<bool> shopOpen from BarberWaitingConsumer
		while (bl_shopOpen.load()) {

			//Reset to 0
			waitCount = 0;

			//Check DequeuSize and waitCount
			while (m_deque->GetDequeSize() == 0 && waitCount < noWaitCount) {
				waitCount++;
				std::cout << "The barber is waiting on customers.\n";

				if (waitCount < noWaitCount) { //Dont wait on third
					//Sleep the thread for 5 seconds
					std::this_thread::sleep_for(std::chrono::seconds(5));
				}
			}

			//If wait count is 3, close shop via terminate
			if (waitCount == noWaitCount) {
				bl_shopOpen = false;
				std::cout << "Looks like no new customers, the barber is closing shop and going home.\n";
				std::this_thread::sleep_for(std::chrono::seconds(2)); //Time to close

				//Notify of shop close
				m_cv->notify_all();
			}
		}

		//Termination statement
		std::cout << "BarberWaitingConsumer has terminated.\n";
		
	}



};

#endif