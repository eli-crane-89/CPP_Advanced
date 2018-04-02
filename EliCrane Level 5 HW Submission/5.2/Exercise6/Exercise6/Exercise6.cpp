#include <regex>
#include <string>
#include <iostream>
#include <boost\lexical_cast.hpp>

int main()
{
	//a)
	//it searches for an optional + or - sign
	//it then searches for any number of digits unless it finds a "." or an e | E then a + or - 
	//finally followed by digits
	std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
	std::smatch m;
	
	//b)
	auto lCheckValid = [&](const std::string& s) {
		//a)
		//-1 returns the non matched fragment
		auto it_token = std::sregex_token_iterator(s.begin(), s.end(), ecmaReg);
		auto it_token_end = std::sregex_token_iterator();
		
		auto blValid = it_token != it_token_end;

		//c)
		//If number contains valid number parts convert to double
		if (blValid) {
			std::string fullNumber = ""; //initialize blank string
			while (it_token != it_token_end) {
				fullNumber += *it_token;

				it_token++;
			}
			std::cout << "fullNumber: " << boost::lexical_cast<double>(fullNumber)*-1 << std::endl;
		}
		
		return blValid;
	};

	std::string s1 = "1234567";
	std::string s2 = "-1234567";
	std::string s3 = "0001234567";
	std::string s4 = "1234.567";
	std::string s5 = "1234567";
	std::string s6 = "123";
	std::string s7 = "12.1E10";
	std::string s8 = "12.1E+10";
	std::string s9 = "a.";

	std::cout << std::boolalpha << lCheckValid(s1) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s2) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s3) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s4) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s5) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s6) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s7) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s8) << std::endl;
	std::cout << std::boolalpha << lCheckValid(s9) << std::endl;

    return 0;
}

