#include <future>
#include <iostream>
#include <chrono>

double func1(double a, double b) {
	std::cout << "The function is executing...\n";

	return a * b;
}

//loop breaker
bool bl_breaker = false;

void infLoop() {
	while (!bl_breaker);

	std::cout << "The loop has been broken.\n";
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
	std::future<double> fut = std::async(func1, 3.4, 1.6);
	std::cout << "fut has a shared state: " << fut.valid() << std::endl;

	//a)
	std::shared_future<double> sfut1; //default state
	std::shared_future<double> sfut2(fut.share()); //transfer shared state from a normal future
	std::shared_future<double> sfut3 = sfut2; //shared future that shares state
	std::shared_future<double> sfut4(std::move(sfut3)); //transfer shared state from a shared future


    //b)
	//std::future_status status_sfut1 = sfut1.wait_for(std::chrono::seconds(1)); //cannot call since it has no shared future
	std::future_status status_sfut2 = sfut2.wait_for(std::chrono::seconds(1)); 
	checkStatus(status_sfut2);
	//std::future_status status_sfut3 = sfut3.wait_for(std::chrono::seconds(1)); //cannot call since it has no shared future
	std::future_status status_sfut4 = sfut4.wait_for(std::chrono::seconds(1));
	checkStatus(status_sfut4);

	std::cout << "sfut2: " << sfut2.get() << std::endl;
	std::cout << "sfut4: " << sfut4.get() << std::endl;

	//Yes, shared futures appear to have the same member functions as regular futures

	//c)

	//shared_future can return its value multiple times, unlike a normal future
	std::cout << "calling sfut2 2x: " << sfut2.get() << std::endl;

	//d)
	std::future<void> f_loop = std::async(infLoop);
	std::shared_future<void> sfut_loop = f_loop.share();

	//Set time point for two seconds
	std::chrono::system_clock::time_point two_seconds = std::chrono::system_clock::now() + std::chrono::seconds(2);
	sfut_loop.wait_until(two_seconds);

	std::cout << "code continued to execute.\n";

	bl_breaker = true;

    return 0;
}

