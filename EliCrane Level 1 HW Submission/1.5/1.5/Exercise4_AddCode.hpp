#ifndef EXERCISE4_ADDCODE_HPP
#define EXERCISE4_ADDCODE_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <memory>
#include <stdlib.h>

//Define types
typedef std::vector<double> Vector;
typedef std::unique_ptr<Vector> uVector;

//Function for find n <= x < n + 1
template<typename T>
double findElemByBinaryOperator(const std::vector<T>& vNumeric, T x) {

	//binary operator that searches through term n and n + 1
	auto binaryOperator = [x](double lhs, double rhs) { return lhs <= x && x < rhs; };

	//Use in adjacent find to find the value and the index, then subtract the beginning position to get final position
	return find(vNumeric.begin(), vNumeric.end(), *std::adjacent_find(vNumeric.begin(), vNumeric.end(), binaryOperator)) - vNumeric.begin();

}

//Function to find errors

template<typename T1, typename T2>
using TuplePair = std::tuple<T1, T2>;

template<typename T>
TuplePair<T, int> findError(uVector&& uv1, uVector&& uv2, bool absolute) {

	//Create necessary iterators
	Vector::iterator itUV1 = uv1->begin();
	Vector::iterator itUVEnd1 = uv1->end();
	Vector::iterator itUV2 = uv2->begin();

	//Populate result vector with errors between terms
	Vector result;

	//Calculate absolute or relative error
	if (absolute) {
		std::transform(itUV1, itUVEnd1, itUV2, std::back_inserter(result), [&](T l, T r) {
			return std::abs(l - r);
		});
	}
	else {
		std::transform(itUV1, itUVEnd1, itUV2, std::back_inserter(result), [&](T l, T r) {
			return std::abs((l - r) / l);
		});
	};

	//Find the iterator with the maximum value
	auto maxIter = std::max_element(result.begin(), result.end());

	//Extract key values
	T maxError = *maxIter;
	int ixMax = maxIter - result.begin();

	TuplePair<T, int> tError = std::make_tuple(maxError, ixMax);
	return tError;

}

#endif