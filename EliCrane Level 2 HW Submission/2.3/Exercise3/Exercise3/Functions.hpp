#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>
#include <cmath>
#include <iostream>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;

// Working function type
using ScalarFunction = FunctionType<double, double>;


template <typename R, typename D>
FunctionType<R, D> operator + (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) + g(x);
	};
}

template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	// Subtraction of functions
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}

template <typename R, typename D>
FunctionType<R, D> operator * (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	// Multiplication of functions
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}

template <typename R, typename D>
FunctionType<R, D> operator / (const FunctionType<R, D>& f,
	const FunctionType<R, D>& g)
{
	// Division of functions
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}

template <typename R, typename D>
FunctionType<R, D> operator -(const FunctionType<R, D>& f)
{
	// Negate functions
	return [=](const D& x)
	{
		return -f(x);
	};
}

//Use specialization for double multipication
template <typename R, typename D>
FunctionType<R, D> operator * (double scalar, const FunctionType<R, D>& f)
{
	//Multiply function by scalar
	return [=](const D& x)
	{
		return scalar * f(x);
	};
}

//Use specialization for int multiplication
template <typename R, typename D>
FunctionType<R, D> operator * (int scalar, const FunctionType<R, D>& f)
{
	//Multiply function by scalar
	return [=](const D& x)
	{
		return scalar * f(x);
	};
}

template<typename R, typename D>
FunctionType<R, D> operator << (FunctionType<R, D>& f, FunctionType<R, D>& g)
{
	//Composition of functions
	return [=](const D& x)
	{
		
		return f(g(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::exp(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f)
{
	// The cos function
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D>& f)
{
	// The sin function
	return [=](const D& x)
	{
		return std::sin(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D>& f)
{
	// The tan function
	return [=](const D& x)
	{
		return std::tan(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f)
{
	// The log function
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f)
{
	// The abs function
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f)
{
	// The abs function
	return [=](const D& x)
	{
		return std::sqrt(f(x));
	};
}

template<typename R, typename D>
FunctionType<R, D> min (FunctionType<R, D>& f, FunctionType<R, D>& g)
{
	//Minimum
	return [=](const D& x)
	{

		return (f(x) <= g(x)) ? f(x) : g(x);
	};
}

template<typename R, typename D>
FunctionType<R, D> max (FunctionType<R, D>& f, FunctionType<R, D>& g)
{
	//Maximum
	return [=](const D& x)
	{

		return (f(x) < g(x)) ? g(x) : f(x);
	};
}



#endif