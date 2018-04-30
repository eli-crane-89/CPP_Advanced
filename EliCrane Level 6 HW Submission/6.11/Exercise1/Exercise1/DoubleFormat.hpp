#ifndef DOUBLEFORMAT_HPP
#define DOUBLEFORMAT_HPP

#include "Observer.hpp"

class Counter;

class DoubleFormat : public Observer {
private:
	Counter* m_counter;

public:
	//Constructor
	DoubleFormat(Counter*);

	//Update
	virtual void Update(Subject*);
};

#endif