#ifndef NOFUNDSEXCEPTION_CPP
#define NOFUNDSEXCEPTION_CPP

#include <iostream>

#include "NoFundsException.hpp"

void NoFundsException::Message() {
	std::cout << "You have insufficient funds in your account.\n";
}

#endif
