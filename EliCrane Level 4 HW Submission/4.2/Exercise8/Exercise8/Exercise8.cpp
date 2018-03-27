#include <iostream>

#include "Stack.hpp"



int main()
{
	//Max - Non-modifying
	//Min - Non-modifying
	//Over - Modifying
	//rot - mutating
	//swap - mutating
	//drop - removing

	Stack<int> s;
	s.add(1);
	s.add(2);
	s.add(3);
	s.add(4);
	s.add(9);
	s.add(10);
	s.add(12);
	s.add(7);

	std::cout << "Printing original stack:\n";
	s.print();

	s.min();
	std::cout << "Printing stack after min:\n";
	s.print();

	s.max();
	std::cout << "Printing stack after max:\n";
	s.print();

	s.over();
	std::cout << "Printing stack after over:\n";
	s.print();

	s.rot();
	std::cout << "Printing stack after rot:\n";
	s.print();

	s.swap();
	std::cout << "Printing stack after swap:\n";
	s.print();

	s.drop();
	std::cout << "Printing stack after drop:\n";
	s.print();


    return 0;
}

