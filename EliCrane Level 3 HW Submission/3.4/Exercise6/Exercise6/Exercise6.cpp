#include <iostream>
#include <future>
#include <thread>

#include "Functions.hpp"

void graphSingleThread(double startVal) {
	auto val_f1 = funcs::f1(startVal);
	auto val_f2 = funcs::f2(startVal);
	auto val_f3 = funcs::f3(val_f2);
	auto val_f4 = funcs::f4(val_f3, val_f1);

	std::cout << "The final value from single thread: " << val_f4 << std::endl;

}

void graphAsync(double startVal) {
	auto fut1 = std::async(std::launch::async, funcs::f1,startVal);
	auto fut2 = std::async(std::launch::async, funcs::f2,startVal);
	auto fut3 = std::async(std::launch::async, funcs::f3,fut2.get());
	auto fut4 = std::async(std::launch::async, funcs::f4, fut3.get(), fut1.get());

	std::cout << "The final value from async: " << fut4.get() << std::endl;

}

void graphPromise(double startVal) {

	//f1
	std::promise<double> prom1; //Make promise
	std::future<double> prom1_fut = prom1.get_future(); //Create promise future
	prom1.set_value(startVal); //Set future value
	auto prom1_fut_ret = std::async(std::launch::async, funcs::f1, prom1_fut.get()); //Use async to return value
	
	//Repeat for f2
	std::promise<double> prom2;
	std::future<double>  prom2_fut = prom2.get_future();
	prom2.set_value(startVal);
	auto prom2_fut_ret = std::async(funcs::f2, prom2_fut.get());

	//Repeat for f3
	std::promise<double> prom3;
	auto prom3_fut = prom3.get_future();
	prom3.set_value(prom2_fut_ret.get());
	auto prom3_fut_ret = std::async(funcs::f3, prom3_fut.get()); //use return from f2
	
	//Need to set two values so need two promises
	std::promise<double> prom4;
	auto prom4_fut = prom4.get_future();
	prom4.set_value(prom3_fut_ret.get());
	std::promise<double> prom5;
	auto prom5_fut = prom5.get_future();
	prom5.set_value(prom1_fut_ret.get());
	auto prom4_fut_ret = std::async(funcs::f4, prom4_fut.get(), prom5_fut.get());

	std::cout << "The final value from promise: " << prom4_fut_ret.get() << std::endl;

}

void graphTask(int startValue) {

	//Create tasks
	std::packaged_task<double(double)> task1(funcs::f1);
	auto task1_fut = task1.get_future();
	std::packaged_task<double(double)> task2(funcs::f2);
	auto task2_fut = task2.get_future(); 
	std::packaged_task<double(double)> task3(funcs::f3);
	auto task3_fut = task3.get_future(); 
	std::packaged_task<double(double,double)> task4(funcs::f4);
	auto task4_fut = task4.get_future();

	//call via threads
	std::thread t_task1(std::move(task1), (double)startValue);
	std::thread t_task2(std::move(task2), (double)startValue);
	std::thread t_task3(std::move(task3), task2_fut.get());
	std::thread t_task4(std::move(task4), task3_fut.get(), task1_fut.get());

	//Join threads
	t_task1.join();
	t_task2.join();
	t_task3.join();
	t_task4.join();

	std::cout << "The final value from tasks: " << task4_fut.get() << std::endl;

}

int main()
{
	const int startVal = 50000;

	//a) Run in a single thread
	auto beginSum = std::chrono::steady_clock::now();
	graphSingleThread(startVal);
	auto endSum = std::chrono::steady_clock::now();
	std::cout << "Time it took to run the single thread graph: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;
	

	//b) Run with async and futures
	beginSum = std::chrono::steady_clock::now();
	graphAsync(startVal);
	endSum = std::chrono::steady_clock::now();
	std::cout << "Time it took to run the async graph: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//The code runs 1/3 faster with aynschronious programming
	//I believe load balancing has been mostly achieved since f1 takes about as much time to run as f3 (f2 and f4 are instantaneous)

	//c) Run with promises
	beginSum = std::chrono::steady_clock::now();
	graphPromise(startVal);
	endSum = std::chrono::steady_clock::now();
	std::cout << "Time it took to run the promise graph: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//The promises flow runs at about the same speed, maybe a little slower
	
	//d) using packaged tasks
	beginSum = std::chrono::steady_clock::now();
	graphTask(startVal);
	endSum = std::chrono::steady_clock::now();
	std::cout << "Time it took to run the task graph: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//The tasks speed is nearly as slow as the single thread

    return 0;
}

