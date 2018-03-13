#ifndef CLIENTARRIVALCONSUMER_HPP
#define CLIENTARRIVALCONSUMER_HPP

#include <string>
#include <iostream>
#include <memory>
#include <atomic>
#include <thread>


#include "SynchronizationDeQue.hpp"
#include "ClientProducer.hpp"
#include "Client.hpp"
#include "BarberWaitingConsumer.hpp"

//To keep track of customer arrivals
std::atomic<bool> bl_clientArrived = false; 

//Create full class in hpp file for brevity
class ClientArrivalConsumer
{
private:
	SynchronizationDeque<Client>* m_deque;
	std::condition_variable * m_cv;

public:
	//Constructor
	ClientArrivalConsumer(SynchronizationDeque<Client>* deque, std::condition_variable * cv) 
		: m_deque(deque), m_cv(cv) {};

	//Fills queue with data
	void operator()() {

		//Continues until std::atomic<bool> shopOpen from BarberWaitingConsumer
		while (bl_shopOpen.load()) {

			//Create unique lock
			std::mutex mx;
			std::unique_lock<std::mutex> uqLock(mx);

			//Check for new client produced or if shop is closed
			while (!bl_clientProduced.load() && bl_shopOpen.load())  m_cv->wait(uqLock);

			if (bl_shopOpen.load()) {

				bl_clientProduced = false; //update atomic bool
				bl_clientArrived = true; //update atomic bool

				//Print
				std::cout << "A client has arrived.\n";

				//Notify
				m_cv->notify_all();

			}
			
		}
		//Termination statement
		std::cout << "ClientArrivalConsumer thread has terminated.\n";
	}



};

#endif