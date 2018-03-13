#ifndef EXERCISE4_ADDCODE_HPP
#define EXERCISE4_ADDCODE_HPP

#include <functional>
#include <iostream>

using VoidFunctionType = std::function<void(double)>;

void ShapeRotate(double factor) {
	std::cout << "Rotated shape by a factor of " << factor << std::endl;
}

void CircleRotate(double factor) {
	std::cout << "Rotated circle by a factor of " << factor << std::endl;
}

// Class hierarchy
class Shape
{
public:
	Shape(const VoidFunctionType &rotateFunction) : f(rotateFunction) {};
	virtual void rotate(double d) { f(d); };

protected:
	VoidFunctionType f;

};

class Circle : public Shape
{
public:
	//Call Base class to set member
	Circle(const VoidFunctionType &rotateFunction) : Circle::Shape(rotateFunction) {};

	//Rotate, does not need override since it overrides by default
	void rotate(double d) { std::cout << "Circle rotate called." << std::endl; f(d); }
};

#endif