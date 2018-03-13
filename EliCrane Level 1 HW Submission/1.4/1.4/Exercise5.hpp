#ifndef EXERCISE5_HPP
#define EXERCISE5_HPP

#include "Exercise5_AddCode.hpp"

#include <iostream>

void Exercise5() {

	std::cout << std::endl << "Exercise5: " << std::endl;

	//Write an initial area lambda function
	auto areaFuncSquare = [](double dimension) {return dimension*dimension; };

	DoubleFunctionType<double> dft = areaFuncSquare;
	NextGenShape ngShape = NextGenShape(dft, 2.0);

	std::cout << ngShape.multiplyAreaFunc(4) << std::endl;


	//Write a new area lambda function to swap out
	auto areaFuncCubed = [](double dimension) {return dimension*dimension*dimension; };

	dft = areaFuncCubed;
	ngShape.switchAreaFunction(dft);

	std::cout << ngShape.multiplyAreaFunc(6) << std::endl;

}

#endif

