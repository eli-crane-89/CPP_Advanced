#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <list>
#include <memory>

#include "Observable.hpp"


class Counter : public Observable {
private:

	//Members
	int _value;


public:
	//Constructor
	Counter();
	Counter(int);

	//Methods
	void AddObservable(Observable*);
	void DeleteObservable(Observable*);
	void NotifyObservables();
	void IncreaseCounter();
	void DecreaseCounter();
	int GetCounter() const;
	void Update();

};

#endif