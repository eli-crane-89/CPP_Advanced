#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <vector>
#include <cmath>
#include <numeric>
#include <complex>

#include "Exercise2_AddCode.hpp"

using namespace std;

void Exercise2() {

	cout << endl << "Exercise2: " << endl;

	//a) Generic Lambda:

	//Can be used on doubles
	auto mult = MyMultiply(4.3, 5.0);
	cout << mult << endl;

	// Using complex numbers
	using Complex = std::complex<double>;
	std::vector<Complex>
		complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };
	Complex initCVal(1.0, 1.0);

	Complex acc6C = MyMultiply(Complex(1.0, 1.0), MyMultiply(Complex(1.0, 1.0), Complex(2.0, 2.0)));
	Complex acc6C2 = accumulate(complexArray.begin(),
		complexArray.end(), initCVal, MyMultiply2<Complex>);

	std::cout << "Sum 6 with MyMultiply, complex numbers: " << acc6C << std::endl;
	std::cout << "Sum 6 with MyMultiply2, complex numbers: " << acc6C2 << std::endl;

	//Yes, MyMultiply lambda function is capable of multiplying complex numbers

	//b)  Embedded Lambda
	auto lambdaAccumulate = [](const auto &v, auto initValue) {

		auto iterBegin = v.begin();
		auto iterEnd = v.end();

		for_each(iterBegin, iterEnd, [&](const auto &a) {initValue *= a; });

		return initValue;
	};

	vector<double> vDouble;
	for (double i = 1; i < 10; i++) {
		vDouble.push_back(i*pow(-1, i));
	}

	auto lamAccum = lambdaAccumulate(vDouble, 1);

	cout << lamAccum << endl;

	//c) Stored lambda function
	auto lambdaFunc = [](const auto &a) {cout << "value: " << a << endl; };

	for_each(vDouble.begin(), vDouble.end(), lambdaFunc);


}

#endif;