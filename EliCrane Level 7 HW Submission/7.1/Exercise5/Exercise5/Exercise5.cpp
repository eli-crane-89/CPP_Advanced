#include <iostream>
#include <cmath>

#include "Point.hpp"

int main()
{
	//Create Points
	CAD::Point p1(1.4,3.5);
	CAD::Point p2(3.5, 4.8);

	//b)
	//Bind lambda to function object and convert to strategy
	auto l_distexact = [](const CAD::Point& p1, const CAD::Point& p2) {
		return std::sqrt(std::pow(p1.Y() - p2.Y(), 2) + std::pow(p1.X() - p2.X(), 2));
	};
	std::function<double(const CAD::Point&, const CAD::Point&)> func_exact = std::bind(l_distexact, std::placeholders::_1, std::placeholders::_2);

	DistanceStrategy exactDist(func_exact);

	//Set strategy and call for stateful pattern
	p1.SetStatelessDistanceStrat(exactDist);
	std::cout << p1.Distance(p2) << std::endl;

	//For stateful construction
	CAD::Point p3(1.5, 3.6, func_exact);
	std::cout << p3.Distance() << std::endl; //Distance from origin

	//c)
	//To increment a counter everytime distance is run, you can simply define a counter variable
	//and increment it within the Distance function for point. 

	std::cout << p3.ReturnCounter() << std::endl;

    return 0;
}

