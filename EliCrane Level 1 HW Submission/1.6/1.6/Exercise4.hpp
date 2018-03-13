#ifndef EXERCISE4_HPP
#define EXERCISE4_HPP

#include "Client.hpp"


void Exercise4() {
	std::cout << std::endl << "Exercise4: " << std::endl;

	// Client of storage using typedef
	int n = 10; int val = 2;
	Client<int> myClient(n, val); myClient.print();

	//b)
	//Yes output is the same
}

#endif