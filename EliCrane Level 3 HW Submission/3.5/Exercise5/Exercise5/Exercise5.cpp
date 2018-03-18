#include <iostream>
#include <vector>
#include <string>
#include <boost\thread.hpp>
#include <atomic>

#include "SynchronizationQueue.hpp"

//For keeping track of whether queue is empty
std::atomic<bool> readyForDeque = false;
std::atomic<bool> emptyQueue = false;

struct CommandComparator {
	bool operator()(const long lhs, const long rhs) const {
		return lhs > rhs;
	}
};

//Thread function for producing. Can be distinguished by different pace.
void insertVectorOfLongs(std::vector<long>& vLong, SynchronizationQueue<long, std::vector<long>, CommandComparator>  * queue, int pace) {

	while (vLong.size() > 0) {
		queue->Enqueue(vLong.back());
		std::cout << vLong.back() << " has just been enqueued.\n";
		vLong.pop_back();
		std::this_thread::sleep_for(std::chrono::seconds(pace)); //wait to space out
	}
}

//Thread function for consuming. Can be distinguished by different description and pace
void dequeLongs(SynchronizationQueue<long, std::vector<long>, CommandComparator>  * queue, std::condition_variable* cv, std::string desc, int pace) {
	std::this_thread::sleep_for(std::chrono::seconds(5)); //wait for quque
	
	//Continue while emptyQueue = false
	while (!emptyQueue.load()) {
		//Create unique lock
		std::mutex mx;
		std::unique_lock<std::mutex> uqLock(mx);

		//Either readyForDeque == true or emptyQueue == true breaks wait
		while (!readyForDeque.load() && !emptyQueue.load()) cv->wait(uqLock); {
			
			//Only dequeu if not empty queue
			if (!emptyQueue.load()) {
				std::cout << queue->Dequeue() << " has just been deqeued in a " << desc << " fashion.\n";
				readyForDeque = false;
				std::this_thread::sleep_for(std::chrono::seconds(pace));
			}

		}
	}

}

//Thread function for stop condition
void notifyEmpty(SynchronizationQueue<long, std::vector<long>, CommandComparator>  * queue, std::condition_variable* cv) {
	std::this_thread::sleep_for(std::chrono::seconds(4)); //wait for queue to fill

	while (queue->GetSize() > 0) {
		readyForDeque = true;
		
		//notify
		cv->notify_all();

		//Sleep
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	//flip flag and notify
	emptyQueue = true;
	cv->notify_all();
}

int main()
{
	//a) the std way
	SynchronizationQueue<long, std::vector<long>, CommandComparator> queue;

	std::vector<long> vLong1({ 200,12345,8474,123,94567 });
	std::vector<long> vLong2({ 3345,128757,912345, 36789456, 23190022 });
	//boost::thread t_insert1(insertVectorOfLongs, vLong1, &queue, 1);
	//boost::thread t_insert2(insertVectorOfLongs, vLong2, &queue, 2);
	//boost::thread_group tg_producers;
	//tg_producers.add_thread(&t_insert1);
	//tg_producers.add_thread(&t_insert2);

	//b) the boost way

	//boost::thread t_dq1(dequeLongs, &queue, "ultimate", 3);
	//boost::thread t_dq2(dequeLongs, &queue, "resplendent", 5);
	//boost::thread_group tg_consumers;
	//tg_consumers.add_thread(&t_dq1);
	//tg_consumers.add_thread(&t_dq2);

	//tg_producers.join_all();
	//tg_consumers.join_all();

	//c) the c++ 11 way
	//Producers
	std::thread t_insert1(insertVectorOfLongs, vLong1, &queue, 1);
	std::thread t_insert2(insertVectorOfLongs, vLong2, &queue, 2);

	std::condition_variable cv;

	//Consumers
	std::thread t_dq1(dequeLongs, &queue, &cv, "ultimate", 3);
	std::thread t_dq2(dequeLongs, &queue, &cv, "resplendent", 5);

	//For notify
	std::thread t_notify(notifyEmpty, &queue, &cv);

	t_insert1.join();
	t_insert2.join();
	t_dq1.join();
	t_dq2.join();
	t_notify.join();


    return 0;
}

