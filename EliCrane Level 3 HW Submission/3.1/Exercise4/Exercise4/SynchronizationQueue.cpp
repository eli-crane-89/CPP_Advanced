#ifndef SYNCHRONIZATIONQUEUE_CPP
#define SYNCHRONIZATIONQUEUE_CPP

#include "SynchronizationQueue.hpp"

#include <boost\thread.hpp>

template<typename T>
void SynchronizationQueue<T>::Enqueue(const T& data) {
	
	//Put lock on queue
	boost::unique_lock<boost::mutex> lock(SynchronizationQueue<T>::m_mutex);

	//Add the data to queue
	m_queue.push(data);

	//Notify others that data is ready
	m_cond.notify_one();
}

template<typename T>
T SynchronizationQueue<T>::Dequeue() {

	//Acquire lock on queue
	boost::unique_lock<boost::mutex> lock(SynchronizationQueue<T>::m_mutex);

	//Wait for data
	//Lock automatically released in the wait
	while (SynchronizationQueue<T>::m_queue.size() == 0) SynchronizationQueue<T>::m_cond.wait(lock);

	// Retrieve the data from the queue
	T result = SynchronizationQueue<T>::m_queue.front();
	SynchronizationQueue<T>::m_queue.pop();

	return result;
}




#endif