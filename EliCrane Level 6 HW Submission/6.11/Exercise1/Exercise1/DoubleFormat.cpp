#ifndef DOUBLEFORMAT_CPP
#define DOUBLEFORMAT_CPP

#include <iostream>
#include <iomanip>

#include "DoubleFormat.hpp"
#include "Counter.hpp"


//Constructor
DoubleFormat::DoubleFormat(Counter* subject) : m_counter(subject) {
	subject->Attach(this);
};

//Update
void DoubleFormat::Update(Subject* subject) {

	if (subject == m_counter) {
		double d = (double)m_counter->GetCounter();
		std::cout << std::setprecision(20) << d << std::endl;
	}

}


#endif