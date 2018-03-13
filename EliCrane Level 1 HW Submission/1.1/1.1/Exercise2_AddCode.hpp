#ifndef EXERCISE2_ADDCODE_HPP
#define EXERCISE2_ADDCODE_HPP


// N.B. Generic lambda
auto MyMultiply = [](auto x, auto y) { return x*y; };

struct FOMultiply
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x * y;
	}
};

template <typename T>
T MyMultiply2(const T& x, const T& y) { return x*y; };


#endif
