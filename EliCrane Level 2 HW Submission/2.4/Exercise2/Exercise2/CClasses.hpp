#ifndef CCLASSES_HPP
#define CCLASSES_HPP

#include <memory>
#include <iostream>

using namespace std;




//a) Create classes C1 and C2

template<typename T>
class C1
{
private:
	//double* d; OLD WAY
	std::shared_ptr<T> d;
public:
	C1(std::shared_ptr<T> value) : d(value) {}
	virtual ~C1() { cout << "\nC1 destructor\n"; }
	void print() const { cout << "Value " << *d << endl; }
};

template<typename T>
class C2
{
private:
	//double* d; OLD WAY
	std::shared_ptr<T> d;
public:
	C2(std::shared_ptr<T> value) : d(value) {}
	virtual ~C2() { cout << "\nC2 destructor\n"; }
	void print() const { cout << "Value " << *d << endl; }
};




#endif