#include <iostream>
#include <vector>
#include <array>
#include <complex>

#include "Addition.hpp"


int main() {

	std::cout << "Exercise1:" << std::endl;

	//Lambda to print 1-dimensional arrays
	auto print = [](const auto& arr) {
		for (auto i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << std::endl;
		}
	};


	//d) test

	//Define vectors
	std::vector<double> v1;
	std::vector<double> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(12.5);


	//Scalars
	int i = 17;
	int j = 4;

	//Arrays
	std::array<double, 3> a1{ 21,32,45 };
	std::array<double, 3> a2{ 41,32.7,45.8 };


	//Two vector addition
	auto v3 = Addition(v1, v2);
	print(v3);

	//Two array addition
	auto a3 = Addition(a1, a2);
	print(a3);

	//Two scalar addition
	auto k = Addition(i, j);
	std::cout << k << std::endl;

	//Vector Add inverse
	auto vinv = AdditiveInverse(v1);
	print(vinv);

	//Array Add Invese
	auto ainv = AdditiveInverse(a1);
	print(ainv);

	//Scalar Add inverse
	std::cout << AdditiveInverse(i) << std::endl;

	//Multiply Vectors
	auto v5 = Multiply(v1, v2);
	print(v5);

	//Multiply Arrays
	auto a4 = Multiply(a1, a2);
	print(a4);

	//Multiply Vector by Scalar
	auto v6 = Multiply(v1, 4.0);
	print(v6);

	//Multiply Array by Scalar
	auto a5 = Multiply(a1, 8.0);
	print(a5);

	//e) Complex
	std::vector<std::complex<double>> vc1;
	vc1.push_back(std::complex<double>(1.1, 3.0));
	vc1.push_back(std::complex<double>(1.0, 5.5));
	vc1.push_back(std::complex<double>(2.1, 6.3));

	std::vector<std::complex<double>> vc2;
	vc2.push_back(std::complex<double>(1.0, 3.0));
	vc2.push_back(std::complex<double>(1.3, 5.0));
	vc2.push_back(std::complex<double>(2.0, 6.0));

	//Addition
	auto vc3 = Addition(vc1, vc2);
	print(vc3);

	//Additive Inverse
	auto vc4 = AdditiveInverse(vc3);
	print(vc4);

	//Multiply
	auto vc5 = Multiply(vc1, vc2);
	print(vc5);

	//Multiply by Scalar
	std::complex<double> c1(3, 4);
	//auto vc6 = Multiply(vc1, c1); //This does not work because is_compund cannot differentiate between a complex number and an array
	//print(vc6);



}