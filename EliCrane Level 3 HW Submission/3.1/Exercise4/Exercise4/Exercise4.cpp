#include <boost\thread.hpp>
#include <string>
#include <memory>

#include "SynchronizationQueue.hpp"
#include "Producer.hpp"
#include "Consumer.hpp"

using namespace std;

int main()
{
	//The number of producers/consumers
	int nrProducers = 3, nrConsumers = 3;

	//The shared queue
	std:shared_ptr<SynchronizationQueue<string>> sp_queue(new SynchronizationQueue<string>);

	//Create producers
	boost::thread_group producers;
	for (int i = 0; i < nrProducers; i++) {
		Producer p(i, sp_queue);
		producers.create_thread(p);
	}

	//Create consumers
	boost::thread_group consumers;
	for (int i = 0; i < nrConsumers; i++) {
		Consumer p(i, sp_queue);
		consumers.create_thread(p);
	}

	// Wait for enter
	getchar();

	// Interrupt the threads and stop them
	producers.interrupt_all(); 
	producers.join_all();
	consumers.interrupt_all(); consumers.join_all();

    return 0;
}

