#ifndef ISINK_HPP
#define ISINK_HPP

#include <string>

class ISink {
public:
	//Thanks customer
	virtual void notify(std::string, bool) = 0;
};

#endif