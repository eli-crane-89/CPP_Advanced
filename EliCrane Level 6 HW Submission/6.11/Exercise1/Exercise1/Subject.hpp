#ifndef  SUBJECT_HPP
#define  SUBJECT_HPP

#include <memory>
#include <list>

class Observer;

class Subject {
private:
	std::list<Observer*> _observers;

public:
	//Control observer lists
	virtual void Attach(Observer* observer);
	virtual void Detach(Observer* observer);

	//Notify observers
	virtual void Notify();
};

#endif // ! SUBJECT_HPP
