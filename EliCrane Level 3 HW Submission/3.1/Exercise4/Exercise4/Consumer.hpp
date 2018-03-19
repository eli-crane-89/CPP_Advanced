#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <string>
#include <iostream>
#include <memory>

#include "SynchronizationQueue.hpp"

class Consumer
{
private:
	int m_id;
	std::shared_ptr<SynchronizationQueue<std::string>> m_queue;

public:

	//Constructor
	Consumer(int id, std::shared_ptr<SynchronizationQueue<std::string>> queue) {
		m_id = id;
		m_queue = queue;
	}

	//Reads data from queue
	void operator() () {
		while (true) {
			std::cout << "Consumer " << std::to_string(m_id).c_str() << std::endl;
			std::cout << " consumed: (" << m_queue->Dequeue().c_str() << ")\n";

			//Provide interruption point
			boost::this_thread::interruption_point();
		}
	}

};

#endif