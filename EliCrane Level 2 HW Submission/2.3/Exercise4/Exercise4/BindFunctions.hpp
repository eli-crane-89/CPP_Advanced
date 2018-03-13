#ifndef BINDFUNCTIONS_HPP
#define BINDFUNCTIONS_HPP

#include <functional>

// Function maps Domain to Range

using ScalarFunction = std::function<double(const double&)>;

using namespace std::placeholders;

template <typename T>
std::function<T(const T&)> bind1st
(const std::function<T(const T& x, const T& y)>& f, const T& x_)
{
	//Bind to the first param x of f(x,y)
	return std::bind(f, x_, _1);

	
}

template <typename T>
std::function<T(const T&)> bind2nd
(const std::function<T(const T& x, const T& y)>& f, const T& y_)
{
	// Bind to the second param y of f(x,y)
	return std::bind(f, _1, y_);
}

#endif