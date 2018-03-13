#ifndef CLIENTSHOPFULLCONSUMER_HPP
#define CLIENTSHOPFULLCONSUMER_HPP

#include <string>
#include <iostream>
#include <atomic>
#include <chrono>

#include "SynchronizationDeQue.hpp"
#include "ClientArrivalConsumer.hpp"
#include "Client.hpp"
#include "BarberWaitingConsumer.hpp"

std::atomic<bool> bl_readyService = false;

//Create full class in hpp file for brevity
class ClientShopFullConsumer
{
private:
	int m_noChairs;
	SynchronizationDeque<Client>* m_deque;
	std::condition_variable* m_cv;

public:
	//Constructor
	ClientShopFullConsumer(int noChairs, SynchronizationDeque<Client>* deque, std::condition_variable * cv) 
		: m_noChairs(noChairs), m_deque(deque), m_cv(cv)  {};

	//Fills queue with data
	void operator()() {

		//Continues until std::atomic<bool> shopOpen from BarberWaitingConsumer
		while (bl_shopOpen.load()) {

			//Create unique lock
			std::mutex mx;
			std::unique_lock<std::mutex> uqLock(mx);

			//Check if client has arrived
			while (!bl_clientArrived.load() && bl_shopOpen.load()) m_cv->wait(uqLock);


			if (bl_shopOpen.load()) {
				//turn off arrived flag
				bl_clientArrived = false;

				//Check if size of dequeu is greater than number of chairs
				if (m_deque->GetDequeSize() > m_noChairs) {

					//Use false to specify pop from back
					std::cout << "The barbershop is full and the customer " << m_deque->Deque(false).m_name << " has exited.\n";
				}
				else {

					//Time it takes to seat customer
					std::this_thread::sleep_for(std::chrono::seconds(2));

					//turn on ready service flag
					bl_readyService = true;
					std::cout << "The client has been seated and is ready for service\n";

					//notify
					m_cv->notify_all();
				}
			}	
		}
		std::cout << "ClientShopFullConsumer has termianted.\n";
	}



};

#endif