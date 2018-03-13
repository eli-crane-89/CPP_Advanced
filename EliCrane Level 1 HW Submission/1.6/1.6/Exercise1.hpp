#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include <iostream>

#include "Exercise1_AddCode.hpp"

void Exercise1() {

	std::cout << "Exercise1: " << std::endl;

	//b) Derive instances of Derived using shared_ptr<Base> 
	BaseSP d1(new Derived());
	BaseSP d2(new Derived());

	//Destructors called
}

#endif // ! EXERCISE1_HPP

