#ifndef SYNCHRONIZATIONDEQUE_CPP
#define SYNCHRONIZATIONDEQUE_CPP

#include "SynchronizationDeQue.hpp"

#include <thread>

template<typename T>
void SynchronizationDeque<T>::Enqueue(const T& data) {
	
	//Put lock on queue
	std::unique_lock<std::mutex> lock(SynchronizationDeque<T>::m_mutex);

	//Add the data to the back of deque
	m_deque.push_back(data);

	//Notify others that data is ready
	m_cond.notify_one();
}

//Modified to 
template<typename T>
T SynchronizationDeque<T>::Deque(bool popFront) {

	//Acquire lock on deque
	std::unique_lock<std::mutex> lock(SynchronizationDeque<T>::m_mutex);

	//Wait for data
	//Lock automatically released in the wait
	while (SynchronizationDeque<T>::m_deque.size() == 0) SynchronizationDeque<T>::m_cond.wait(lock);

	// Retrieve the data from the deque

	//Define return
	T result;

	//If popFront is true remove from front
	if (popFront) {
		result = SynchronizationDeque<T>::m_deque.front();
		SynchronizationDeque<T>::m_deque.pop_front();
	}
	else {
		result = SynchronizationDeque<T>::m_deque.back();
		SynchronizationDeque<T>::m_deque.pop_back();
	}
	

	return result;
}

//Return m_deque size
template<typename T>
int SynchronizationDeque<T>::GetDequeSize() {

	//Acquire lock on deque
	std::unique_lock<std::mutex> lock(SynchronizationDeque<T>::m_mutex);

	int dqSize = SynchronizationDeque<T>::m_deque.size();
	return dqSize;
}





#endif