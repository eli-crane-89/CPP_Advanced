#include <iostream>

#include "Point.hpp"

int main()
{

	//Make points
	CAD::Point p1(1,3);
	CAD::Point p2(3, 4);

	//Test Strategies
	std::cout << "Exact: " << p1.Distance(p2) << std::endl;
	std::cout << "Exact Distance From Origin: " << p1.Distance() << std::endl;

	p1.SetDistanceStrat("Approx");
	std::cout << "Approx: " << p1.Distance(p2) << std::endl;
	std::cout << "Approx Distance From Origin: " << p1.Distance() << std::endl;

	//The advantages of the strategy pattern is it allows you to create a 1:N relationship in terms of the possible behavior of calling
	//the Distance function on the Point class. 



    return 0;
}

