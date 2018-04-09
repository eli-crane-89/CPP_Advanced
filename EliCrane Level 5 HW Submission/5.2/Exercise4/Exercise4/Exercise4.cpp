#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <boost\lexical_cast.hpp>

int main()
{
	std::regex myReg10("/");
	std::string S3 = "2016/3/15";

	//a)
	//-1 returns the non matched fragment
	auto it_token = std::sregex_token_iterator(S3.begin(), S3.end(), myReg10, -1);
	auto it_token_end = std::sregex_token_iterator();

	//Just gonna put in a vector of ints since conversion to gregorian date is trivial
	std::vector<int> vInt;
	while (it_token != it_token_end) {
		vInt.push_back(boost::lexical_cast<int>(*it_token));

		it_token++;
	}

	//b)
	//returns matched expression
	auto it_token2 = std::sregex_token_iterator(S3.begin(), S3.end(), myReg10);
	auto it_token2_end = std::sregex_token_iterator();

	//Place results in vector of chars
	std::vector<char> vChar;
	while (it_token2 != it_token2_end) {
		vChar.push_back(boost::lexical_cast<char>(*it_token2));

		it_token2++;
	}

	//c)

	for (auto elem : vInt) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;

	for (auto elem : vChar) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;



    return 0;
}

