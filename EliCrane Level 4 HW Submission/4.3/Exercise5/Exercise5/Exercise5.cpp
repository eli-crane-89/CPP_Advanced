#include <iostream>
#include <random>

#include "Independent_Bits_Engine.hpp"

int main()
{
	//a)
	std::random_device rd;
	independent_bits_engine<std::mt19937, 4, unsigned int> ibe(rd());
	std::cout << ibe;

	//b)
	TestIBE<2>(1000);

	//Using i as the seed, very close to 50% of all bits are 1

	//c)
	TestIBE<4>(1000);
	TestIBE<8>(1000);
	TestIBE<16>(1000);
	
	//Yes, all of the bitset counts are very close to 50%



    return 0;
}

