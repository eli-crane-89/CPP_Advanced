#include <iostream>
#include <vector>
#include <algorithm>

#include "BindFunctions.hpp"


int main()
{
	double yval = 10.0;

	std::function<double(const double& x, const double& y)> fxy = [=](double x, double y) { return x + y; };

	ScalarFunction fx = bind2nd<double>(fxy, yval);
	std::cout << fx(3.0) << std::endl;
	
	// Test new bind code on STL algorithms
	std::vector<double> vec(10, 2.0);
	std::transform(vec.begin(), vec.end(), vec.begin(), fx);
	for (auto i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ",";
	}


	//My second function
	std::function<double(const double& x, const double& y)> fxy2 = [=](double x, double y) { return x * y; };

	ScalarFunction fx2 = bind1st<double>(fxy2, yval);

	// Test new bind code on STL algorithms
	std::vector<double> vec2(10, 2.0);
	std::transform(vec2.begin(), vec2.end(), vec2.begin(), fx2);
	for (auto i = 0; i < vec2.size(); ++i)
	{
		std::cout << vec2[i] << ",";
	}


    return 0;
}

