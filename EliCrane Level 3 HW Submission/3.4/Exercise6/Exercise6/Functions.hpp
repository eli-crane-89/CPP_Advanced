#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

//Create global prime vector
std::vector<double> vPrime;

auto isPrime = [&](long num, std::vector<double>& vPrime) {

	//Exception for 2
	if (num % 2 == 0 && num > 2) {
		return false;
	}

	for (auto prime : vPrime) {
		//Check for previous prime divisibility, but not 1
		if (num % (int)prime == 0 && prime != 1) {
			return false;
		}
	}

	return true;
};

namespace funcs {

	double f1(double b) {
		std::cout << "f1 is running...\n";

		//Define return
		double val = 1;

		//Multiple and divide val by i until it hits b * 30000
		int i = 1;
		while (i < b * 30000) {
			//If i is even, multiply
			if (i % 2 == 0) {
				val *= i;
			}
			else {
				val /= i;
			}

			i++;
		}

		return val;
	}

	double f2(double n) {
		std::cout << "f2 is running...\n";

		long num = 1;

		//Clear vector for multiple runs
		vPrime.clear();

		//Creates a vector of first n prime numbers
		while (vPrime.size() < n) {
			if (isPrime(num, vPrime)) {
				vPrime.push_back(num);
			}

			num++;
		}

		//Return lastPrime
		return vPrime.back();
	}

	
	double f3(double lastPrime) {
		std::cout << "f3 is running...\n";

		//divide each vPrime by b
		for (auto iter = vPrime.begin(); iter != vPrime.end(); iter++) {
			(*iter) /= lastPrime;
		}

		//Return sum
		return std::accumulate(vPrime.begin(), vPrime.end(), 0);
	}

	double f4(double sumPrime, double lastPrime) {
		std::cout << "f4 is running...\n";

		//Divide sum by reductor and return
		return sumPrime / lastPrime;
	}
}

#endif // !FUNCTIONS_HPP