#ifndef LONGFORMAT_CPP
#define LONGFORMAT_CPP

#include <iostream>

#include "LongFormat.hpp"
#include "Counter.hpp"


//Constructor
LongFormat::LongFormat(){};

//Update
void LongFormat::Update(double val) {

	long long ll = (long long)val;
	std::cout << "Long format: " << ll  << std::endl;


}


#endif