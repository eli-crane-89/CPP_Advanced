#ifndef FULLSTACKSTATE_CPP
#define FULLSTACKSTATE_CPP

#include <stdexcept>

#include "FullStackState.hpp"

//Constructors
FullStackState::FullStackState() : StackState(){};
FullStackState::FullStackState(const FullStackState& source) : StackState(source) {};

//Assignment operator
FullStackState& FullStackState::operator=(const FullStackState& orig) {
	if (this != &orig) {
		StackState::operator=(orig);
	}
	return *this;
}


//Push override
void FullStackState::Push(Stack* stack, int elem) {
	throw std::out_of_range("The stack is full.");
}

//Pop delegation
int FullStackState::Pop(Stack* stack) {
	return StackState::Pop(stack);
}

//Singleton
FullStackState* FullStackState::Instance() {

	return Singleton<FullStackState>::instance();
}


//Destructor
FullStackState::~FullStackState() {};

#endif