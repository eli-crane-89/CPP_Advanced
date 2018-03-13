#include <iostream>
#include <future>
#include <chrono>

//a)
void func1()
{
	std::cout << "The first function has executed.\n";
}

double func2(double a, double b)
{
	std::cout << "The second function is executing...\n";

	if (a > b) {
		return a * b;
	}
	else {
		return a / b;
	}
}

//lamda to check status
auto checkStatus = [&](std::future_status& status) {
	if (status == std::future_status::deferred) {
		std::cout << "deferred\n";
	}
	else if (status == std::future_status::timeout) {
		std::cout << "timeout\n";
	}
	else if (status == std::future_status::ready) {
		std::cout << "ready!\n";
	}
};

int main()
{
	//b)
	std::future<void> f_func1 = std::async(std::launch::deferred, []() {return func1(); }); 
	std::future<double> f_func2 = std::async(std::launch::deferred, [=]() {return func2(3.1, 4.5); });

	//Validity check before getting value
	std::future_status status_func1 = f_func1.wait_for(std::chrono::seconds(1)); //Async/default With 1 second status = ready, 0 seconds = timeout
	checkStatus(status_func1); //returns ready
	std::future_status status_func2 = f_func2.wait_for(std::chrono::seconds(1)); //Async/default With 1 second status = ready, 0 seconds = timeout
	checkStatus(status_func2); //returns ready

	//Get value
	f_func1.get();
	std::cout << "The value from func2 is: " << f_func2.get() << std::endl;

	//Validity check after getting value
	//Wait for causes an error as the thread is no longer active after the get
	//std::future_status status_func1 = f_func1.wait_for(std::chrono::seconds(1)); //With 1 second status = ready, 0 seconds = timeout
	//checkStatus(status_func1);
	//status_func2 = f_func2.wait_for(std::chrono::seconds(0)); 
	//checkStatus(status_func2);

	//c)Get value a second time
	//These lines causes an error as the associated thread is terminated
	//f_func1.get();
	//std::cout << "The value from func2 is: " << f_func2.get() << std::endl;
	
	//d) 

	//Seems to behave the same with async when default is used

	//e)

	//Deferred delays execution until the get and changes the pre-status to "deferred"

    return 0;
}

