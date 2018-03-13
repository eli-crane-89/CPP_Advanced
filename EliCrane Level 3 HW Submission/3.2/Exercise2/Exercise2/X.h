#ifndef X_H
#define X_H

#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <chrono>

struct X
{
	double val;

	X() : val(0.0) {}
	void operator ()() {
		std::cout << "An X " << val << std::endl;
	}
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

//Generate random number
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 1000);

//a) Create function
void Modify(PointerType& p, double newVal)
{
	// Wait a while, long enough to trigger the race
	std::chrono::milliseconds sleepTime = std::chrono::milliseconds(distribution(generator));
	std::this_thread::sleep_for(sleepTime);

	//Assing new val
	std::cout << "Assigning new val of: " << newVal << " with a sleepTime of: " << sleepTime.count() << std::endl;
	p->val = newVal;
}

#endif