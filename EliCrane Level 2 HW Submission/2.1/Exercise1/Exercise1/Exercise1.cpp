// Exercise1.cpp : Defines the entry point for the console application.
//




#include <iostream>
#include <memory>

#include "AddCode.hpp"

using namespace std;
int main() {

	std::cout << "Exercise1:" << std::endl;

	//a)
	int i = 3;
	determineType<int>(i); //Unknown

	int * p = &i;
	determineType(p); //Pointer

	determineType(nullptr); //Null Pointer

	determineType<int &>(i); //lValue

	determineType<const int &&>(std::move(i)); //rValue

											   //b)
	if (std::is_member_function_pointer<decltype(&TestClass::func)>::value) {
		std::cout << "The type is to a member function pointer." << std::endl;
	}

	if (std::is_member_pointer<decltype(&TestClass::funcStatic)>::value) {
		std::cout << "The type is a non-static member function." << std::endl;
	}
	else {
		std::cout << "The type is a static member function." << std::endl;
	}

	//c)

	std::shared_ptr<TestClass> sp(new TestClass);
	IsPointer(sp); //Not a raw pointer
	IsPointer(sp.get()); //This is a raw pointer
	IsPointer(*sp); //Dereference to pointed TestClass

	return 0;
}
