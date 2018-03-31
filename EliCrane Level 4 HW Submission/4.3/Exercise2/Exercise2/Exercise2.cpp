#include <map>
#include <string>
#include <iostream>
#include <random>
#include <cmath>


//a)
template <typename T, typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng eng, int NTrials, const std::string& s)
{
	std::map<T, int> mRes;
	int nSpaceDec = 0; //for printing

	for (int i = 0; i < NTrials; i++) {
		T numDist = d(eng);

		//If not exists insert num with count of 1
		if (mRes.count(numDist) == 0) {
			mRes.insert(std::pair<T, int>(numDist, 1));
		}
		//else increment count
		else { 
			mRes[numDist]++;
		}
	}

	std::cout << "----" << s << "----\n";

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
		for (int h = 0; h < 4-nSpaceDec; h++){
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

	std::cout << std::endl << std::endl;
}

int main()
{
	std::mt19937_64 eng_mt64;
	

	//b)
	std::uniform_int_distribution<> dist_real(0, 100);
	GenerateRandomNumbers<int>(dist_real, eng_mt64, 1000, "Real Distribution");

	std::geometric_distribution<int> dist_geo(0.3);
	GenerateRandomNumbers<int>(dist_geo, eng_mt64, 200, "Geometric Distribution");

	std::poisson_distribution<int> dist_pois(4.1);
	GenerateRandomNumbers<int>(dist_pois, eng_mt64, 200, "Poisson Distribution");

	//c)
	//Yes, the distributions make sense. The uniform distribution seems to be
	//pretty equally disperesed across the 100 numbers. The geometric distribution
	//also makes sense since it has a probability of .3. 71/200 is slightly higher
	//than the true expected value of .6. The gradual decline of occurences of numbers
	//as they get higher is also expected. The poisson distribution also looks correct
	//since the distribution falls around 4.1, we would expect to usually get 4, but
	//5 and 3 should also be frequent. The right skew is normal since it is bound at 0.

    return 0;
}

