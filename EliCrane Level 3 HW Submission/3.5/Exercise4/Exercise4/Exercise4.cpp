
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

#include "SynchronizationQueue.hpp"


//a) Comparator
struct CommandComparator {
	bool operator()(const long lhs, const long rhs) const {
		return lhs > rhs;
	}
};

//Thread functions
void insertVectorOfLongs(std::vector<long>& vLong, SynchronizationQueue<long, std::vector<long>, CommandComparator>  * queue) {
	
	while (vLong.size() > 0) {
		queue->Enqueue(vLong.back());
		std::cout << vLong.back() << " has just been enqueued.\n";
		vLong.pop_back();
		std::this_thread::sleep_for(std::chrono::seconds(2)); //wait to space out
	}
}

//Thread functions
void dequeLongs(SynchronizationQueue<long, std::vector<long>, CommandComparator>  * queue) {

	while (queue->GetSize() > 0) {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		
		std::cout << queue->Dequeue() << " has just been deqeued.\n";
	}
}



int main()
{
	//a)
	SynchronizationQueue<long, std::vector<long>, CommandComparator> queue;

	//b) locks added

	//c) Notifications added

	//d) Test
	std::vector<long> vLong({ 200,12345,8474,123,94567 });
	std::thread t_insert(insertVectorOfLongs, vLong, &queue);
	std::thread t_dq(dequeLongs, &queue);

	t_insert.join();
	t_dq.join();


    return 0;
}

