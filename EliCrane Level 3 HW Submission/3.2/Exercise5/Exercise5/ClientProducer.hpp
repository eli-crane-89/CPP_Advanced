#ifndef CLIENTPRODUCER_HPP
#define CLIENTPRODUCER_HPP

#include <string>
#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include <chrono>

#include "Client.hpp"

#include "SynchronizationDeQue.hpp"

std::condition_variable cv_client;
std::atomic<bool> bl_clientProduced = false; //to keep track of new customers

class ClientProducer
{
private:
	std::vector<std::string> m_vNames;
	SynchronizationDeque<Client>* m_deque; 
	std::condition_variable * m_cv;

public:

	//Constructor
	ClientProducer(std::vector<std::string> vNames, SynchronizationDeque<Client>* deque, std::condition_variable * cv) 
		: m_vNames(vNames), m_deque(deque), m_cv(cv) {};

	//Reads data from queue
	void operator() () {


		//Iterator through a vector of names
		for (auto name : m_vNames) {

			//Create a client
			Client c = Client(name);

			std::cout << "The customer: " << c.m_name << " wants a haircut.\n";
				
			//Enqueue client
			m_deque->Enqueue(c);

			//Turn on client produced flag
			bl_clientProduced = true;
			std::cout << "The customer: " << c.m_name << " has been placed in queue.\n";

			//Notify threads for change in condition
			m_cv->notify_all();

			//Sleep producer for 10 seconds
			std::this_thread::sleep_for(std::chrono::seconds(10));


		}

	}

};

#endif