#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <iostream>
#include <array>

#include "Exercise2_AddCode.hpp"

void Exercise2() {
	std::cout << std::endl << "Exercise2: " << std::endl;

	//a) Call variadic rotate
	Valve valve = Valve();
	Circle circle = Circle();
	Line line = Line();

	double factor = 2.0;

	rotate(factor, valve, circle, line);
	
	//b) for loop rotate 
	std::array<Shape*, 5> shapeList{ &circle, &line, &circle, &circle, &line };
	double factor2 = 20.0;
	for (auto& elem : shapeList)
	{
		elem->rotate(factor2);
	}

	//We cannot include valves because the specific array is for Shape pointers, which must be objects derived from Shape
	//Valve is not derived from shape and thus cannot be included in the array. The variadic function can include Valve 
	//because it takes n arguments, and all that matters is that each argument can have rotate() called on it. 
}


#endif
