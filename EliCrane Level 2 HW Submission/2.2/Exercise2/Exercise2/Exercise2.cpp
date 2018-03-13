#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <tuple>
#include <memory>
#include <type_traits>

#include "AddCode.hpp"



int main() {

	std::cout << "Exercise2:" << std::endl;

	//a)
	std::cout << "Is a double an array: " << std::boolalpha << std::is_array<double>::value << std::endl; //false
	std::cout << "Is a const double an array: " << std::boolalpha << std::is_array<const double>::value << std::endl; //false
	std::cout << "Is a pointer an array: " << std::boolalpha << std::is_array<double*>::value << std::endl; //false
	std::cout << "Is a vector an array: " << std::boolalpha << std::is_array<std::vector<double>>::value << std::endl; //false
	std::cout << "Is an array an array: " << std::boolalpha << std::is_array<std::array<double, 5>>::value << std::endl; //false
	std::cout << "Is a TestClass an array: " << std::boolalpha << std::is_array<TestClass>::value << std::endl; //false
	std::cout << "Is a tuple an array: " << std::boolalpha << std::is_array<std::tuple<char>>::value << std::endl; //false
	std::cout << "Is a complex number an array: " << std::boolalpha << std::is_array<std::complex<double>>::value << std::endl; //false
	std::cout << "Is an array of ints an array: " << std::boolalpha << std::is_array<int[]>::value << std::endl; //true
	std::cout << "Is pointer to an array of ints an array: " << std::boolalpha << std::is_array<int *[]>::value << std::endl; //true
	std::cout << "Is TestClass[] an array: " << std::boolalpha << std::is_array<TestClass[]>::value << std::endl; //true
	std::cout << "Is unique pointer an array: " << std::boolalpha << std::is_array<std::unique_ptr<double>>::value << std::endl; //false
	std::cout << "Is unique pointer to int[] array: " << std::boolalpha << std::is_array<std::unique_ptr<int[]>>::value << std::endl; //false


																																	  //b)
	int arr[][3][4][5] = { {
		{ { 0,8,5,4,3 },{ 1,5,4,7,89 },{ 34,52,7,89,99 },{ 4,8,5,4,16 } },
		{ { 4,1,5,4,6 },{ 4,1,5,4,6 },{ 6,8,9,10,11 },{ 7,17,178,123,45 } },
		{ { 7,34,56,78,92 },{ 6,1,5,4,6 },{ 8,17,178,123,234 },{ 9,99,182,234,1 } }
		} };

	std::cout << "The rank of arr is: " << std::boolalpha << std::rank<decltype(arr)>::value << std::endl;
	std::cout << "The extent of arr 0 is: " << std::boolalpha << std::extent<decltype(arr), 0>::value << std::endl; //0
	std::cout << "The extent of arr 1 is: " << std::boolalpha << std::extent<decltype(arr), 1>::value << std::endl; //3
	std::cout << "The extent of arr 2 is: " << std::boolalpha << std::extent<decltype(arr), 2>::value << std::endl; //4
	std::cout << "The extent of arr 3 is: " << std::boolalpha << std::extent<decltype(arr), 3>::value << std::endl; //5

																													//c)
	using removeExtent = std::remove_extent<decltype(arr)>::type; //First dimension, [], removed
	std::cout << "The extent of arr 0 after removal is: " << std::boolalpha << std::extent<removeExtent, 0>::value << std::endl; //Now 3
	std::cout << "The extent of arr 1 after removal is: " << std::boolalpha << std::extent<removeExtent, 1>::value << std::endl; //Now 4
	std::cout << "The extent of arr 2 after removal is: " << std::boolalpha << std::extent<removeExtent, 2>::value << std::endl; //Now 5

	using removeAllExtent = std::remove_all_extents<decltype(arr)>::type; //Reduced down to int
	std::cout << "The extent of arr 0 after removal of all extens is: " << std::boolalpha << std::extent<removeAllExtent, 0>::value << std::endl; //0

	removeAllExtent rae = 1;//can be set to int
	std::cout << "The type of removeAllExtent: " << typeid(rae).name() << std::endl;

	return 0;

}

