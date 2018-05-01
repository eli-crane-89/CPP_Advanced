#ifndef STACK_HPP
#define STACK_HPP

#include <memory>

#include "Stack.hpp"
#include "StackState.hpp"

class StackState;

class Stack {
private:
	//Make friend
	friend class StackState;

	//Declare members
	std::unique_ptr<int[]> _stack;
	int _index;
	StackState* _state; //Use raw so it works with this
	int _size;

	//Init function
	void Init(int);


public:
	//Constructors
	Stack();
	Stack(int);

	//Methods
	void Push(int);
	int Pop();
};

#endif