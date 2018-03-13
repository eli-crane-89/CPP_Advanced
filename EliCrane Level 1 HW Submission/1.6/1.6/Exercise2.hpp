#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include "TMP.hpp"

void Exercise2() {

	std::cout << std::endl << "Exercise2: " << std::endl;

	InputFunction iFunction = funcInput;
	OutputFunction oFunction = funcOutput;

	std::size_t n = 10;
	double startValue = 0;

	//b) Instantiate
	TMP tmp = TMP(n, startValue, iFunction, oFunction);
	tmp.Compute();
}

#endif // ! EXERCISE2_HPP
