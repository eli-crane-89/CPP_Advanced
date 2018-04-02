#include <regex>
#include <string>
#include <iostream>
#include <boost\lexical_cast.hpp>
#include <set>
int main()
{
	std::string S2 = "1,1,2,3,5,8,13,21";
	std::regex myReg("(\\d+),?");

	//a)
	std::sregex_iterator iter_srgx = std::sregex_iterator(S2.begin(), S2.end(), myReg);
	std::sregex_iterator iter_srgx_end;

	//b)
	std::set<std::string> s1;

	//sregex_iterator capures each instance of the matched expression
	while (iter_srgx != iter_srgx_end) {
		std::smatch match = *iter_srgx;
		std::string match_str = match.str();
		s1.insert(match_str);

		iter_srgx++;
	}

	//c)
	//output order is alphabetical, also no repeating values in set
	for (auto elem : s1) {
		std::cout << elem << std::endl;
	}

	//d)
	std::cout << std::endl;

	std::set<int> s2;
	myReg = "(\\d+)"; //change to not get comma
	iter_srgx = std::sregex_iterator(S2.begin(), S2.end(), myReg);

	while (iter_srgx != iter_srgx_end) {
		std::smatch match = *iter_srgx;
		std::string match_str = match.str();

		//use lexical cast for str -> int conversion
		s2.insert(boost::lexical_cast<int>(match_str));

		iter_srgx++;
	}

	//output order is numeric
	for (auto elem : s2) {
		std::cout << elem << std::endl;
	}

    return 0;
}

