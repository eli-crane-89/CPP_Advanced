#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include "Exercise1_AddCode.hpp"

void Exercise1() {

	std::cout << "Exercise1: " << std::endl;

	//a)
	FunctionType<double> f;

	//b)
	//Free Function
	f = returnR;
	print(f, 3.4); //3.4
	
	//Function Object
	f = Multiply<double>(3.0);
	print(f, 6.1); //18.3

	//Lambda Function
	f = [&] (double a) {return a*2; };
	print(f, 3.0); //6.0

	
}
#endif