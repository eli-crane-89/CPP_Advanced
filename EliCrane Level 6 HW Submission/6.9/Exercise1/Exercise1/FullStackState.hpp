#ifndef FULLSTACKSTATE_HPP
#define FULLSTACKSTATE_HPP

#include "StackState.hpp"
#include "Singleton.hpp"


class FullStackState : public StackState {
	

private:
	friend class Singleton<FullStackState>;

public:

	FullStackState(); // Default constructor
	FullStackState(const FullStackState&); // Copy constructor
	FullStackState & operator = (const FullStackState & source); //Assignment Operator

	//Destructor
	~FullStackState();

	//Override
	void Push(Stack*, int);
	int Pop(Stack*);

	static FullStackState* Instance();

};

#endif