#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "EmptyStackState.hpp"

//Constructors
Stack::Stack() {
	Init(1);
}

Stack::Stack(int size) {
	Init(size);
}


//Init function
void Stack::Init(int size) {

	//set size for comparison
	_size = size;

	//check size
	if (_size < 1) {
		_size = 1;
	}

	//set array
	_stack = std::make_unique<int[]>(_size);

	//set index
	_index = 0;

	//set state
	_state = EmptyStackState::Instance();
}

void Stack::Push(int elem) {
	_state->Push(this, elem);
};

int Stack::Pop() {
	return _state->Pop(this);
};

#endif