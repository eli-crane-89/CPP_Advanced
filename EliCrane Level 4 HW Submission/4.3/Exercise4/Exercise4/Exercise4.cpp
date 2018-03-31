#include <random>
#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
	//a)
	std::random_device rd;
	std::mt19937_64 eng_mt64(rd());
	
	//b)
	std::uniform_real_distribution<double> dist_urd1(-1.0, 1.0);
	std::uniform_real_distribution<double> dist_urd2(-1.0, 1.0);

	//c)
	double x, y;
	long counter = 0, nTrials = 500000000;

	for (int i = 0; i < nTrials; i++) {
		x = dist_urd1(eng_mt64);
		y = dist_urd2(eng_mt64);

		if (std::sqrt(std::pow(x, 2) + std::pow(y, 2)) > 1) {
			counter++;
		}

	}

	//d)
	std::cout << "After " << nTrials << " trials, Pi is equal to: ";
	std::cout << std::setprecision(8) << (double)((nTrials - counter) * 4) / (double)nTrials << std::endl;
	
	//closest I could get was 3.141519 after 500,000,000 trials

    return 0;
}

