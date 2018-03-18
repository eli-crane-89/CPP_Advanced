#ifndef SYNCHRONIZATIONQUEUE_CPP
#define SYNCHRONIZATIONQUEUE_CPP

#include <thread>
#include "SynchronizationQueue.hpp"



template<typename T, class Container, class Comparator>
void SynchronizationQueue<T, Container, Comparator>::Enqueue(const T& data) {
	
	//Put lock on queue
	std::unique_lock<std::mutex> lock(SynchronizationQueue<T, Container, Comparator>::m_mutex);

	//Add the data to queue
	m_queue.push(data);

	//Notify others that data is ready
	m_cond.notify_one();
}

template<typename T, class Container, class Comparator>
T SynchronizationQueue<T, Container, Comparator>::Dequeue() {

	//Acquire lock on queue
	std::unique_lock<std::mutex> lock(SynchronizationQueue<T, Container, Comparator>::m_mutex);

	//Wait for data
	//Lock automatically released in the wait
	while (SynchronizationQueue<T, Container, Comparator>::m_queue.size() == 0) SynchronizationQueue<T, Container, Comparator>::m_cond.wait(lock);

	// Retrieve the data from the queue
	T result = SynchronizationQueue<T, Container, Comparator>::m_queue.top();
	SynchronizationQueue<T, Container, Comparator>::m_queue.pop();

	return result;
}

//Return m_deque size
template<typename T, class Container, class Comparator>
int SynchronizationQueue<T, Container, Comparator>::GetSize() {

	//Acquire lock on deque
	std::unique_lock<std::mutex> lock(SynchronizationQueue<T, Container, Comparator>::m_mutex);

	return SynchronizationQueue<T, Container, Comparator>::m_queue.size();
}




#endif