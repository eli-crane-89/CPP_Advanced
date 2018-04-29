#ifndef STACKSTATE_CPP
#define STACKSTATE_CPP

#include "StackState.hpp"
#include "EmptyStackState.hpp"
#include "FullStackState.hpp"


//Constructors
StackState::StackState() {};
StackState::StackState(const StackState& orig) {};

//Assignment Operator
StackState& StackState::operator=(const StackState& source) {
	return *this;
}

void StackState::Push(Stack* stack, int val) {

	stack->_stack.get()[stack->_index++] = val;

	//Need to compare to set size, because sizeof does not work on array stored in pointer
	if (stack->_index == stack->_size) {
		stack->_state = FullStackState::Instance();
	}
}

int StackState::Pop(Stack* stack) {

	//If at elem 1 change to empty stack
	if (stack->_index == 1) {
		stack->_state = EmptyStackState::Instance();
	}

	//Pre decrement index and return elem at index
	return stack->_stack.get()[--stack->_index];
}

#endif
