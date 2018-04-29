#ifndef PARTIALLYFULLSTACKSTATE_CPP
#define PARTIALLYFULLSTACKSTATE_CPP

#include "PartiallyFullStackState.hpp"


#ifndef FULLSTACKSTATE_CPP
#define FULLSTACKSTATE_CPP

#include <stdexcept>

#include "PartiallyFullStackState.hpp"

//Constructors
PartiallyFullStackState::PartiallyFullStackState() : StackState() {};
PartiallyFullStackState::PartiallyFullStackState(const PartiallyFullStackState& source) : StackState(source) {};

//Assignment operator
PartiallyFullStackState& PartiallyFullStackState::operator=(const PartiallyFullStackState& orig) {
	if (this != &orig) {
		StackState::operator=(orig);
	}
	return *this;
}

//Push delegation
void PartiallyFullStackState::Push(Stack* stack, int elem) {
	StackState::Push(stack, elem);
}

//Pop delegation
int PartiallyFullStackState::Pop(Stack* stack) {
	return StackState::Pop(stack);
}

//Singleton
PartiallyFullStackState* PartiallyFullStackState::Instance() {

	return Singleton<PartiallyFullStackState>::instance();
}


//Destructor
PartiallyFullStackState::~PartiallyFullStackState() {};

#endif
#endif;