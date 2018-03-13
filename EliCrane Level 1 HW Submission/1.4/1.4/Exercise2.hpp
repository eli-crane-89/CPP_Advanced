#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <iostream>

using namespace std::placeholders;

double freeFunction3(double x, double y, double z)
{
	return x + y + z;
}

void Exercise2() {

	std::cout << std::endl << "Exercise2: " << std::endl;
	
	//arity 3
	auto ar3 = std::bind(freeFunction3, _1, _3, _2);
	std::cout << ar3(6, 8, 9) << std::endl;

	//arity 2
	auto ar2 = std::bind(freeFunction3, _1, 2, _2);
	std::cout << ar2(6,8) << std::endl;

	//arity 1
	auto ar1 = std::bind(freeFunction3, _1, 2, 7);
	std::cout << ar1(6) << std::endl;
	
	//arity 0
	auto ar0 = std::bind(freeFunction3, 1, 2, 7);
	std::cout << ar0() << std::endl;
}
#endif