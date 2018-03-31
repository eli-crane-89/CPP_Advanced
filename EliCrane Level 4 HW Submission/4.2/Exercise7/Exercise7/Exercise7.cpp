#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

//Forward declare
std::vector<int> GeneratePermutations(const std::vector<int>&);



auto lPrint = [](std::vector<int>& v, std::string msg, int lineSize = 999) {

	if (lineSize == 999) {
		lineSize = v.size();
	}

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
	auto vPower = GeneratePermutations(S);
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



bool nextPerm(std::vector<int>::iterator iterFirst, std::vector<int>::iterator iterLast){
	//Set iterCur to last term iterator
	if (iterFirst == iterLast)
		return false;
	auto iterCur = iterFirst;
	++iterCur;
	if (iterCur == iterLast)
		return false;
	iterCur = iterLast;
	--iterCur;

	while (true) {
		auto iterCur2 = iterCur;
		--iterCur;

		if (*iterCur < *iterCur2) {
			auto iterCur3 = iterLast;
			while (!(*iterCur < *--iterCur3)) {
			}
			std::iter_swap(iterCur, iterCur3);
			std::reverse(iterCur2, iterLast);
			return true;
		}
		if (iterCur == iterFirst) {
			std::reverse(iterFirst, iterLast);
			return false;
		}
	}
}

//Generate Permutation
std::vector<int> GeneratePermutations(const std::vector<int>& v) {
	auto vWork = v;
	//Sort vWork for nextPerm algorithm to work
	std::sort(vWork.begin(), vWork.end());

	const auto size = vWork.size();
	const auto sizeFact = factorial(size);

	//Create result vector
	std::vector<int> vResults(sizeFact * size);
	int incCounter = 0;
	
	//For exit condition
	int permCounter = 0;

	//Insert first results
	do {
		for (int i = 0; i < size; i++) {
			vResults[i + permCounter*size] = vWork[i];
		}
		permCounter++;
	} while (permCounter < factorial(size) && nextPerm(vWork.begin(), vWork.end())); 
		
	return vResults;
}