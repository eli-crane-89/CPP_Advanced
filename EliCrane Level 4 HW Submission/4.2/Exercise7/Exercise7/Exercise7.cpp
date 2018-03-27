#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

//Forward declare
std::vector<int> ReturnPowerSet(const std::vector<int>&);
void heapPermutation(std::vector<int>&, int, const int, std::vector<int>&, int&);

auto lPrint = [](std::vector<int>& v, std::string msg, int lineSize) {
	std::cout << msg << ":\n";
	int lineCounter = 0;
	for (auto elem : v) {
		std::cout << elem << ", ";

		lineCounter++;
		if (lineCounter == lineSize) {
			std::cout << std::endl;
			lineCounter = 0;
		}
		
	}
};

int main()
{
	std::vector<int> S = { 1,-1,7,8,9,10 };
	lPrint(S, "S unalgorithimed", 3);

	//a)
	std::vector<int> SRes(S.size());
	std::reverse_copy(S.begin(), S.end(), SRes.begin());
	lPrint(SRes, "Result of S copied backwards", 3);

	//b)
	std::rotate(S.begin(), S.begin() + 3, S.end());
	lPrint(S, "Rotating S so 8 is the first term", 3);

	//c)
	S = { 1,-1,7,8,9,10 }; //Reinstantiating 
	auto vPower = ReturnPowerSet(S);
	lPrint(vPower, "A printing of all the power sets.", S.size());

	//d)
	//Move numbers to the front
	std::rotate(S.rbegin(), S.rbegin() + 3, S.rend());
	lPrint(S, "With 8,9,10 moved to front", S.size());

    return 0;
}

//used to calculating size of return vector
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}


//Generating permutation using Heap Algorithm
void heapPermutation(std::vector<int>& v, int size, const int n, std::vector<int>& vPower, int& permCounter)
{
	// if size becomes 1 then load permutation
	if (size == 1)
	{
		for (auto it = v.begin(); it != v.end(); it++) {
			vPower.push_back(*it);
		}
		//Keep track of permutations for exit condition
		permCounter++;
		
	}

	//If permCounter + 1 == n permutations then exit
	if (permCounter + 1 == factorial(n)) {
		return;
	};

	for (int i = 0; i<size; i++)
	{
		//Recursive call
		heapPermutation(v, size - 1, n, vPower, permCounter);
		// if size is odd, swap first and last
		// element
		if (size % 2 == 1) {
			std::swap(v[0], v[size - 1]);
		}

		// If size is even, swap ith and last
		// element
		else {
			std::swap(v[i], v[size - 1]);
		}
	}
}

//Heap permutation wrapper class
std::vector<int> ReturnPowerSet(const std::vector<int>& vConst) {
	//Copy over so original vector is unmodified
	std::vector<int> v = vConst;
	
	//Result vector
	std::vector<int> vPower;

	//Determine size for heapPermutation
	int n = v.size();

	//To keep track of perms
	int permCounter = 0;

	//Call heap permutation class
	heapPermutation(v, n, n, vPower, permCounter);

	return vPower;

}