#include <iostream>
#include <string>
#include <boost/bimap/bimap.hpp>

using BMType = boost::bimaps::bimap<std::string, int>;

int main()
{
	//a)
	BMType bm;

	bm.insert(BMType::value_type("John",3));
	//bm.emplace(BMType::value_type("Randy",42)); //does not work, no emplace
	bm.insert(BMType::value_type("Randy", 42));
	bm.insert(BMType::value_type("Marcus", 42)); //This is not added because of duplicate age
	bm.insert(BMType::value_type("Elizabeth", 37));
	bm.insert(BMType::value_type("Elizabeth", 82)); //This is not added because of duplicate name

	//b)
	for (auto iterLeft = bm.left.begin(); iterLeft != bm.left.end(); ++iterLeft) {
		std::cout << "left: " << iterLeft->first << ", right: " << iterLeft->second << std::endl;
	} //pr

	for (auto iterRight = bm.right.begin(); iterRight != bm.right.end(); ++iterRight) {
		std::cout << "right: " << iterRight->first << ", left: " << iterRight->second << std::endl;
	} //pr
	

	//c) Find
	std::cout << bm.left.find("John")->second << std::endl;
	std::cout << bm.right.find(3)->second << std::endl;

	//d) Iterate over bm from third view
	for (auto elem : bm) {
		std::cout << "left: " << elem.left;
		std::cout << ", right: " << elem.right << std::endl;
	} //prints in order from left element

	return 0;
}

