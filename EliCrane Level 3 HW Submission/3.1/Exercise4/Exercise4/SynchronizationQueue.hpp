#ifndef SYNCHRONIZATIONQUEUE_HPP
#define SYNCHRONIZATIONQUEUE_HPP

#include <queue>
#include <thread>
#include <boost\thread.hpp>
#include <condition_variable>

template<typename T>
class SynchronizationQueue
{
private:
	std::queue<T> m_queue;
	boost::mutex m_mutex;
	boost::condition_variable m_cond;
public:
	void Enqueue(const T& data);
	T Dequeue();
};

#ifndef SYNCHRONIZATIONQUEUE_CPP
#include "SynchronizationQueue.cpp"
#endif

#endif // !SYNCHRONIZED_QUEUE