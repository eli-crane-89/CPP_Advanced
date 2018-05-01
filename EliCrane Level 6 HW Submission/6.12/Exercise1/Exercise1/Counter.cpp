#ifndef COUNTER_CPP
#define COUNTER_CPP

#include <iostream>

#include "Counter.hpp"
#include "Observable.hpp"

//Constructors
Counter::Counter() : _value(0) {};
Counter::Counter(int value) : _value(value) {};

//Increase
void Counter::IncreaseCounter() {
	++_value;
	this->NotifyObservables();
}

//Decrease
void Counter::DecreaseCounter() {
	--_value;
	this->NotifyObservables();
}

//Get Counter
int Counter::GetCounter() const{
	return _value;
}
void Counter::AddObservable(Observable* obs) {
	//Delegate to observable
	Observable::AddObservable(obs);
}

void Counter::DeleteObservable(Observable* obs) {
	//Delegate to observable
	Observable::DeleteObservable(obs);
}

void Counter::NotifyObservables() {
	//Delegate to observable
	Observable::NotifyObservables();
}

void Counter::Update() {
	std::cout << "This counter is at: " << _value << std::endl;

	//On Update Decrease Counter to Furthe Propogate
	DecreaseCounter();

	//Create recursive call to Notify Observables
	Observable::NotifyObservables();
}

#endif