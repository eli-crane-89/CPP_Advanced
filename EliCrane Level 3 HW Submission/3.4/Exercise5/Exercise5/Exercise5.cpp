#include <vector>
#include <random>
#include <numeric>
#include <iostream>
#include <future>
#include <chrono>
#include <omp.h>




//Parallel sumThread
template<typename T>
long sumThread(T iterBegin, T iterEnd) {
	int sz = iterEnd - iterBegin;

	if (sz < 1000) { //if size less than 1000, return accumulate
		return  std::accumulate(iterBegin, iterEnd, 0);
	}
	else
	{
		T iterMid = iterBegin + sz / 2; //split list in two
		std::future<long> fut = std::async(std::launch::async, sumThread<T>, iterMid, iterEnd); //create future with recursive call for second half of list
		long sum = sumThread(iterBegin, iterMid); //sum first half of iterator
		return sum + fut.get(); //add sum + future sumThread value
	}

}

//With threads
std::mutex mx;
template<typename T>
void sumThreadsThread(T iterBegin, T iterEnd, long* initVal) {
	int sz = iterEnd - iterBegin;

	if (sz < 1000) { //if size less than 1000, return accumulate
		std::unique_lock<std::mutex> uqLock(mx); //lock initVal
		*initVal += std::accumulate(iterBegin, iterEnd, 0); //add to pointer
	}
	else
	{
		T iterMid = iterBegin + sz / 2; //split list in two
		std::thread tSum(sumThreadsThread<T>, iterMid, iterEnd, initVal); //create thread that sums right half
		sumThreadsThread(iterBegin, iterMid, initVal); //sum first half of iterator

		tSum.join(); //Join thread
		
	}

}

template<typename T>
long long productThread(T iterBegin, T iterEnd) {
	int sz = iterEnd - iterBegin;

	if (sz < 1000) { //if size less than 1000, return accumulate via multiplication
		long long product = std::accumulate(iterBegin, iterEnd, 1, std::multiplies<long>());
		return product;
	}
	else
	{
		T iterMid = iterBegin + sz / 2; //split list in two
		std::future<long long> fut = std::async(std::launch::async, productThread<T>, iterMid, iterEnd); //create future with recursive call for second half of list
		long long product = productThread(iterBegin, iterMid); //get product of first half of iterator
		return product + fut.get(); //add product + future productThread value
	}

}

int main()
{
	
	//Populate vector
	std::vector<long> v;
	for (long i = 1; i <= (2000); i++) {
		v.push_back(i);
	}

	//a)
	//Sum with accumulate
	auto beginSum = std::chrono::steady_clock::now();
	auto sum = std::accumulate(v.begin(), v.end(), 0);
	auto endSum = std::chrono::steady_clock::now();
	std::cout << "The sum is equal to: " << sum << std::endl;
	std::cout << "Time it took to sum: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//b) Sum with parallel process
	beginSum = std::chrono::steady_clock::now();
	auto sumPar = sumThread(v.begin(), v.end());
	endSum = std::chrono::steady_clock::now();
	std::cout << "The parallel sum is equal to: " << sumPar << std::endl;
	std::cout << "Time it took to sum: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//This is actually slower than std::accumulate. I know that is not supposed to be true but I am not sure what I am doing incorrectly

	//c)
	//omp
	long sumOmp = 0;

	beginSum = std::chrono::steady_clock::now();
	omp_set_num_threads(2);
	#pragma omp parallel for reduction (+:sumOmp)
	for (long i = 0; i < v.size(); ++i) {
		sumOmp += v[i];
	}
	endSum = std::chrono::steady_clock::now();
	std::cout << "The omp sum is equal to: " << sumOmp << std::endl;
	std::cout << "Time it took to sum: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//This is still slower than std::accumulate, but faster than the parallel thread

	//e)

	long sumT = 0; //make pointer
	beginSum = std::chrono::steady_clock::now();
	sumThreadsThread(v.begin(), v.end(), &sumT);
	endSum = std::chrono::steady_clock::now();
	
	std::cout << "The thread sum is equal to: " << sumT << std::endl;
	std::cout << "Time it took to sum: " << std::chrono::duration_cast<std::chrono::microseconds>(endSum - beginSum).count() << std::endl;

	//The thread sum is faster than all, but accumulate
	
	//f)

	//make new smaller vector
	//cannot make vector too big even to demonstrate since factorials adds up quickly
	std::vector<long long> v2;
	for (int i = 1; i < 20; i++) {
		v2.push_back(i);
	}

	long long product = productThread(v2.begin(), v2.end());
	std::cout << "The normal product is: " << std::accumulate(v2.begin(), v2.end(), 1, std::multiplies<long long>()) << std::endl;
	std::cout << "The parallel product is equal to: " << product << std::endl;

    return 0;
}

