#include <random>
#include <thread>
#include <chrono>
#include <future>
#include <iostream>
#include <queue>

// Thread function
double compute(double x, double y)
{
	// Wait a while
	std::default_random_engine dre(42);
	std::uniform_int_distribution<int> delay(0, 1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

	return std::cos(x) * std::exp(y);
}


int main()
{

	//a)
	double x = 0.0; double y = 2.71;
	// A. 'Direct' tasks
	std::future<double> fut = std::async(compute, x, y);

	// Get the shared data
	double result = fut.get();
	std::cout << "Result: " << result << '\n';

	//b)

	//Create a task and associated future
	std::packaged_task<double(double, double)> task1(compute);
	auto fut1 = task1.get_future();

	//Start task
	task1(1.5, 1.6);

	//wait for task completion and get result
	std::cout << "Result from task: " << fut1.get() << std::endl;

	//c)

	//create queue
	std::queue<std::packaged_task<double (double, double)>> q_pt;

	//create three new tasks
	std::packaged_task<double(double, double)> task2(compute);
	std::packaged_task<double(double, double)> task3(compute);
	std::packaged_task<double(double, double)> task4(compute);

	//add packaged tasks to the queue
	q_pt.push(std::packaged_task<double(double, double)>(std::move(task2)));
	q_pt.push(std::packaged_task<double(double, double)>(std::move(task3)));
	q_pt.push(std::packaged_task<double(double, double)>(std::move(task4)));

	//loop through queue

	const std::size_t s = q_pt.size();
	for (int i = 0; i < s; i++) {
		q_pt.front()(3.0/i, 2.0/i);
		auto result = q_pt.front().get_future(); //Get future for the task
		std::cout << "The result from packaged task " << i << ": " << result.get() << std::endl; //get task result
		q_pt.pop(); //Pop task from front
	}

    return 0;
}

