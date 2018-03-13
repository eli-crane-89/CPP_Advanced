#ifndef SYNCHRONIZATIONDEQUE_HPP
#define SYNCHRONIZATIONDEQUE_HPP

#include <queue>
#include <thread>
#include <condition_variable>

template<typename T>
class SynchronizationDeque
{
private:
	//Change to Deque so can pop back and front
	std::deque<T> m_deque;
	std::mutex m_mutex;
	std::condition_variable m_cond;
public:
	void Enqueue(const T& data);
	T Deque(bool);

	//Getter Deque size
	int GetDequeSize();


};

#ifndef SYNCHRONIZATIONDEQUE_CPP
#include "SynchronizationDeQue.cpp"
#endif

#endif // !SYNCHRONIZED_QUEUE