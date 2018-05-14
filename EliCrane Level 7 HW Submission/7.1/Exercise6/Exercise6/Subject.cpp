#ifndef  SUBJECT_CPP
#define  SUBJECT_CPP

#include "Subject.hpp"
#include <algorithm>

template<template<typename, typename> class Container>
void Subject<Container>::Attach(std::function<void(double)>* obs) {
	_observers.push_back(obs);
}

template<template<typename, typename> class Container>
void Subject<Container>::Detach(std::function<void(double)>* obs) {
	//Need to change so that it works with more container types
	_observers.erase(std::remove(_observers.begin(), _observers.end(),obs),_observers.end());
}

template<template<typename, typename> class Container>
void Subject<Container>::Notify(double val) {
	for (auto it = _observers.begin(); it != _observers.end(); ++it) {
		(*it)->operator()(val);
	}
}

#endif