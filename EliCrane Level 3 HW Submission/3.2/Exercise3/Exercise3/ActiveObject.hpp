#ifndef ACTIVEOBJECT_HPP
#define ACTIVEOBJECT_HPP

#include <thread>

class ActiveObject {

private:
	std::thread* _p_thread;



public:

	//constructor
	ActiveObject(std::thread * p_thread) {
		if (p_thread->joinable()) {
			_p_thread = p_thread;
		}
		else {
			throw std::system_error(EINVAL, std::generic_category(), "Thread function cannot be joined");
		}
	}

	//Destructor
	~ActiveObject() {

		//Check for joinability and join
		if (_p_thread->joinable()) {
			_p_thread->join();
		}
	}
};

#endif