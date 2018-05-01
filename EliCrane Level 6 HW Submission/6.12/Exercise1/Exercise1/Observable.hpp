#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include <memory>

#include "Observer.hpp"

class Observable : public Observer  {
protected:
	//Use shared pointers
	std::list<std::shared_ptr<Observable>> _observers;
public:
	//Control Observerable List
	virtual void AddObservable(const std::shared_ptr<Observable>&) = 0;
	virtual void DeleteObservable(const std::shared_ptr<Observable>&) = 0;
	virtual void NotifyObservables() = 0;

};

#endif