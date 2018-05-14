#ifndef  SUBJECT_HPP
#define  SUBJECT_HPP

#include <functional>

template<template<typename,typename> class Container>
class Subject {
private:
	Container<std::function<void(double)>*, std::allocator<std::function<void(double)>*>> _observers;

public:
	//Control observer lists
	virtual void Attach(std::function<void(double)>*);
	virtual void Detach(std::function<void(double)>*);

	//Notify observers
	virtual void Notify(double);
};

#ifndef SUBJECT_CPP
#include "Subject.cpp"
#endif

#endif // ! SUBJECT_HPP
