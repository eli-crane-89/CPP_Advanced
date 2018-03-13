#ifndef EXERCISE1_ADDCODE_HPP
#define EXERCISE1_ADDCODE_HPP

#include <functional>
#include <iostream>

using namespace std;

//Create Function Type alias of std::function for T function(T)
template <typename T>
using FunctionType = std::function<T(const T& t)>;


//Print Function
template <typename T>
void print(const FunctionType<T>& f, T t)
{
	std::cout << f(t) << '\n';
}


//Free Function
double returnR(double r) {

	return r;
};

//Multiply Functor
template<typename T>
class Multiply {
private:
	T multiplier;

public:
	Multiply(T _multiplier) : multiplier(_multiplier) {};
	T operator () (double val) const { return val * multiplier; };

};

#endif