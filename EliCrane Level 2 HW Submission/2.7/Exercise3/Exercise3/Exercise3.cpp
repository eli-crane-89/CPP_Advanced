#include <iostream>
#include <string>

int main()
{

	//a)

	//io_error
	std::cout << std::error_condition(std::errc::io_error).message() << std::endl;

	//network_unreachable
	std::cout << std::error_condition(std::errc::network_unreachable).message() << std::endl;

	//no_such_file_or_directory
	std::cout << std::error_condition(std::errc::no_such_file_or_directory).message() << std::endl;
	
	//not_a_socket
	std::cout << std::error_condition(std::errc::not_a_socket).message() << std::endl;

	//Permission_denied
	std::cout << std::error_condition(std::errc::permission_denied).message() << std::endl;

	//b)

	//Generic category error message
	std::cout << std::error_condition(128, std::generic_category()).message() << std::endl; //not a socket error

	//c)
	
	std::error_condition ec = std::make_error_condition(std::io_errc::stream);
	std::cout << ec.message() << std::endl; //iostream stream error


    return 0;
}

