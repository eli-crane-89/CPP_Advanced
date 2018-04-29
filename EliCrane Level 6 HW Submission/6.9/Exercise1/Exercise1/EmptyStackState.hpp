#ifndef EMPTYSTACKSTATE_HPP
#define EMPTYSTACKSTATE_HPP

#include "StackState.hpp"
#include "Singleton.hpp"


class EmptyStackState : public StackState {

private:
	friend class Singleton<EmptyStackState>;

public:

	EmptyStackState(); // Default constructor
	EmptyStackState(const EmptyStackState&); // Copy constructor
	EmptyStackState& operator = (const EmptyStackState& source); //Assignment Operator

	//Destructor
	~EmptyStackState();

	//Override
	void Push(Stack*, int);
	int Pop(Stack*);

	//Singleton
	static EmptyStackState* Instance();

};

#endif