#ifndef BRIDGEFUNCTION_HPP
#define BRIDGEFUNCTION_HPP

#include <iostream>

template<typename T>
void PrintObject(const T& t, std::true_type) {
	std::cout << "Pointer argument is: " << *t << std::endl; //Prints derefenced value
};

template<typename T>
void PrintObject(const T& t, std::false_type) {
	std::cout << "Non Pointer Object argument is: " << t << std::endl;
}

template <typename T>
void PrintObjectBridge(const T& val) {
	PrintObject(val, std::is_pointer<T>()); //Splits based on whether T is a pointer or not
}

#endif