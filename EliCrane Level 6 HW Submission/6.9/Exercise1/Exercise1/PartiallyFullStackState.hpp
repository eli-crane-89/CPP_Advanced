#ifndef PARTIALLYFULLSTACKSTATE_HPP
#define PARTIALLYFULLSTACKSTATE_HPP

#include "StackState.hpp"
#include "Singleton.hpp"


class PartiallyFullStackState : public StackState {

private:
	friend class Singleton<PartiallyFullStackState>;

public:

	PartiallyFullStackState(); // Default constructor
	PartiallyFullStackState(const PartiallyFullStackState&); // Copy constructor
	PartiallyFullStackState & operator = (const PartiallyFullStackState & source); //Assignment Operator

	//Methods
	void Push(Stack*, int);
	int Pop(Stack*);

	//Destructor
	~PartiallyFullStackState();

	//Singleton
	static PartiallyFullStackState* Instance();


};

#endif