#ifndef EXERCISE1_ADDCODE_HPP
#define EXERCISE1_ADDCODE_HPP

#include <iostream>
#include <memory>

//a) Fix/refactor functions
struct Base
{
	virtual void draw() { std::cout << "print a base\n"; };
	virtual void print() {}; //Changed to virtual so it can be overriden
	~Base() { std::cout << "bye base\n"; };
};

//Removed final so the class could be derived from
struct Derived : public Base
{
	Derived() {}
	void draw() override { std::cout << "print a derived\n"; }
	void draw() const {}; //removed override since there is no virtual function in the base class that returns const
	void print() override {};
	~Derived() { std::cout << "bye derived\n"; }
};

class Derived2 : public Derived
{

};

//Define alias
using BaseSP = std::shared_ptr<Base>;

#endif