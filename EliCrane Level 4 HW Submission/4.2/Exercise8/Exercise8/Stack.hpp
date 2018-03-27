#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

template<typename T>
class Stack {

private:
	std::deque<T> stack;

public:
	//Constructor
	Stack();

	//helpers
	void add(const T&);
	void print();

	//operations
	void max();
	void min();
	void over();
	void rot();
	void swap();
	void drop();





};

#ifndef  STACK_CPP
#include "Stack.cpp"
#endif // ! STACK_CPP

#endif
