#ifndef NOACCESSEXCEPTION_HPP
#define NOACCESSEXCEPTION_HPP

#include "Exception.hpp"

class NoAccessException : public Exception {
public:
	void Message();
};


#endif