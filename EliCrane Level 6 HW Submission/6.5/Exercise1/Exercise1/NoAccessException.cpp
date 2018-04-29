#ifndef NOACCESSEXCEPTION_CPP
#define NOACCESSEXCEPTION_CPP

#include <iostream>
#include "NoAccessException.hpp"


void NoAccessException::Message() {
	std::cout << "You password did not match the one we have for your account.\n";
}



#endif