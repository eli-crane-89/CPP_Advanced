#include "Stack.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
	Stack stack(10);


	//Test pop error
	try {
		std::cout << stack.Pop() << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}


	//Populate stack
	for (int i = 0; i < 10; ++i) {
		std::cout << i << std::endl;
		stack.Push(i);
	}

	//Try and push one more
	try {
		stack.Push(3);
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	//Print stack
	for (int i = 10; i > 0; --i) {
		std::cout << stack.Pop() << std::endl;
	}
	

    return 0;
}

