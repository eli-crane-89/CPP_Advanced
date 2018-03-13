#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {

public:
	std::string m_name;

	//Default constructor
	Client() : m_name("John") {};

	//Named constructor
	Client(std::string name) : m_name(name) {};


};


#endif // ! CLIENT_HPP
