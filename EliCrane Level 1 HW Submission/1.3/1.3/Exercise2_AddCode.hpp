#ifndef EXERCISE2_ADDCODE_HPP
#define EXERCISE2_ADDCODE_HPP

#include <iostream>
#include <array>

class Shape
{
public:
	virtual void rotate(double d) = 0;
};

class Circle : public Shape
{
public:
	void rotate(double d) override { std::cout << "c\n"; }
};

class Line : public Shape
{
public:
	void rotate(double d) override { std::cout << "l\n"; }
};

class Valve
{
public:
	void rotate(double d) { std::cout << "v\n"; }
};

//Variadic Polymorphic Function double factor, 
template<typename T>
void rotate(double factor, T p) {
	p.rotate(factor);
	std::cout << "The final object has been rotated with a factor of: " << factor << std::endl;
}

template<typename T, typename... Args>
void rotate(double factor, T first, Args... args) {
	first.rotate(factor);
	std::cout << "An object has been rotated with a factor of: " << factor << std::endl;

	rotate(factor, args...);
}

#endif