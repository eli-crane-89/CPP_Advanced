#ifndef LONGFORMAT_HPP
#define LONGFORMAT_HPP

#include "Observer.hpp"

class Counter;

class LongFormat : public Observer {
private:
	Counter* m_counter;

public:
	//Constructor
	LongFormat(Counter*);

	//Update
	virtual void Update(Subject*);
};

#endif