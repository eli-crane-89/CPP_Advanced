#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include <memory>

#include "Observer.hpp"

class Observable : public Observer  {
protected:
	//Use raw pointers since they are easier to pass between objects
	std::list<Observable*> _observers;
public:
	//Control Observerable List
	virtual void AddObservable(Observable*) = 0;
	virtual void DeleteObservable(Observable*) = 0;
	virtual void NotifyObservables() = 0;

};

#endif