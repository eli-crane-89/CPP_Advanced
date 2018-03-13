#include <iostream>
#include <fstream>
#include <string>

#include <boost\system\error_code.hpp>

//Function Object
class FileFinalizer {
public:
	void operator() (FILE * f) {
		fclose(f);
		std::cout << "File has been released.\n";
	}
};


int main()
{

	//a) 

	//Create lambda
	auto filestream = [](std::string& fn) {
			std::cout << fn << std::endl;
			std::ifstream ifs(fn, std::ifstream::in);

			//Check if open, and if not make error condition
			if (!ifs.is_open()) return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);

			char c = ifs.get();

			//Prints line
			while (ifs.good()) {
				std::cout << c;
				c = ifs.get();
			}

			ifs.close();

			std::cout << std::endl; //To put a space after last line

			//Returns no error
			return boost::system::error_condition();

	};


	std::string fn1 = "test.txt";
	std::string fn2 = "noexist.txt";

	std::cout << filestream(fn1).message() << std::endl; //returns no error
	std::cout << filestream(fn2).message() << std::endl; //return no such file or directory

	//d)

	//Filestream lambda for C++ 11
	auto filestreamC11 = [](std::string& fn){
		std::cout << fn << std::endl;
		std::ifstream ifs(fn, std::ifstream::in);

		//Check if open, and if not make error condition
		if (!ifs.is_open()) return std::error_condition(std::errc::no_such_file_or_directory);

		char c = ifs.get();

		//Prints line
		while (ifs.good()) {
			std::cout << c;
			c = ifs.get();
		}

		ifs.close();

		std::cout << std::endl; //To put a space after last line

		//Returns no error
		return std::error_condition();

	};

	std::cout << filestreamC11(fn1).message() << std::endl; //returns no error
	std::cout << filestreamC11(fn2).message() << std::endl; //return no such file or directory

	
    return 0;
}

