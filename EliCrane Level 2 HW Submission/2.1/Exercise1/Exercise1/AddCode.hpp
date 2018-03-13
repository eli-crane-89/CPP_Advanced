#ifndef ADDCODE_HPP
#define ADDCODE_HPP

#include <iostream>

template <typename T>
void determineType(const T &t) {

	if (std::is_pointer<T>::value) {
		std::cout << "The type is a pointer." << std::endl;
	}
	else if (std::is_null_pointer<T>::value) {
		std::cout << "The type is a null pointer." << std::endl;
	}
	else if (std::is_lvalue_reference<T>::value) {
		std::cout << "The type is an lvalue reference." << std::endl;
	}
	else if (std::is_rvalue_reference<T>::value) {
		std::cout << "The type is an rvalue reference." << std::endl;
	}
	else {
		std::cout << "The type is unknown." << std::endl;
	}
}

//TestClass for function members
class TestClass
{
public:
	void func() {};
	static void funcStatic() {};
};

template <typename T>
void IsPointer(const T& t)
{
	// First example of type_traits;check if t is a pointer
	// Return type is std::true_type or std::false_type

	if (std::is_pointer<T>::value)
	{
		std::cout << "This is a pointer type argument\n";
	}
	else
	{
		std::cout << "_not_ a pointer type argument\n";
	}
}


#endif