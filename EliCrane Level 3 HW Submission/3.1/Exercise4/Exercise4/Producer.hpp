#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <string>
#include <iostream>

#include "SynchronizationQueue.hpp"

//Create full class in hpp file for brevity
class Producer
{
private:
	int m_id;
	SynchronizationQueue<std::string>* m_queue;

public:
	//Constructor
	Producer(int id, SynchronizationQueue<std::string>* queue) {
		m_id = id;
		m_queue = queue;
	}

	//Fills queue with data
	void operator()() {
		int data = 0;

		while (true) {

			//Produce an incrementing string and put in queue
			std::string str = "Producer: " + std::to_string(m_id) + " data: " + std::to_string(data++);
			m_queue->Enqueue(str);

			std::cout << str << std::endl;

			//Sleep the thread for a second
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}
	}



};

#endif