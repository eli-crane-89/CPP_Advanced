#include <random>
#include <iostream>

#include "RandomFunction.hpp"

template<typename T>
void printVec(std::vector<T> v) {

	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Generate uniform random variates in interval [A, B]
	double A = 0.0;
	double B = 1.0;
	std::uniform_real_distribution<double> dist(A, B);
	int nTrials = 30;

	//a)
	// Choose the engine
	std::default_random_engine eng;
	std::minstd_rand lce_eng(1729);
	std::mt19937 mt_eng(1729);
	std::mt19937_64 mt64_eng(1729);

	std::cout << "uniform real distribution:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << dist(eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "linear congruential engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << dist(lce_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << dist(mt_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt64 engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << dist(mt64_eng) << ", ";
	}
	std::cout << "end\n\n";

	//b)
	std::cout << "Bernouilli:\n\n" << std::endl;

	std::bernoulli_distribution bern_dist(.5);
	std::cout << "uniform real distribution:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "linear congruential engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(lce_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(mt_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt64 engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(mt64_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "Normal:\n\n" << std::endl;

	std::normal_distribution<double> nm_dist(5.0, 2.0);
	std::cout << "uniform real distribution:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << nm_dist(eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "linear congruential engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << nm_dist(lce_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(mt_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt64 engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << bern_dist(mt64_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "Chi-Squared:\n\n" << std::endl;

	std::chi_squared_distribution<double> chi_dist(3.0);
	std::cout << "uniform real distribution:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << chi_dist(eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "linear congruential engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << chi_dist(lce_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << chi_dist(mt_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt64 engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << chi_dist(mt64_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "cauchy_distribution:\n\n" << std::endl;

	std::cauchy_distribution<double> cauchy_dist(5.0, 1.0);
	std::cout << "uniform real distribution:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << cauchy_dist(eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "linear congruential engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << cauchy_dist(lce_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << cauchy_dist(mt_eng) << ", ";
	}
	std::cout << "end\n\n";

	std::cout << "mt64 engine:\n";

	// Produce a number of uniform variates
	for (int i = 1; i <= nTrials; ++i)
	{
		std::cout << cauchy_dist(mt64_eng) << ", ";
	}
	std::cout << "end\n\n";

	
	//c)
	std::cout << "\nGeneric Function:\n\n";

	std::cout << "cauchy:\n";
	//Bind to function
	printVec<double>(GenericNumberGeneration<double>(cauchy_dist, mt64_eng, 100));
			
	std::cout << "Bernouill:\n";
	//Bind to function
	printVec<double>(GenericNumberGeneration<double>(bern_dist,mt_eng, 10 ));

	std::cout << "Normal:\n";
	//Bind to function
	printVec<double>(GenericNumberGeneration<double>(nm_dist, lce_eng, 10));

	std::cout << "Chi:\n";
	//Bind to function
	printVec<double>(GenericNumberGeneration<double>(chi_dist, mt64_eng, 10));

    return 0;
}

