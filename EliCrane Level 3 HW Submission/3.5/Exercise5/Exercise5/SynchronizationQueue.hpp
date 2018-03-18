#ifndef SYNCHRONIZATIONQUEUE_HPP
#define SYNCHRONIZATIONQUEUE_HPP

#include <queue>
#include <boost\thread.hpp>
#include <thread>
#include <condition_variable>

template<typename T, class Container, class Comparator>
class SynchronizationQueue
{
private:
	std::priority_queue<T, Container, Comparator> m_queue;
	//std::mutex m_mutex;
	std::mutex m_mutex;
	//std::condition_variable m_cond;
	std::condition_variable m_cond;
public:
	void Enqueue(const T& data);
	T Dequeue();
	int GetSize();
};

#ifndef SYNCHRONIZATIONQUEUE_CPP
#include "SynchronizationQueue.cpp"
#endif

#endif // !SYNCHRONIZED_QUEUE