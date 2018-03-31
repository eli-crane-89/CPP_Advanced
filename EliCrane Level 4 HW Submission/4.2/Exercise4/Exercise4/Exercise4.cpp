#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

#include "AdditionalFunctions.hpp"

using tCount = std::tuple<int, int>;

auto lPrint = [](std::vector<tCount>& v, std::string msg) {
	std::cout << msg << ":\n";

	for (auto elem : v) {
		std::cout << "(" << std::get<0>(elem) << "," << std::get<1>(elem) << ")" << std::endl;
	}
};

int main()
{
	std::vector<int> v1({ 1,5,7,8,8,9,10,9,5,5,5 });

	//a)
	std::vector<tCount> mCount;

	//Since there is no clean way to just iterate through uniques and a tuple is a logical method of
	//returning the values, will use for_each and find if to locate if the key for each unique element
	//already exists
	std::for_each(v1.begin(), v1.end(), [&](int t) {

		//find term with element in tuple
		auto it_count = std::find_if(mCount.begin(), mCount.end(), [&](tCount tCnt) {
			return std::get<0>(tCnt) == t; 
		});

		//If find_if cannot find element in tuple, add tuple with count value of 1
		if (it_count == mCount.end()) {
			mCount.push_back(std::make_tuple(t, 1));
		}
		//else increment count for iter value
		else {
			std::get<1>(*it_count)++;
		}
	});

	lPrint(mCount, "Count of terms in v1");

	//b)
	tSumStats<int> sumStats = calculateSumStats<int, std::vector<int>>(v1);
	std::cout << "The min element in v1 is:" << std::get<0>(sumStats) << std::endl;
	std::cout << "The max element in v1 is:" << std::get<1>(sumStats) << std::endl;
	std::cout << "The sum of elements in v1 is:" << std::get<2>(sumStats) << std::endl;
	std::cout << "The average of elements in v1 is:" << std::get<3>(sumStats) << std::endl; //Rounded

	//c)
	std::vector<int> S = { 1,2,-3,4,5,5,5,6 };
	auto it_f_S = std::find(S.begin(), S.end(), 5);
	std::cout << "The first instance of 5 is found at position: " << std::distance(S.begin(), it_f_S) << std::endl;
	using namespace std::placeholders;

	//Couldn't get bind2nd to work so used std::bind instead
	//auto bound2ndFunc = std::bind(Equals(), _1, 5);
	auto bound2ndFunc = std::bind(ModCompare(),_1, 2);
	it_f_S = std::find_if(S.begin(), S.end(), bound2ndFunc);
	std::cout << "The first instance of an even num is found at position using bind: " << std::distance(S.begin(), it_f_S) << std::endl;

	it_f_S = std::find_if(S.begin(), S.end(), [](int t) {return t % 2 == 0; });
	std::cout << "The first instance of an even num is found at position using lambda: " << std::distance(S.begin(), it_f_S) << std::endl;

	//d)
	//Define a vector with subrange
	std::vector<int> vSub({ 5,5,5 });
	//Change -3 to 3 to make 3,4,5 search more interesting
	std::vector<int> S2 = { 1,2,5,5,3,4,5,5,5,6,3,4,5 };

	//Find first element of sub with search then print next two elements
	auto res = search(S2.begin(), S2.end(), vSub.begin(), vSub.end());
	std::cout << "The subrange 5,5,5 can be found starting at position: " << std::distance(S2.begin(), res);
	std::cout << " and continues until position: " << std::distance(S2.begin(), res+2) << std::endl;

	vSub = { 3,4,5 };
	res = search(S2.begin(), S2.end(), vSub.begin(), vSub.end());
	std::cout << "The first instance of subrange 3,4,5 can be found starting at position: " << std::distance(S2.begin(), res) << std::endl;

	//perform search from right reversing vSub as well
	auto res_rev = search(S2.rbegin(), S2.rend(), vSub.rbegin(), vSub.rend());
	std::cout << "The last instance of subrange 3,4,5 can be found starting at position: ";
	//Subtract distance from right + amount of elements that you are searching for from the total size of S2 to get start position
	std::cout << S2.size() - (std::distance(S2.rbegin(), res_rev) + vSub.size()) << std::endl;

	//e)
	//use adjacent find
	S2 = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };
	res = std::adjacent_find(S2.begin(), S2.end());
	std::cout << "The first element to have a value equal to the next element is " << *res;
	std::cout << " located at position: " << std::distance(S2.begin(), res) << std::endl;

	//f)
	//determine if equal
	std::vector<int> S1 = { 1,2,5 };
	std::cout << "S1 equal to S2: " << std::boolalpha << std::equal(S1.begin(), S1.end(), S2.begin()) << std::endl;
	//S1 is equal to S2 if you use S1 to start since it will then only search for the first three elements
	
    return 0;
}

