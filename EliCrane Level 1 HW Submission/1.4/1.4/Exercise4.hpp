#ifndef EXERCISE4_HPP
#define EXERCISE4_HPP

#include "Exercise4_AddCode.hpp"

void Exercise4() {

	std::cout << std::endl << "Exercise4: " << std::endl;

	//Assign to variable so can pass by reference
	VoidFunctionType vft1 = ShapeRotate;
	Shape shape = Shape(vft1);

	VoidFunctionType vft2 = CircleRotate;
	Circle circle = Circle(vft2);
	
	shape.rotate(3); //Prints: Rotated Shape by a factor of 3
	circle.rotate(4); //Prints: Circle rotate called. Rotates Circle by a factor of 3

}

#endif

