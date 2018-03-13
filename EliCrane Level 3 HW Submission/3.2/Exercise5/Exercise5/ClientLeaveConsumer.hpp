#ifndef CLIENTLEAVECONSUMER_HPP
#define CLIENTLEAVECONSUMER_HPP

#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include "Client.hpp"

#include "SynchronizationDeQue.hpp"
#include "ServiceConsumer.hpp"


//Create full class in hpp file for brevity
class ClientLeaveConsumer
{
private:

	SynchronizationDeque<Client>* m_deque;
	std::condition_variable* m_cv;

public:
	//Constructor
	ClientLeaveConsumer(SynchronizationDeque<Client>* deque, std::condition_variable * cv) : m_deque(deque), m_cv(cv) {};

	//Fills queue with data
	void operator()() {

		//Continues until std::atomic<bool> shopOpen from BarberWaitingConsumer
		while (bl_shopOpen.load()) {

			//Create unique lock 
			std::mutex mx;
			std::unique_lock<std::mutex> uqLock(mx);

			//Wait for serviced flag or shopOpen
			while (!bl_serviced && bl_shopOpen.load()) m_cv->wait(uqLock);
			
			if (bl_shopOpen.load()) {
				bl_serviced = false; //Turn off serviced flag

				//Dequeu customer
				std::this_thread::sleep_for(std::chrono::seconds(2)); //Time it takes to leave
				std::cout << "The customer " << m_deque->Deque(true).m_name << " has received service and is now leaving.\n";
			}
		}
		//Termination statement
		std::cout << "ClientLeaveConsumer has termianted.\n";
	}



};

#endif