#include <iostream>
#include <boost\functional\hash.hpp>
#include <string>
#include <numeric>

template <typename T>
std::size_t boostHashFunction(const T& key) {
	boost::hash<T> hasher;
	return hasher(key);
}

template <typename T>
std::size_t c11HashFunction(const T& key) {
	std::hash<T> hasher;
	return hasher(key);
}


int main()
{
	//b)
	int i1 = 3, i2 = 6;
	std::size_t bhs_i1 = boostHashFunction(i1);
	std::cout << "bhs_i1: " << bhs_i1 << std::endl;
	std::size_t bhs_i2 = boostHashFunction(i2);
	std::cout << "bhs_i2: " << bhs_i2 << std::endl;
	std::size_t c11_i1 = c11HashFunction(i1);
	std::cout << "c11_i1: " << c11_i1 << std::endl;
	std::size_t c11_i2 = c11HashFunction(i2);
	std::cout << "c11_i2: " << c11_i2 << std::endl;
	std::cout << std::endl;

	std::string s1 = "Hello", s2 = "Goodbye";
	std::size_t bhs_s1 = boostHashFunction(s1);
	std::cout << "bhs_s1: " << bhs_s1 << std::endl;
	std::size_t bhs_s2 = boostHashFunction(s2);
	std::cout << "bhs_s2: " << bhs_s2 << std::endl;
	std::size_t c11_s1 = c11HashFunction(s1);
	std::cout << "c11_s1: " << c11_s1 << std::endl;
	std::size_t c11_s2 =c11HashFunction(s2);
	std::cout << "c11_s2: " << c11_s2 << std::endl;
	std::cout << std::endl;

	std::unique_ptr<int> u_i1 = std::make_unique<int>(3);
	std::shared_ptr<int> s_i2 = std::make_shared<int>(500);
	std::shared_ptr<int> s_i3 = std::make_shared<int>(750);
	std::size_t bhs_u_i1 = boostHashFunction(u_i1);
	std::cout << "bhs_u_i1: " << bhs_u_i1 << std::endl;
	std::size_t bhs_s_i2 = boostHashFunction(s_i2);
	std::cout << "bhs_s_i2: " <<s_i2 << std::endl;
	std::size_t bhs_s_i3 = boostHashFunction(s_i3);
	std::cout << "bhs_s_i3: " << s_i3 << std::endl;
	std::size_t c11_u_i1 = c11HashFunction(u_i1);
	std::cout << "c11_u_i1: " << c11_u_i1 << std::endl;
	std::size_t c11_s_i2 = c11HashFunction(s_i2);
	std::cout << "c11_s_i2: " << c11_s_i2 << std::endl;
	std::cout << std::endl;

	long l = std::numeric_limits<long>::max();
	std::cout << "The numeric limit is: " << l << std::endl;
	std::size_t bhs_l = boostHashFunction(l);
	std::cout << "bhs_l: " << bhs_l << std::endl;
	std::size_t c11_l = c11HashFunction(l);
	std::cout << "c11_l: " << c11_l << std::endl;
	std::cout << std::endl;
	
	//It is clear that boost::hash and std::hash use different hashing functions
	//For example, bhs uses the integer to hash ints and longs, while std::hash
	//used a more elabaroate function. This is also true for the numeric limit
	//where the boost::hash equals the real numeric limit for long.
	//I was interested in the hash by boost for the shared pointer so i created a 
	//third shared pointer to see what the results would. It looks like boost uses
	//some kind of hex code for the shared pointers.
	//Also, when rerunning the program the hashes for all the types except the 
	//pointers remain the same between the two functions. Clearly hashing pointers
	//takes into account the memory of the pointer.

	//c)
	std::size_t bhs_h1 = boostHashFunction(s1);
	std::size_t bhs_h2 = boostHashFunction(s2);

	//This function bit shits bhs_h2 1 to the left
	//xor then does a bit comparison
	std::cout << "h1^(h2<<1): " << (bhs_h1^(bhs_h2 << 1)) << std::endl;



    return 0;
}

