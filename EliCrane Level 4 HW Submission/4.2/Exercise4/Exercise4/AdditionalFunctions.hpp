#ifndef ADDITIONALFUNCTIONS_HPP
#define ADDITIONALFUNCTIONS_HPP

#include <tuple>
#include <algorithm>
#include <numeric>

template<typename T>
using tSumStats = std::tuple<T, T, T, double>;

template<typename T, class Container>
tSumStats<T> calculateSumStats(const Container& c) {
	tSumStats<T> tReturn;

	std::get<0>(tReturn) = *std::min_element(c.begin(), c.end());
	std::get<1>(tReturn) = *std::max_element(c.begin(), c.end());
	std::get<2>(tReturn) = std::accumulate(c.begin(), c.end(), 0);
	std::get<3>(tReturn) = (double)std::get<2>(tReturn) / (double)c.size();

	return tReturn;
}


struct ModCompare {
	ModCompare() {}
	bool operator()(int x, int compare) { return x % compare == 0; }
};

#endif