#ifndef EXERCISE4_HPP
#define EXERCISE4_HPP

#include "Exercise4_AddCode.hpp"

void Exercise4() {

	std::cout << std::endl << "Exercise4: " << std::endl;

	std::vector<double> vDouble;
	vDouble.push_back(1.5);
	vDouble.push_back(3.1);
	vDouble.push_back(12.88);
	vDouble.push_back(32.4);
	vDouble.push_back(32.4);
	vDouble.push_back(54.6);

	//a)
	std::cout << "Index satisfying the condition n <= x < n + 1: " << findElemByBinaryOperator<double>(vDouble, 13) << std::endl;

	//b)

	//create vectors as Unique Pointers
	uVector v1(new Vector);
	v1->push_back(1.5);
	v1->push_back(2.312);
	v1->push_back(4.8);
	v1->push_back(23.7);
	v1->push_back(48.45);

	uVector v2(new Vector);
	v2->push_back(260);
	v2->push_back(312.2);
	v2->push_back(8.4);
	v2->push_back(4.7);
	v2->push_back(50.45);

	TuplePair<double, int> tupAbsError = findError<double>(std::move(v1), std::move(v2), 1);
	TuplePair<double, int> tupRelError = findError<double>(std::move(v1), std::move(v2), 0);
	
	double absoluteErrorMax, relativeErrorMax;
	int absoluteErrorIndex, relativeErrorIndex;
	std::tie(absoluteErrorMax, absoluteErrorIndex) = tupAbsError;
	std::tie(relativeErrorMax, relativeErrorIndex) = tupRelError;

	std::cout << "Max absolute error is: " << absoluteErrorMax << std::endl;
	std::cout << "With the terms located at the index of " << absoluteErrorIndex << std::endl;
	std::cout << "Max relative error is: " << relativeErrorMax << std::endl;
	std::cout << "With the terms located at the index of " << relativeErrorIndex << std::endl;

}


#endif
