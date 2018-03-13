#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

#include "C.hpp"

inline void Exercise3() {

	cout << endl << "Exercise3: " << endl;

	//a) Move copy and assignment

	//b) 
	C<int> cInt;
	C<int> cIntCopy = std::move(cInt); //Move Constructor called
	C<int> cInt2;
	cInt2 = std::move(cIntCopy); //Move Assignment Operator called
	
	//Using std::move ensures the move functions are called

	//c) Try to move with lvalue
	//Cannot run below code with an lvalue
	//cInt2 = cIntCopy;

}

#endif