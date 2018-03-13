#include <bitset>
#include <iostream>
#include <string>


int main()
{

	//a) create two bitsets
	std::bitset<5> bs1;
	std::bitset<5> bs2;

	//b) toggle on bits
	bs1.set();
	bs2.set();

	//c) 
	//Xor
	std::cout <<  (bs1 ^= bs2) << std::endl;
	//And
	std::cout << (bs1 &= bs2) << std::endl;
	//Or
	std::cout << (bs1 |= bs2) << std::endl;

	//d)
	//Left shift
	std::cout << (bs1 << 1) << std::endl;

	//Right shift
	std::cout << (bs1 >> 1) << std::endl;

	//e)
	//hash
	std::hash<std::bitset<5>> hash_fn;
	size_t h1 = hash_fn(bs1);
	std::cout << h1 << std::endl;
	size_t h2 = hash_fn(bs2);
	std::cout << h2 << std::endl;


    return 0;
}

