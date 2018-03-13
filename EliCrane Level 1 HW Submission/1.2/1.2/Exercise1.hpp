#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include "C.hpp"

#include <iostream>

inline void Exercise1() {

	std::cout << "Exercise1: " << std::endl;

	//a) Default and Delete
	C<int> c; //= C<int>();

	//An array of size 0 is still generated
	cout << c.VectorT().size() << endl;

	//Cannot Copy Construct due to inaccessible error
	//C<int> cCopy = c;

	//Cannot use the Assignment operator due to inaccessible error
	//cCopy = c;

	//The code only compiled with delete if I remove the body of the Copy Constructor and the Assignment Operator from C.cpp

	//b) Explicit
	//Explict Added to Copy Constructor and Default Constructor

	//c) ConstExpr
	//ConstExpr added to copy constructor, default constructor and setter for vector

	//d) NoExcept
	//NoExcept added to everything
}

#endif