#ifndef BASEDERIVED_HPP
#define BASEDERIVED_HPP

#include <iostream>
#include <list>
#include <memory>

using namespace std;

//Forward declare
class Base;

//Alias
using SharedBase = std::shared_ptr<Base>;

// Base class
class Base
{
private:
public:
	Base() {};

	virtual void print() const = 0;
protected:
	virtual ~Base() { cout << "Base destructor\n\n"; }
};

// Derived class
class Derived : public Base
{
private:
public:
	Derived() : Base() {};
	~Derived() { cout << "Derived destructor\n"; }
	void print() const { cout << "derived object\n"; }
};


SharedBase DerivedFactory() {
	SharedBase sb(new Derived());
	return sb;
}

#endif