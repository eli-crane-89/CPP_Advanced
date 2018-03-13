#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

#include "Exercise3_AddCode.hpp"

void Exercise3() {

	std::cout << std::endl << "Exercise3: " << std::endl;

	std::vector<double> vDouble;
	vDouble.push_back(1.5);
	vDouble.push_back(3.1);
	vDouble.push_back(12.88);
	vDouble.push_back(32.4);
	vDouble.push_back(32.4);
	vDouble.push_back(54.6);

	//a)Summary Statistics
	double mean, meanDev, range, stdDev, variance;

	tupleSummaryStats sumStats = calculateSummaryStats<double>(vDouble);
	std::tie(mean, meanDev, range, stdDev, variance) = sumStats;

	//b) show stats

	std::cout << "mean: " << mean << std::endl;
	std::cout << "meanDev: " << meanDev << std::endl;
	std::cout << "range: " << range << std::endl;
	std::cout << "stdev: " << stdDev << std::endl;
	std::cout << "variance: " << variance << std::endl;

	//c) Mean and Mode
	double median, mode;
	TupleMedianMode<double> medianMode = returnMedianAndMode<double>(vDouble);
	std::tie(median, mode) = medianMode;

	std::cout << "median: " << median << std::endl;
	std::cout << "mode: " << mode << std::endl;
}

#endif