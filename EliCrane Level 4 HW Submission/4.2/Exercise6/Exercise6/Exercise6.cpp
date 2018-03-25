#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>

#include "Point.hpp"
#include "AdditionalFunctions.hpp"

using namespace Eli::CAD;



auto lPrint = [](std::vector<char>& v, std::string msg) {
	std::cout << msg << ":\n";

	for (auto elem : v) {
		std::cout << elem << std::endl;
	}
};

int main()
{

	//a)
	std::vector<char> S1 = { 'a','b','c','d','e','k' };
	std::vector<char> S2 = { 'a', 'e' };

	//Make lambda to search for each char in S1
	//in S2
	auto l_ExcludeRange = [&](const char c) {
		auto it = std::find(S2.begin(), S2.end(), c);
		if (it != S2.end()) {
			return true;
		}
		return false;
	};

	//Erase all values to be excluded
	S1.erase(std::remove_if(S1.begin(), S1.end(), l_ExcludeRange), S1.end());
	lPrint(S1, "S1 after removing undesired elements");

	//b)
	Point p1(4, 5);
	Point p2(12, 84);
	Point p3(4, 5);
	Point p4(6, 7);
	Point p5(12, 84);

	std::vector<Point> vPoint = { p1, p2, p3, p4, p5 };

	std::vector<Point> vUnique;

	//Check if identical point exists exists in vUnique
	//Then use captue to add element to vUnique
	auto lUnique = [&](const Point& p) {
		if (std::find(vUnique.begin(), vUnique.end(), p) == vUnique.end()) {
			vUnique.push_back(p);
		};
	};

	std::for_each(vPoint.begin(), vPoint.end(), lUnique);

	std::cout << "vUnique containes:\n";
	for (auto elem : vUnique) {
		std::cout << elem << std::endl;
	}
	
	std::vector<Point> vDistance;
	Point pThreshold(4, 4);
	double threshold = 4.0;

	//Check if point is within threshold distance
	//Use capture on result vector and threshold
	auto lThreshold = [&](const Point& p) {
		if (pThreshold.Distance(p) <= threshold) {
			vDistance.push_back(p);
		}
	};

	std::for_each(vPoint.begin(), vPoint.end(), lThreshold);

	std::cout << "vDistance contains:\n";
	for (auto elem : vDistance) {
		std::cout << elem << std::endl;
	}

	//c)
	std::string s = "  there is  so much white space here   ";
	
	//Remove whitespace
	auto strBegin = s.find_first_not_of(" ");
	auto strEnd = s.find_last_not_of(" ");

	//new string
	s = s.substr(strBegin, strEnd-1);
	std::cout << "String without leading and trailing whitespace: " << s << ".\n";

	//Remove white space with predicate
	Trim trim;
	const std::string s2 = "\n\t   there is so much white space here\n\n   \t";
	std::cout << "String without leading and trailing whitespace: " << trim(s2) << ".\n";
    

	//Separate string into vector of strings
	SplitString ss(',');
	std::string sSplit = "Bobby,Larry,David,Moe,";

	auto vSplit = ss(sSplit);

	for (auto elem : vSplit) {
		std::cout << elem << std::endl;
	}

	//Join two strings
	std::string s1 = "This is the first string";
	std::string s3 = " and this is the second string\n";

	std::string s13 = JoinStrings(s1, s3);
	std::cout << s13 << std::endl;

	return 0;
}

