#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std; 

void Exercise1() {

	cout << endl << "Exercise1: " << endl;

	vector<double> vDouble;
	for (double i = 0; i < 50; i++) {
		vDouble.push_back(i*pow(-1, i));
	}

	std::for_each(vDouble.begin(), vDouble.end(), [](const auto &a) -> void {cout << a << endl; });

	//a) multiply array
	int multNum = 3;

	//Pass by copy
	std::for_each(vDouble.begin(), vDouble.end(), [=](auto &a) -> void {a *= multNum; });

	std::for_each(vDouble.begin(), vDouble.end(), [](const auto &a) -> void {cout << a << endl; }); //Array multiplied by 3

	//Pass by reference
	std::for_each(vDouble.begin(), vDouble.end(), [&](auto &a) -> void {a *= multNum; });

	std::for_each(vDouble.begin(), vDouble.end(), [](const auto &a) -> void {cout << a << endl; }); //Array multiplied by three again

	//b) Print with auto
	auto iterBegin = vDouble.begin();
	auto iterEnd = vDouble.end();

	std::for_each(iterBegin, iterEnd, [](const auto &a) -> void {cout << a << endl; });


	//c) Min and Max Lambda function	
	auto lambdaMinMax = [](const auto &v) {

		using vType = decay_t<decltype(v[0])>; //decay_t casts the decltype from const double -> double

		vType min = v[0];
		vType max = v[0];

		auto iterBegin = v.begin();
		auto iterEnd = v.end();
		//Pass values (min and max) by reference
		std::for_each(iterBegin, iterEnd, [&](const auto &a) {
			min = [&]() -> auto { return a < min ? a : min; }(); //Pass a and min by reference
			max = [&]() -> auto { return a > max ? a : max; }(); //Pass a and max by reference
		});

		tuple<vType, vType> tupleRet(min, max);

		return tupleRet;
	};

	auto tupMinMax = lambdaMinMax(vDouble);

	cout << "Min: " << get<0>(tupMinMax) << " Max: " << get<1>(tupMinMax) << endl;

	//d) minmax_element
	auto elemMinMax = minmax_element(vDouble.begin(), vDouble.end());

	cout << "min element at: " << elemMinMax.first - vDouble.begin() << '\n';
	cout << "max element at: " << elemMinMax.second - vDouble.begin() << '\n';

	//I find the minmax_element to be a bit more dyanmic since it returns the iterator rather than just the value
	//lambdaMinMax is generic and can be used on any vector with types that can be compared:

	vector<char> vChar;

	for (double i = 0; i < 50; i++) {
		vChar.push_back(i + 33);
	}

	//Test lambda minmax on char array

	auto tupCharMinMax = lambdaMinMax(vChar);

	cout << "Min: " << get<0>(tupCharMinMax) << " Max: " << get<1>(tupCharMinMax) << endl;
}

#endif;