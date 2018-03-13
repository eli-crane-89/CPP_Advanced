#include <iostream>

#include "ErrorCondition.hpp"

int main()
{


	//a)
	//Default constructor
	std::cout << "The default error condition: ";
	std::cout << std::error_condition().message() << std::endl;

	//Value Error
	std::error_condition ec(2, std::generic_category());
	std::cout << "\n" << 2 << ": " << ec.message() << std::endl;

	//Based on std::errc
	std::cout << std::error_condition(std::errc::address_in_use).message() << std::endl;


	//b)
	tupError te = parseErrorCond(ec);

	std::cout << "Message: " << std::get<0>(te) << std::endl;
	std::cout << "Value: " << std::get<1>(te) << std::endl;
	std::cout << "Category: " << std::get<2>(te) << std::endl;





    return 0;
}

