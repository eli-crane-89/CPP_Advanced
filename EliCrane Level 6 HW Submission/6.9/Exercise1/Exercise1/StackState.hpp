#ifndef STACKSTATE_HPP
#define STACKSTATE_HPP

#include <memory>

#include "Stack.hpp"
//#include "EmptyStackState.hpp"

class Stack;
//class EmptyStackState;

class StackState {

private:
	
	

protected:
	StackState(); // Default constructor
	StackState(const StackState&); // Copy constructor
	StackState& operator=(const StackState&);

public:
	virtual ~StackState() {};

	virtual void Push(Stack*, int) = 0;
	virtual int Pop(Stack*) = 0;

	

};

#endif