#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Subject.hpp"

class Counter : public Subject {
private:
	int _value;

public:
	//Constructor
	Counter();

	//Methods
	void IncreaseCounter();
	void DecreaseCounter();
	int GetCounter() const;
};


#endif