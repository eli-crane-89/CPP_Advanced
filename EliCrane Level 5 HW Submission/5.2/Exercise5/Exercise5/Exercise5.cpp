#include <iostream>
#include <regex>
#include <string>
#include <boost\algorithm\string.hpp>
#include <map>
#include <vector>
#include <boost\lexical_cast.hpp>

int main()
{
	std::regex myReg10(",");
	std::string sA("a = 1, b = 2, c = 3");

	//a)
	std::map<std::string, int> mRes;

	//-1 returns the non matched fragment
	auto it_token = std::sregex_token_iterator(sA.begin(), sA.end(), myReg10, -1);
	auto it_token_end = std::sregex_token_iterator();

	while (it_token != it_token_end) {

		std::vector<std::string> vString;
		std::string s = *it_token; //split only works if I convert *it_token to string first
		boost::split(vString, s, boost::is_any_of("="));

		//Make pair taking care to trim string and cast the value to int
		mRes.insert(std::pair<std::string, int>(boost::trim_copy(vString[0]),boost::lexical_cast<int>(boost::trim_copy(vString[1]))));

		it_token++;
	}

	for (auto iter = mRes.begin(); iter != mRes.end(); iter++) {
		std::cout << "Key: " << iter->first << " Value: " << iter->second << std::endl;
	}


    return 0;
}

