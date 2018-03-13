#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

#include <iostream>
#include <functional>

#include "Exercise3_AddCode.hpp"

using namespace placeholders;

void Exercise3() {

	std::cout << std::endl << "Exercise3: " << std::endl;

	C c = C(3);

	FunctionType<double> f;

	f = c.Square;
	std::cout << f(3) << std::endl;

	auto f2 = std::bind(&C::translate, &c,_1);
	std::cout << f2(2) << std::endl;

	auto f3 = std::bind(&C::translate2, &c, _1,7);
	std::cout << f3(7) << std::endl;


}

#endif
