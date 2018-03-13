#ifndef X_H
#define X_H

#include <iostream>
#include <memory>

struct X
{
	double val;

	X() : val(0.0) {}
	void operator ()() {
		std::cout << "An X " << val << std::endl;
	}
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

#endif