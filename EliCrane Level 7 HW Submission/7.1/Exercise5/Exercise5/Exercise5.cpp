#include <iostream>
#include <cmath>
#include <future>
#include <vector>

#include "Point.hpp"
#include "StopWatch.hpp"

StopWatch sw;

//Taxman approximate distance function
double ApproxDistance(const CAD::Point& p1, const CAD::Point& p2) {
	return std::abs(p1.Y() - p2.Y()) + std::abs(p1.X() - p2.X());
}

//Exact distance lambda
auto l_distexact = [](const CAD::Point& p1, const CAD::Point& p2) {
	return std::sqrt(std::pow(p1.Y() - p2.Y(), 2) + std::pow(p1.X() - p2.X(), 2));
};

//For subsetting vectors
auto l_subset = [](const std::vector<CAD::Point>& vPoint, int ixStart, int ixEnd) {
	std::vector<CAD::Point> vReturn;
	
	//Create iterators
	auto iterStart = vPoint.begin();
	std::advance(iterStart, ixStart);
	auto iterEnd = vPoint.begin();
	std::advance(iterEnd, ixEnd+1); //Increment by one

	for (auto iter = iterStart; iter != iterEnd; ++iter) {
		vReturn.push_back(*iter);
	}

	return vReturn;
};

//Calculate distance for vector and strategy
double CalculateDistance(const std::vector<CAD::Point>& vPoint, const DistanceStrategy& distStrat) {
	double sum = 0;
	CAD::Point lastPoint, currentPoint;

	for (int i = 0; i < vPoint.size(); ++i) {
		currentPoint = vPoint[i]; 
		if (i > 0) { //Don't calculate for first point
			sum += distStrat.Distance(lastPoint, currentPoint);
		}
		lastPoint = currentPoint;
	}

	return sum;

}

//Distance between ordered points function
double DistanceBetweenOrderedPoints(const std::vector<CAD::Point>& vPoint, const DistanceStrategy& distStrat) {
	sw.Reset();
	
	//first split array into fourths
	int size = vPoint.size();

	int len1, len2, len3, len4;

	len1 = .25 * size;
	len2 = .5 * size;
	len3 = .75 * size;

	sw.StartStopWatch();
	std::vector<CAD::Point> v1 = l_subset(vPoint, 0, len1);
	std::vector<CAD::Point> v2 = l_subset(vPoint, len1, len2); //Start with last point to get distance between last point and "first" point in new set
	std::vector<CAD::Point> v3 = l_subset(vPoint, len2, len3);
	std::vector<CAD::Point> v4 = l_subset(vPoint, len3, size-1);
	sw.StopStopWatch();

	std::cout << "It took " << sw.GetTime() << " to split the vectors.\n\n";
	sw.Reset();

	//Create Function Objects
	sw.StartStopWatch();
	std::function<double()> fun1 = std::bind(CalculateDistance, v1, distStrat);
	std::function<double()> fun2 = std::bind(CalculateDistance, v2, distStrat);
	std::function<double()> fun3 = std::bind(CalculateDistance, v3, distStrat); 
	std::function<double()> fun4 = std::bind(CalculateDistance, v4, distStrat);
	sw.StopStopWatch();

	std::cout << "It took " << sw.GetTime() << " to bind the vectors.\n\n";
	sw.Reset();

	//Create Futures
	sw.StartStopWatch();
	std::future<double> fut1 = std::async(std::launch::async, fun1);
	std::future<double> fut2 = std::async(std::launch::async, fun2);
	std::future<double> fut3 = std::async(std::launch::async, fun3);
	std::future<double> fut4 = std::async(std::launch::async, fun4);

	return fut1.get() + fut2.get() + fut3.get() + fut4.get();

}

int main()
{
	//Create Points
	CAD::Point p1(1.4,3.5);
	CAD::Point p2(3.5, 4.8);

	//b)
	//Bind lambda to function object and convert to strategy
	std::function<double(const CAD::Point&, const CAD::Point&)> func_exact = std::bind(l_distexact, std::placeholders::_1, std::placeholders::_2);
	std::function<double(const CAD::Point&, const CAD::Point&)> func_approx = std::bind(ApproxDistance, std::placeholders::_1, std::placeholders::_2);
	
	//Create Strategy Interfaces
	DistanceStrategy exactDist(func_exact);
	DistanceStrategy approxDist(func_approx);

	//Set strategy and call for stateless pattern
	p1.SetStatelessDistanceStrat(exactDist);
	std::cout << p1.Distance(p2) << std::endl;
	p1.SetStatelessDistanceStrat(approxDist);
	std::cout << p1.Distance(p2) << std::endl;

	//For stateful construction
	CAD::Point p3(1.5, 3.6, func_exact);
	std::cout << p3.Distance() << std::endl; //Distance from origin
	CAD::Point p4(1.5, 3.6, func_approx);
	std::cout << p4.Distance() << std::endl; 

	//c)
	//To increment a counter everytime distance is run, you can simply define a counter variable
	//and increment it within the Distance function for point. 

	std::cout << p1.ReturnCounter() << std::endl;

	//d)
	//Create large vector
	std::vector<CAD::Point> vPoint;
	for (int i = 0; i < 1000000; ++i) {
		vPoint.push_back(CAD::Point(i,i));
	}

	//Single Thread
	sw.StartStopWatch();
	std::cout << "Distance single thread: " << CalculateDistance(vPoint, exactDist) << std::endl;
	sw.StopStopWatch();
	std::cout << "It took: " << sw.GetTime() << " seconds to run the distance formula in a single thread.\n\n";
	sw.Reset();

	//Parallel Threads
	sw.StartStopWatch();
	std::cout << "Distance multi thread: " << DistanceBetweenOrderedPoints(vPoint, exactDist) << std::endl;
	sw.StopStopWatch();
	std::cout << "It took: " << sw.GetTime() << " seconds to run the distance formula in 4 parallel threads.\n\n";

	//So by splitting the time up between the different parts of the parallel process, you can see that the 4 parallel distance
	//functions run more quickly than the single threaded distance function, but since it takes so much time to split the vector
	//it is still faster to run using the single thread. If the algorithm was more complex, this most likely wouldn't be the case.

    return 0;
}

