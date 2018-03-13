#ifndef EXERCISE3_ADDCODE_HPP
#define EXERCISE3_ADDCODE_HPP

#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <map>


using tupleSummaryStats = std::tuple<double, double, double, double, double>;

//Summary Statistics Function
template<typename T>
tupleSummaryStats calculateSummaryStats(const std::vector<T>& vNumeric) {

	//Define necessary variables
	auto iterBegin = vNumeric.begin();
	auto iterEnd = vNumeric.end();
	int vSize = vNumeric.size();

	//Mean
	double mean = std::accumulate(iterBegin, iterEnd, 0.0) / static_cast<T>(vSize);

	//Mean dev
	double meanDev = 0;
	for (auto iterCur = iterBegin; iterCur != iterEnd; iterCur++) {
		meanDev += std::abs(mean - *iterCur);
	}

	//Standard Deviation
	double sq_sum = std::inner_product(iterBegin, iterEnd, iterBegin, 0);
	double stdev = std::sqrt(sq_sum / vSize - mean * mean);

	//Range
	auto minmax = std::minmax_element(iterBegin, iterEnd);
	double range = *minmax.second - *minmax.first;

	//Variance
	double num = 0;
	for (auto iterCur = iterBegin; iterCur != iterEnd; iterCur++) {
		num += std::pow(std::abs(*iterCur - mean), 2);
	}
	double variance = num / (vSize);

	//Create tuple
	tupleSummaryStats tupleReturn = std::make_tuple(mean, meanDev, range, stdev, variance);

	return tupleReturn;
}

template<typename T>
using TupleMedianMode = std::tuple<T, T>;

//Median and Mode of a vector
template<typename T>
TupleMedianMode<T> returnMedianAndMode(const std::vector<T>& vNumeric) {
	T mode = *vNumeric.begin();
	double median;
	int vNumericSize = vNumeric.size();


	//Median
	if (vNumericSize % 2 == 1) {
		median = vNumeric[vNumericSize / 2]; //Take advantage of int rounding
	}
	else {
		median = (vNumeric[vNumericSize / 2 - 1] + vNumeric[vNumericSize / 2]) / 2;
	}

	//Mode
	std::map<T, int> mValues;
	std::vector<T> vKeys;
	T curVal;

	for (auto iterCur = vNumeric.begin(); iterCur != vNumeric.end(); iterCur++) {
		curVal = *iterCur;

		//Create a map of values and a vector of keys
		if (find(vKeys.begin(), vKeys.end(), curVal) == vKeys.end()) {
			vKeys.push_back(curVal);
			mValues.insert(std::pair<T, int>(curVal, 0));
		}

		//Increment mValues value for curVal key
		mValues[curVal]++;
	}

	//Find max count
	int maxCount = 0;
	for (auto iterCur = vKeys.begin(); iterCur != vKeys.end(); iterCur++) {
		int curCount = mValues[*iterCur];
		maxCount > curCount ? maxCount = maxCount : maxCount = curCount;
	}

	//Find first term in map that has max count by pre sorted vector
	auto iterCur = vNumeric.begin();
	while (mValues[mode] != maxCount) {
		mode = *iterCur;
		iterCur++;
	}

	TupleMedianMode<T> tupleReturn = std::make_tuple(median, mode);

	return tupleReturn;
}

#endif