#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <memory>

class Subject;

class Observer {
public:
	//Update Function
	virtual void Update(Subject*) = 0; //Use regular pointer so this can be used
};

#endif