#ifndef SERVICECONSUMER_HPP
#define SERVICECONSUMER_HPP

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

#include "Client.hpp"

#include "SynchronizationDeQue.hpp"
#include "ClientShopFullConsumer.hpp"
#include "BarberWaitingConsumer.hpp"

//Atomic to keep track of state
std::atomic<bool> bl_serviced = false;

//Create full class in hpp file for brevity
class ServiceConsumer
{
private:
	std::string m_service;
	SynchronizationDeque<Client>* m_deque;
	std::condition_variable* m_cv;

public:
	//Constructor
	ServiceConsumer(std::string service, SynchronizationDeque<Client>* deque, std::condition_variable * cv) 
		: m_service(service), m_deque(deque), m_cv(cv) {};

	//Fills queue with data
	void operator()() {
		int data = 0;

		//Continues until std::atomic<bool> shopOpen from BarberWaitingConsumer
		while (bl_shopOpen.load()) {

			//Create unique lock 
			std::mutex mx;
			std::unique_lock<std::mutex> uqLock(mx);

			//Look for service flag or shopOpen flag
			while (!bl_readyService && bl_shopOpen.load()) m_cv->wait(uqLock);
			
			if (bl_shopOpen.load()) {

				//Turn off ready service flag
				bl_readyService = false;

				//Time it takes to receive service
				std::cout << "The client is receiving a service of " << m_service << ".\n";
				std::this_thread::sleep_for(std::chrono::seconds(8));

				//Turn on serviced flag
				bl_serviced = true;

				//Notify
				m_cv->notify_all();
			}
		}
		//Termiantion statement
		std::cout << "ServiceConsumer has termianted.\n";
	}



};

#endif