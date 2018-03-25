#include <vector>
#include <iostream>
#include <algorithm>

#include "StopWatch.hpp"

//Forward declate
void testEfficiency(std::vector<int>&);

//Predicate

bool predLTE(const int t1, const int t2) {
	return t1 <= t2;
}

bool predGTE(const int t1, const int t2) {
	return t1 >= t2;
}

int main()
{
	//a)
	std::vector<int> v1;
	for (int i = 5; i < 15; i++) {
		v1.push_back(i);
	}
	v1.push_back(15);
	v1.push_back(4);

	auto isu = std::is_sorted_until(v1.begin(), v1.end());
	int sortUntil = std::distance(v1.begin(), isu);
	std::cout << "The vector is sorted until: " << sortUntil << std::endl; //sorted until second 15

	//Less than or equal
	isu = std::is_sorted_until(v1.begin(), v1.end(), predLTE);
	sortUntil = std::distance(v1.begin(), isu);
	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v1.begin(), v1.end()) << std::endl;

	std::cout << "The vector is sorted until: " << sortUntil << std::endl; //sorted until second 15

	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v1.begin(), v1.end(), predLTE) << std::endl;

	//Greater than or equal
	isu = std::is_sorted_until(v1.begin(), v1.end(), predGTE);
	sortUntil = std::distance(v1.begin(), isu);
	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v1.begin(), v1.end()) << std::endl;

	std::cout << "The vector is sorted until: " << sortUntil << std::endl; //sorted until 1st term

	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v1.begin(), v1.end(), predGTE) << std::endl;


	//b) Compare Efficiency

	//Make large vectors
	size_t sz = 1000000;

	std::vector<int> v2; //sorted
	std::vector<int> v3; //sorted partially
	std::vector<int> v4; //Reverse sorted

	for (int i = 0; i < sz; i++) {
		v2.push_back(i);
	}

	for (int i = 0; i < sz; i++) {
		v3.push_back(i);
	}
	v3[500000] = 127;

	for (int i = sz; i > 0; i--) {
		v4.push_back(i);
	}

	//Test v2
	std::cout << "Testing v2\n\n";
	testEfficiency(v2);

	//Test v3
	std::cout << "Testing v3\n\n";
	testEfficiency(v3);

	//Test v4
	std::cout << "Testing v2\n\n";
	testEfficiency(v4);

	//Both is sorted and is sorted until seem to run at similar speeds.
	//Adding algorithms did not change the speed much either
	//The only thing that mattered is how many terms each algorithm needed to go through before
	//reaching its terminating condition

    return 0;
}

void testEfficiency(std::vector<int>& v) {
	//Create stopwatch
	StopWatch sw;

	

	//Start stop watch
	sw.StartStopWatch();

	//is sorted until
	auto isu = std::is_sorted_until(v.begin(), v.end());
	int sortUntil = std::distance(v.begin(), isu);

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "The vector is sorted until: " << sortUntil << std::endl;
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted_until to run.\n";

	//Reset and Start
	sw.Reset();
	sw.StartStopWatch();

	//Is Sorted
	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v.begin(), v.end()) << std::endl;

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted to run.\n";

	//Reset and Start
	sw.Reset();
	sw.StartStopWatch();

	//Is sorted until predLTE
	isu = std::is_sorted_until(v.begin(), v.end(), predLTE);
	sortUntil = std::distance(v.begin(), isu);

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "The vector is sorted until: " << sortUntil << std::endl;
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted_until with predLTE to run.\n";


	//Reset and Start
	sw.Reset();
	sw.StartStopWatch();

	//is sorted predLTE
	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v.begin(), v.end(), predLTE) << std::endl;

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted with predLTE to run.\n";

	//is sorted until predLTE
	isu = std::is_sorted_until(v.begin(), v.end(), predGTE);
	sortUntil = std::distance(v.begin(), isu);

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "The vector is sorted until: " << sortUntil << std::endl;
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted_until with predGTE to run.\n";

	//Reset and Start
	sw.Reset();
	sw.StartStopWatch();

	std::cout << "Is the vector sorted: " << std::boolalpha << std::is_sorted(v.begin(), v.end(), predGTE) << std::endl;

	//Stop stop watch
	sw.StopStopWatch();
	std::cout << "It took " << sw.GetTime() << " seconds for is_sorted with predGTE to run.\n";

	
}
