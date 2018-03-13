#ifndef EXERCISE5_ADDCODE_HPP
#define EXERCISE5_ADDCODE_HPP

#include <functional>

template<typename T1>
using DoubleFunctionType = std::function<T1(T1)>;

class NextGenShape
{
public:
	NextGenShape(DoubleFunctionType<double>& areaFunc, double factor)
		: _areaFunc(areaFunc), _fac(factor) {};

	double multiplyAreaFunc(double dimension) {
		return _areaFunc(dimension) * _fac;
	}

	void switchAreaFunction(DoubleFunctionType<double>& newAreaFunc) {
		_areaFunc = newAreaFunc;
	}
protected:

	DoubleFunctionType<double> _areaFunc;
	double _fac;

};

#endif