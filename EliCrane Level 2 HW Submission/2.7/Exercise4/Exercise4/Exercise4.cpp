#include <iostream>
#include <string>
#include <tuple>

//b) Function to return tuple of error_code
std::tuple<std::string, int, std::string> parseErrorCode(std::error_code& ec) {
	std::tuple<std::string, int, std::string> tupEC = std::make_tuple(ec.message(), ec.value(), ec.category().name());

	return tupEC;
}



int main()
{

	//a)
	errno = 0;

	//Default error code
	std::error_code ec(errno, std::generic_category());

	//Platform specific
	std::error_code ecPlat(4, std::iostream_category());
	std::cout << "Platform specific error: " << ecPlat.message() << std::endl;

	//c)
	std::error_condition econd(errno, std::generic_category());
	std::cout << std::boolalpha << (ec == econd) << std::endl; //true

	std::error_condition econd2(1, std::generic_category());
	std::cout << std::boolalpha << (ec == econd2) << std::endl; //false

	std::error_condition econd3(4, std::iostream_category());
	std::cout << std::boolalpha << (ecPlat == econd3) << std::endl; //true





    return 0;
}

