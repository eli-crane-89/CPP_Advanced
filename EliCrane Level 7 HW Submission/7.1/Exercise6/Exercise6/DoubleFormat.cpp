#ifndef DOUBLEFORMAT_CPP
#define DOUBLEFORMAT_CPP

#include <iostream>
#include <iomanip>

#include "DoubleFormat.hpp"
#include "Counter.hpp"


//Constructor
DoubleFormat::DoubleFormat()  {};

//Update
void DoubleFormat::Update(double val) {

	std::cout << "Double format: " << std::setprecision(20) << (double)val << std::endl;

}


#endif