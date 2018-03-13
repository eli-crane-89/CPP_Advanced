#include <iostream>

#include "Epsilon.hpp"

int main()
{
	double epsilon = 1.0;
	
	//a)
	auto _calcEpsilon = calcEpsilon<double>(epsilon);
	std::cout << _calcEpsilon << std::endl; //2.22045e-16

	//b)
	auto _numLimiEpsilon = std::numeric_limits<double>::epsilon();
	std::cout << _numLimiEpsilon << std::endl;  //2.22045e-16

	std::cout << std::boolalpha << "Calculated epsilon = numeric limit epsilon: " << (_numLimiEpsilon == _calcEpsilon) << std::endl;
	//true, the two values equal each other

    return 0;
}

