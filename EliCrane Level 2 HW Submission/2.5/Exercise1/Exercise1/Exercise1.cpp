#include <iostream>

#include "NumberClassifier.hpp"

int main()
{

	//a)
	double val = std::numeric_limits<double>::max();
	std::cout << "val type: " << Classify<double>(val) << std::endl; //normal
	std::cout << "2.0 * val type: " << Classify<double>(2.0 * val) << std::endl; //Inf
	std::cout << "3.1415 + val type: " << Classify<double>(3.1415 + val) << std::endl; //normal
	double val2 = std::numeric_limits<double>::min() -3.1415; 
	std::cout << "val2 type: " << Classify<double>(val2) << std::endl; //normal
	std::cout << "val2 / 2.0 type: " << Classify<double>(val2 / 2.0) << std::endl; //normal
	std::cout << "DBL_MIN / 2. type: " << Classify<double>(DBL_MIN / 2.) << std::endl; //subnormal

	//b)
	auto lambdaClassify = [](const auto val) {

		std::cout << std::boolalpha;

		std::cout << "is finite: " << std::isfinite(val) << ", ";
		std::cout << "is inf: " << std::isinf(val) << ", ";
		std::cout << "is nan: " << std::isnan(val) << ", ";
		std::cout << "isnormal: " << std::isnormal(val) << std::endl;

	};

	double factor = 2.0;
	std::cout << "factor type: ";
	lambdaClassify(factor);
	val = factor*std::numeric_limits<double>::max();
	std::cout << "val type: ";
	lambdaClassify(val);
	std::cout << "val - val type: ";
	lambdaClassify(val - val);
	std::cout << "std::sqrt(-1.0) type: ";
	lambdaClassify(std::sqrt(-1.0));
	std::cout << "std::log(0.0) type: ";
	lambdaClassify(std::log(0.0));
	std::cout << "std::exp(val) type: ";
	lambdaClassify(std::exp(val));

    return 0;
}

