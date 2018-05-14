#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Subject.hpp"

template<template<typename, typename> class Container>
class Counter : public Subject<Container> {
private:
	int _value;

public:
	//Constructor
	Counter();

	//Methods
	void IncreaseCounter(double);
	void DecreaseCounter(double);
	int GetCounter() const;
};

#ifndef COUNTER_CPP
#include "Counter.cpp"
#endif


#endif