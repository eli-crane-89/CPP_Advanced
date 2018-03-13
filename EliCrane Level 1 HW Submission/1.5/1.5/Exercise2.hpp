#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <tuple>
#include <iostream>
#include <complex>

#include "Exercise2_AddCode.hpp"
	
typedef std::tuple<double, double> NumberTuple2;
typedef std::tuple<double, double, double> NumberTuple3;

template<typename T>
using  NumberComplexTuple3 = std::tuple<std::complex<T>, std::complex<T>, std::complex<T>>;

void Exercise2() {

	std::cout << std::endl << "Exercise2: " << std::endl;

	NumberTuple2 tNums2(3.6, 3.4);
	NumberTuple3 tNums3(4.2, 12.7, 1.3);

	const int N2 = std::tuple_size<decltype(tNums2)>::value;
	const int N3 = std::tuple_size<decltype(tNums3)>::value;
	
	//b)) Sum, Average, Max
	std::cout << Calculator<double, NumberTuple2, N2>::sum(tNums2) << std::endl;
	std::cout << Calculator<double, NumberTuple3, N3>::sum(tNums3) << std::endl;

	std::cout << Calculator<double, NumberTuple2, N2>::average(tNums2) << std::endl;
	std::cout << Calculator<double, NumberTuple3, N3>::average(tNums3) << std::endl;

	std::cout << Calculator<double, NumberTuple2, N2>::maximum(tNums2) << std::endl;
	std::cout << Calculator<double, NumberTuple3, N3>::maximum(tNums3) << std::endl;
	
	//c) Complex numbers sum and average
	NumberComplexTuple3<int> nct3((3, 4),(8,1),(5,6));
	const int NC3 = std::tuple_size<decltype(nct3)>::value;

	std::cout << Calculator<std::complex<int>, NumberComplexTuple3<int>, NC3>::sum(nct3) << std::endl;
	std::cout << Calculator<std::complex<int>, NumberComplexTuple3<int>, NC3>::average(nct3) << std::endl;
}


#endif