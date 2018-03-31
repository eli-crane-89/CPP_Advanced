#include <vector>
#include <random>
#include <iostream>
#include <cmath>

//Global variables
int nVars = 1000;

auto lPrint = [](std::vector<int>& v) {
	for (auto i = 0; i < v.size(); i++) {
		std::cout << v[i] << ",";

		//Print 20 numbers per row
		if (i > 0 && i % 20 == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
};


int randFunc(int seed) {
	std::srand(seed); //To change seed
	return std::rand() % seed; //use modulo to control range
}

int mt19937Func(int seed) {
	std::mt19937 eng(seed);
	return std::abs(static_cast<int>(eng())) % seed; //use static cast and abs value with modulo to control range
}

int dfrFunc(int seed) {
	std::default_random_engine eng(seed);
	return std::abs(static_cast<int>(eng())) % seed; //use static cast and abs value with modulo to control range
}

int lgeFunc(int seed) {
	std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> eng(seed);
	return std::abs(static_cast<int>(eng())) % seed; //use static cast and abs value with modulo to control range
}

//User defined
auto lUDRNG = [](int i) {
	std::random_device rd;
	return std::abs(static_cast<int>(rd())) % i;
};

auto lUDRNG2 = []() {
	std::random_device rd;
	return std::mt19937(rd());
};

int main()
{
	std::vector<int> vInt;
	std::random_device rd;

	for (int i = 0; i < 100; i++) {
		vInt.push_back(i);
	}

	//a)
	std::cout << "a)\n";

	//mt19937
	std::random_shuffle(vInt.begin(), vInt.end(), randFunc);
	lPrint(vInt);

	std::random_shuffle(vInt.begin(), vInt.end(), mt19937Func);
	lPrint(vInt);

	std::random_shuffle(vInt.begin(), vInt.end(), dfrFunc);
	lPrint(vInt);
	
	std::random_shuffle(vInt.begin(), vInt.end(), lgeFunc);
	lPrint(vInt);

	std::random_shuffle(vInt.begin(), vInt.end(), lUDRNG);
	lPrint(vInt);

	//b)
	std::cout << "\n\nb)\n\n";
	//std::shuffle(vInt.begin(), vInt.end(), std::rand()); //cannot get to work with rand
	//lPrint(vInt);

	std::mt19937 eng_mt(rd());
	std::shuffle(vInt.begin(), vInt.end(), eng_mt);
	lPrint(vInt);

	std::default_random_engine eng_dre(rd());
	std::shuffle(vInt.begin(), vInt.end(), eng_dre);
	lPrint(vInt);

	std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> eng_lge(rd());
	std::shuffle(vInt.begin(), vInt.end(), eng_lge);
	lPrint(vInt);

	std::shuffle(vInt.begin(), vInt.end(), lUDRNG2());
	lPrint(vInt);

	

    return 0;
}

