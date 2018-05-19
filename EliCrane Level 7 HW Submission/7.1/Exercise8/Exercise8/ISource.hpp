#ifndef ISOURCE_HPP
#define ISOURCE_HPP

#include <string>
#include <tuple>

class ISource {

public:
	//Returns tuple of product choice and quantity
	virtual std::tuple<std::string, int> message() = 0;
};

#endif // ! ISOURCE_HPP
