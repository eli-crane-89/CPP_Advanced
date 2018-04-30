#ifndef LONGFORMAT_CPP
#define LONGFORMAT_CPP

#include <iostream>

#include "LongFormat.hpp"
#include "Counter.hpp"


//Constructor
LongFormat::LongFormat(Counter* subject) : m_counter(subject) {
	subject->Attach(this);
};

//Update
void LongFormat::Update(Subject* subject) {

	if (subject == m_counter) {
		long long ll = (long long)m_counter->GetCounter();
		std::cout << ll  << std::endl;
	}

}


#endif