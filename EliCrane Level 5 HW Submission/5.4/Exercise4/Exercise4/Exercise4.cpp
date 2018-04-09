#include <iostream>
#include <string>

#include "HashFunction.hpp"
#include "Line.hpp"

using namespace CAD;

int main()
{
	std::string s = "This is a good test string.", s2 = "This is an even better test string.";
	std::size_t seed = 0;

	hash_value(seed, s, s2);
	std::cout << seed << std::endl;

	//b)
	//Aux function on strings
	std::cout << hash_value(s, s2) << std::endl; //same value as above

	Point p1(1, 3);
	Point p2(2, 4);
	Point p3(3, 5);
	Line line1(p1, p2);
	Line line2(p2, p3);

	std::cout << "hash p1: " << hash_value(p1) << std::endl;
	std::cout << "hash p1, p2: " << hash_value(p1, p2) << std::endl;
	std::cout << "hash p1, p2, p3: " << hash_value(p1, p2, p3) << std::endl;
	std::cout << "hash line1: " << hash_value(line1) << std::endl;
	std::cout << "hash line2: " << hash_value(line2) << std::endl;
	std::cout << "hash line1, line2: " << hash_value(line1, line2) << std::endl; //different than line1 or line2
	std::cout << "hash line2, line1: " << hash_value(line2, line1) << std::endl; //different from line1, line2
	


    return 0;
}

