#ifndef EMPTYSTACKSTATE_CPP
#define EMPTYSTACKSTATE_CPP

#include <stdexcept>

#include "EmptyStackState.hpp"

//Constructors
EmptyStackState::EmptyStackState() : StackState() {};
EmptyStackState::EmptyStackState(const EmptyStackState& source) : StackState(source) {};

//Assignment operator
EmptyStackState& EmptyStackState::operator=(const EmptyStackState& orig) {
	if (this != &orig) {
		StackState::operator=(orig);
	}
	return *this;
}

//Singleton
EmptyStackState* EmptyStackState::Instance() {

	return Singleton<EmptyStackState>::instance();
}

//Push delegation
void EmptyStackState::Push(Stack* stack, int elem) {
	StackState::Push(stack, elem);
}

int EmptyStackState::Pop(Stack* stack) {
	//Throw error since stack cannot be popped
	throw std::out_of_range("The stack is empty.");

	//This will never return
	return 0;
}



//Destructor
EmptyStackState::~EmptyStackState() {};


#endif