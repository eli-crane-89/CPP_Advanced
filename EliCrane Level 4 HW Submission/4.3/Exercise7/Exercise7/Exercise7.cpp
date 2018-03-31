#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <map>



//Map accumulator function
auto lMapAdd = [](int value, const std::map<int, int>::value_type& mOutComes) {
	return value + mOutComes.second; 
};

double chiSquared(std::map<int, int> mOutComes) {
	double chi2 = 0;

	//Assume equal prob for all event
	double pi = 1.0 / (double)mOutComes.size();

	//Expected number of outcomes for each event
	int N = std::accumulate(mOutComes.begin(), mOutComes.end(), 0, lMapAdd);
	double exp = (double)N * pi;
	
	//Iterate through outcomes
	double eq1, eq2;
	for (auto outcome : mOutComes) {
		
		eq1 = std::pow((outcome.second - exp),2);
		eq2 = eq1 / exp;
		
		//Add to chi2
		chi2 += eq2;
	}

	return chi2;
}

//Number in range roller, constant seed for constant results
std::map<int,int> rangeRoller(int nTrials, int seed, int rangeMin, int rangeMax) {
	//Simulate dice rolls
	std::mt19937 eng_mt(seed);
	std::uniform_int_distribution<int> dist_uni(rangeMin, rangeMax);

	//Create map of outcomes
	std::map<int, int> mOutComes;
	for (int i = 1; i <= 6; i++) {
		mOutComes.insert(std::pair<int, int>(i, 0));
	}

	//Perform trials
	for (int i = 0; i < nTrials; i++) {
		int val = dist_uni(eng_mt);
		mOutComes[val]++;
	}

	return mOutComes;
}


//Histogram
auto lHist = [](const std::map<int, int>& mRes) {
	int nSpaceDec = 0;

	for (auto iter = mRes.begin(); iter != mRes.end(); iter++) {

		//Output values
		std::cout << iter->first;

		//Decrement spaces based on power of 10 for printing
		//0 is special case
		if (iter->first != 0) {
			while (std::pow(10, nSpaceDec) - 1 < iter->first) {
				nSpaceDec++;
			}
		}
		else {
			nSpaceDec++;
		}

		//Create spaces
		for (int h = 0; h < 4 - nSpaceDec; h++) {
			std::cout << " ";
		}

		//Print divider
		std::cout << " |";

		//Print * of count
		for (int i = 0; i < iter->second; i++) {
			std::cout << "*";
		}
		std::cout << "(" << iter->second << ")";
		std::cout << std::endl;
	}

	std::cout << std::endl;
};

int main()
{
	//b)
	std::vector<int> vTrials = { 10 };

	std::map<int, int> mOutComes;

	for (int i = 0; i < 50; i++) {

		//Simulate dice roll with range 1-6;
		mOutComes = rangeRoller(50, i, 1, 6);
		std::cout << "Trial no: " << i << std::endl;
		lHist(mOutComes);
		std::cout << "Chi-Squared: " << chiSquared(mOutComes) << std::endl << std::endl;
	}

	//When running 50 different trials with n of 50, the histograms created mostly do not have a high enough chi2
	//statistic to reject the null hypothesis. This is to be expected since I was generating a random sample.
	//However, certain trials, by chance, have distributions that look less equal, such as trial 48, that had
	//14 5s, instead of the expectecd 8-9 5s. This gives it a higher chi-squared statistic, increasing the chance
	//that the sample was not random

	//c)
	std::map<int, int> mOutComes2 = rangeRoller(1000, 5, 0, 50);
	std::cout << "Range 0 - 50, 1000 trials:\n";
	lHist(mOutComes2);
	std::cout << "Chi-Squared: " << chiSquared(mOutComes2) << std::endl << std::endl;
	
	//The expected frequency is 1000/51 or approx 20 per integer
	//the chi squared statistic of 37.136 with 949 degrees of freedom means you can reject 
	//the null hypothesis at the 10% level, which is obviously far below acceptable
	//statistical significance.

    return 0;
}

