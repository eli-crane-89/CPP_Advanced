#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <list>
#include <memory>

#include "Observable.hpp"


class Counter : public Observable {
private:

	//Members
	int _value;


	//Private
	void IncreaseCounter();
	void DecreaseCounter();


public:
	//Constructor
	Counter();
	Counter(int);

	//Methods
	void AddObservable(const std::shared_ptr<Observable>&);
	void DeleteObservable(const std::shared_ptr<Observable>&);
	void NotifyObservables();
	
	int GetCounter() const;
	void Update();

};

#endif