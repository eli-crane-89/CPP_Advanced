#include <iostream>
#include <random>
#include <future>

#include "TmpProcessor.hpp"
#include "StopWatch.hpp"

//Find max prime that comes before number
template<typename T>
T findPrimesUntil(T maxNum) {
	T maxPrime = 0;

	for (int i = 2; i< maxNum; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				bool prime = false;
				break;
			}
		}
		if (prime) {
			maxPrime = i;
		}
	}

	return maxPrime;
}

//Return random number based on max prime
template<typename T>
T generateRandomLargeNumber(T maxPrime) {

	std::default_random_engine e1(3);
	std::uniform_int_distribution<T> uniform_dist(0, 9);

	T largeNumber = 0;

	for (int i = 0; i < maxPrime; i++) {
		largeNumber += uniform_dist(e1);
	}

	return largeNumber;
	
}

//Compute Method Sequentially
template<typename T>
T compute(T maxNum) {

	std::function<T()> func_fPU = std::bind(findPrimesUntil<T>, maxNum);
	std::function<T()> func_genRLN = std::bind(generateRandomLargeNumber<T>, func_fPU());

	T largeNum1 = func_genRLN();
	T largeNum2 = func_genRLN();

	//Find Primes Again For Complexities Sake
	largeNum1 = findPrimesUntil(largeNum1);
	largeNum2 = findPrimesUntil(largeNum2);

	return largeNum1 + largeNum2;
}

//Compute Method In Parallel
template<typename T>
T computeParallel(T maxNum) {

	std::function<T()> func_fPU = std::bind(findPrimesUntil<T>, maxNum);
	std::function<T()> func_genRLN = std::bind(generateRandomLargeNumber<T>, func_fPU());

	//Use lambdas to bind functions
	std::future<T> fut1 = std::async(std::launch::async, std::bind(func_genRLN));
	std::future<T> fut2 = std::async(std::launch::async, std::bind(func_genRLN));

	//Find Primes Again For Complexities Sake
	std::future<T> fut3 = std::async(std::launch::async, std::bind(findPrimesUntil<T>, fut1.get())); //Dependent on fut1
	std::future<T> fut4 = std::async(std::launch::async, std::bind(findPrimesUntil<T>, fut2.get())); //Dependent on fut2

	return fut3.get() + fut4.get();
}






int main()
{

	//a)

	//Define lambdas
	int var = 1;
	auto l_ff = [&]() {
		return var; 
	};

	auto l_cf = [](int i) {
		return i*6;
	};

	auto l_df = [](int i) {
		std::cout << i << std::endl;
	};

	//Create types for constructor
	FactoryFunction<int> ff = l_ff;
	ComputeFunction<int> cf = l_cf;
	DispatchFunction<int> df = l_df;

	//Initialize TmpProcess
	TmpProcessor<int>tp(ff, cf, df);

	//Call Methods
	tp.algorithm();

	//b)
	//Make StopWatch
	StopWatch sw;

	//Factory Method
	auto factoryLambda = []() {
		std::default_random_engine e1(5);
		std::uniform_int_distribution<long> uniform_dist(200000, 1500000);

		return uniform_dist(e1);
	};
	FactoryFunction<long> ff2 = factoryLambda;

	//Compute Method
	ComputeFunction<long> cf2 = compute<long>;

	//Dispatch Lambda
	auto dispatchLambda = [](const long randLargeNum) {
		std::cout << "The final generated number is: " << randLargeNum << ".\n";
	};
	DispatchFunction<long> df2 = dispatchLambda;

	//Create Sequential Processor
	TmpProcessor<long> tp_sequential(ff2, cf2, df2);

	//Call Algorithm
	sw.StartStopWatch();
	tp_sequential.algorithm();
	sw.StopStopWatch();

	//Read time
	std::cout << "It took " << sw.GetTime() << " seconds to complete the sequential algorithm.\n\n";

	sw.Reset();

	//Parallel Compute Method
	ComputeFunction<long> cf3 = computeParallel<long>;

	//Create Parallel Processor
	TmpProcessor<long> tp_parallel(ff2, cf3, df2);

	//Call Algorithm
	sw.StartStopWatch();
	tp_parallel.algorithm();
	sw.StopStopWatch();

	//Read time
	std::cout << "It took " << sw.GetTime() << " seconds to complete the parallel algorithm.\n\n";

	//The parallel method is clearly faster. This pattern is useful since it allows each function
	//In the algorithm to be swapped out.

	//Data Dependency Graph is in Resource Files


    return 0;
}

