#ifndef TMP_HPP
#define TMP_HPP

#include <iostream>
#include <functional>
#include <vector>
#include <cstdlib>
#include <algorithm>

using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

//a) TMP Class
class TMP final {
private:
	std::vector<double> _vDouble;
	double _startValue;
	std::size_t _n;
	InputFunction _iFunction;
	OutputFunction _oFunction;



public:
	TMP(std::size_t n, double startValue, InputFunction& iFunction, OutputFunction& oFunction) : _n(n), _startValue(startValue), _iFunction(iFunction),
		_oFunction(oFunction)
	{
		//Initialize Vector
		std::vector<double> vDouble(n);
		for (int i = 0; i < n; i++) {
			vDouble[i] = 1.0 + i;
		}
		_vDouble = vDouble;
	};

	//Create a compute function that transforms the vector elems by iFunction
	void Compute() {
		std::transform(_vDouble.begin(), _vDouble.end(), _vDouble.begin(), [&](double& elem) {
			return elem * _iFunction();
		});

		//Run oFunction
		_oFunction(_vDouble);

	};
};

//Define an ifunction that generates random numbers
double funcInput() {
	double randDouble = (double)(rand() % 15 + 1);
	std::cout << "Random number of " << randDouble << " generated." << std::endl;
	return randDouble;
}

//Define an oFunction to put elems
void funcOutput(const std::vector<double>& vDouble) {
	for (const auto& elem : vDouble) {
		std::cout << "The vector value has been transformed to " << elem << std::endl;
	}
}


#endif