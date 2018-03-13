
#include <iostream>
#include <string>
#include <fstream>





int main()
{
	std::ifstream file(std::string("DOESNOTEXIST.txt"));
	try
	{
		// Set the exception mask of the file stream
		// In this case 1) logical error on I/O operation or
		// 2) read/write error on I/O operation
		file.exceptions(file.failbit | file.badbit);

	}
	catch (const std::ios_base::failure& e)
	{
		//a)
		if (e.code() == std::io_errc::stream) {

			//b)
			std::error_code ec1(e.code().value(), e.code().category());

			std::error_condition ec2(ec1.value(), ec1.category());

			std::cout << "Error value: " << ec2.value() << ", message: " << ec2.message() << ", category: " << ec2.category().name() << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "catch all\n";
	}

    return 0;
}

