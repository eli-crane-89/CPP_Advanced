#ifndef COUNTER_CPP
#define COUNTER_CPP

#include "Counter.hpp"

//Constructor
Counter::Counter() : _value(0) {};

//Increase
void Counter::IncreaseCounter() {
	++_value;
	this->Notify();
}

//Decrease
void Counter::DecreaseCounter() {
	--_value;
	this->Notify();
}

//Get Counter
int Counter::GetCounter() const{
	return _value;
}

#endif