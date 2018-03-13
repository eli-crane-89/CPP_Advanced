#include <future>
#include <iostream>
#include <chrono>
#include <thread>



//For thread
void threadFunction(std::future<double>& fut) {
	std::cout << "The returned val is: " << fut.get() << std::endl;
}

int main()
{

	//a)
	std::promise<void> defaultPromise; //default
	std::promise<void> emptyStatePromise; //default also has an empty shared state
	std::promise<void>(std::move(emptyStatePromise)); //move constructor

	//b)
	std::promise<double> doublePromise; //make promise with empty state
	std::future<double> fut = doublePromise.get_future(); //associate promise with future

	//c) Make thread with fut
	std::thread t(threadFunction, std::ref(fut));


	//d)
	//Set value
	doublePromise.set_value(1.3);

	//Join
	t.join(); //without this line the program crashes


    return 0;
}

