#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include <iostream>

//b) Tail function
template<typename T>
void printer(T p) {
	std::cout << p << std::endl;
}

//a) Variadic Printer in action
template<typename T, typename... Args>
void printer(T first, Args... args) {
	std::cout << first << std::endl; 

	printer(args...);
}



void Exercise1() {

	std::cout << "Exercise1: " << std::endl;

	//c) Test Function
	printer("Hello", 2, 3, 4, 7);
}




#endif