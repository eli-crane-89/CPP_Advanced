#ifndef STACK_CPP
#define STACK_CPP

#include <deque>
#include <algorithm>
#include <iostream>

#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() : stack(std::deque<T>()) {};

//Add item to stack
template<typename T>
void Stack<T>::add(const T& elem) {
	stack.push_back(elem);
}

//Find min of top two elements and remove non min
template<typename T>
void Stack<T>::min() {

	//Only perform is dq size is greater than 1
	if (stack.size() > 1) {
		if (stack[0] > stack[1]) {
			stack.pop_front();
		}
		else {
			stack.erase(stack.begin() + 1);
		}

	}
}

//Find max of top two elements and remove non max
template<typename T>
void Stack<T>::max() {

	//Only perform is dq size is greater than 1
	if (stack.size() > 1) {
		if (stack[0] <= stack[1]) {
			stack.pop_front();
		}
		else {
			stack.erase(stack.begin() + 1);
		}

	}

}

//Find max of top two elements and remove non max
template<typename T>
void Stack<T>::over() {

	//Only perform is dq size is greater than 1
	if (stack.size() > 1) {
		stack.push_back(stack[1]);

	}

}

//Rotate third element to front
template<typename T>
void Stack<T>::rot() {

	//Only perform is dq size is greater than 2
	if (stack.size() > 2) {
		std::rotate(stack.begin(), stack.begin() + 2, stack.end());
	}

}

//Swap top two elements
template<typename T>
void Stack<T>::swap() {

	//Only perform if dq size is greater than 1
	if (stack.size() > 1) {
		std::swap(stack[0], stack[1]);
	}
}

//Drop last element
template<typename T>
void Stack<T>::drop() {

	//Only perform if stack has elements
	if (stack.size() > 0) {
		stack.pop_back();
	}

}

template<typename T>
void Stack<T>::print() {
	for (auto elem : stack) {
		std::cout << elem << std::endl;
	}

}

#endif

