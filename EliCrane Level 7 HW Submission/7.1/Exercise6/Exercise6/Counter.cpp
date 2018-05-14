#ifndef COUNTER_CPP
#define COUNTER_CPP

#include "Counter.hpp"

//Constructor
template<template<typename, typename> class Container>
Counter<Container>::Counter() : _value(0) {};

//Increase
template<template<typename, typename> class Container>
void Counter<Container>::IncreaseCounter(double val) {
	++_value;
	this->Notify(val);
}

//Decrease
template<template<typename, typename> class Container>
void Counter<Container>::DecreaseCounter(double val) {
	--_value;
	this->Notify(val);
}

//Get Counter
template<template<typename, typename> class Container>
int Counter<Container>::GetCounter() const{
	return _value;
}

#endif