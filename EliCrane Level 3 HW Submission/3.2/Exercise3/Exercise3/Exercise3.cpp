
#include <iostream>
#include <thread>
#include <string>

#include "ActiveObject.hpp"

void ThreadFunction(std::string& message) {
	std::cout << message << std::endl;
}

//c) implement thread functions
//lambda
auto lambdaThread = [&](std::string message) {
	std::cout << message << std::endl;
};

//Function Object
class ThreadFunctor {

public:
	ThreadFunctor() {};

	void operator () (std::string& message) { 
		std::cout << message << std::endl;
	};

};

int main()
{
	//b) Create active object with thread with no associated function
	std::thread t;
	try {
		ActiveObject ao = ActiveObject(&t);
	}
	catch (const std::system_error& e) {
		std::cout << e.what() << std::endl;
	}

	
	//d) test code
	std::thread t_lambda(lambdaThread, "From lambda");
	ActiveObject ao1 = ActiveObject(&t_lambda);

	ThreadFunctor tf;
	std::string tf_message = "From functor";
	std::thread t_functor(tf, tf_message);
	ActiveObject ao2 = ActiveObject(&t_functor);


    return 0;
}

