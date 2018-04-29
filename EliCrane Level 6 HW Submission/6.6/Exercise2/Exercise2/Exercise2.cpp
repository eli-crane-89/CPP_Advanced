#include <iostream>

#include "Point.hpp"
#include "DistanceStrategy.hpp"
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"

int main()
{

	//Make points
	CAD::Point p1(1, 3);
	CAD::Point p2(3, 4);

	//Make strategies
	std::shared_ptr<DistanceStrategy> sp_exact = std::make_shared<ExactDistance>();
	std::shared_ptr<DistanceStrategy> sp_approx = std::make_shared<ApproximateDistance>();

	//Test Strategies
	std::cout << "Exact: " << p1.Distance(p2, sp_exact) << std::endl;
	std::cout << "Exact Distance From Origin: " << p1.Distance() << std::endl;

	p1.SetDistanceStrat("Approx");
	std::cout << "Approx: " << p1.Distance(p2, sp_approx) << std::endl;
	std::cout << "Approx Distance From Origin: " << p1.Distance() << std::endl;

	//The advantages of storing the strategy as a pointer as in Example 1 
	//is that you can give the Point a default strategy on construction
	//so that you don't need to create a pointer to the strategy in the
	//method that is calling it. The advantage of injecting the strategy 
	//into the Distance method is that the method caller will not
	//accidentally invoke the default the strategy since they have
	//to explicitly declare the chosen strategy.


	return 0;
}

